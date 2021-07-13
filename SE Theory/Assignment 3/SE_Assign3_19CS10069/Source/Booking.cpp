/*
Name : Abhinandan De
Roll No: 19CS10069
*/

#include<iostream>
using namespace std;
#include "Booking.h"
#include <cmath>

// setting the static members

double Booking :: sBaseFarePerKM = 0.5;
int Booking :: sBookingPNRSerial = 1;
double Booking :: sACSurcharge = 50;
double Booking :: sLuxuryTaxPercent = 25;
vector<Booking*> Booking :: sBookings = {};

Booking :: Booking(const Station& from, const Station& to, const Date& d, const BookingClass& bClass): 
    from_(from), to_(to), date_(d), bClass_(bClass), pnr_(sBookingPNRSerial++) { 
        bookingMessage_ = "BOOKING SUCCEEDED";
        ComputeFare();
        sBookings.push_back(this);
    }

Booking :: ~Booking() { }

void Booking :: ComputeFare() {
    fare_ = from_.GetDistance(to_)*sBaseFarePerKM*(bClass_.GetLoadFactor()) + ((bClass_.IsAC()) ? sACSurcharge : 0.0);
    fare_ = ((bClass_.IsLuxury()) ? ((sLuxuryTaxPercent+100.00)*fare_)/100.00 : fare_);
    fare_ += 0.5;       // for rounding off
}

void Booking :: ChangeAcSurcharge(double newSurcharge) {
    Booking :: sACSurcharge = newSurcharge;
}

void Booking :: ChangeBaseFare(double newBaseFare) {
    Booking :: sBaseFarePerKM = newBaseFare;
}

void Booking :: ChangeLuxuryTaxPercent(double newLuxuryTaxPercent) {
    Booking :: sLuxuryTaxPercent = newLuxuryTaxPercent;
}

void Booking:: UnitTest() {

    Booking b(Station("Delhi"), Station("Kolkata"), Date(15, 12, 2021), ACFirstClass::Type());

    cout << b << '\n';                  // testing the stream operator

    if(static_cast<int>(b.fare_) != 2823) 
        cout << "Error in computing fare!\n";
    
    if(b.from_.GetName() != "Delhi" || b.to_.GetName() != "Kolkata") 
        cout << "Error in getting the source and destinations\n";
    
    if(b.date_ != Date(15, 12, 2021)) 
        cout << "Wrong date of journey\n";

    ChangeAcSurcharge(60.00);             // testing the static member functions

    ChangeBaseFare(1.00);

    ChangeLuxuryTaxPercent(27.00);

    const double error = 1e-6;

    if(abs(sACSurcharge - 60.00) >= error) {
        cout << "Error in changing AC surcharge\n";
    }
    if(abs(sBaseFarePerKM - 1.00) >= error) {
        cout << "Error in changing Base fare\n";
    }
    if(abs(sLuxuryTaxPercent - 27.00) >= error) {
        cout << "Error in changing luxury tax percent\n";
    }

    // SAME booking after changing the different fares

    Booking b1(Station("Delhi"), Station("Kolkata"), Date(17, 11, 2022), ACFirstClass::Type());         

    cout << b1 << '\n';

    if(static_cast<int>(b1.fare_) != 5685) {
        cout << "Error in computing fare!\n";
    }

    // Source and destination stations have already been checked!
}

ostream& operator<< (ostream& os, const Booking& b) {
    os << b.bookingMessage_ << ":\n";
    os << "PNR Number = " << b.pnr_ << '\n';
    os << "From station: " << b.from_;
    os << "To station: " << b.to_;
    os << "Travel Date: " << b.date_;
    os << b.bClass_;
    os << "Fare: " << static_cast<int>(b.fare_) << "\n\n";
    
    return os;
}
