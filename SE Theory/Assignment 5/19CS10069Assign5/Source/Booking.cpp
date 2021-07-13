/*
Name : Abhinandan De
Roll No: 19CS10069
*/

#include<iostream>
using namespace std;

#include "Booking.h"
#include "BookingCategory.h"
#include<cmath>


// #define __DEBUG

// setting the static members 

double Booking :: sBaseFarePerKM = 0.5;
int Booking :: sBookingPNRSerial = 1;
double Booking :: sLuxuryTaxPercent = 25;
vector<Booking*> Booking :: sBookings = {};

Booking :: Booking(const Station& from, const Station& to, const Date& dob, const Date& dor, const BookingClass& bClass, const Passenger& p, const BookingCategory& bCategory): 
    fromStation_(from), toStation_(to), dateOfBooking_(dob), bookingClass_(bClass), pnr_(sBookingPNRSerial++), passenger_(p) , 
    bookingCategory_(bCategory), dateOfReservation_(dor)  { 
    bookingMessage_ = "BOOKING SUCCEEDED";
    sBookings.push_back(this);
}

Booking :: ~Booking() { 
    
}

const Booking* Booking :: ReserveBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking,         
                                const BookingClass& bClass, const BookingCategory& bCategory, const Passenger& p, 
                                const Date& dateOfReservation) {

    try {
        Validate(fromStation, toStation, dateOfBooking, bClass, bCategory, p, dateOfReservation);   // date of booking is checked!
    }
    catch(exception& e) {
        throw;
    }

    #ifdef __DEBUG
        cout << "Successfully validated Dates\n";
    #endif
    
    try {
        const Booking* myBooking = bCategory.createBooking(fromStation, toStation, dateOfBooking, dateOfReservation, p, bClass);
        double d = Railways :: GetDistance(fromStation, toStation);     // to check if route is available or not or if source and destination stations are same!
        
        #ifdef __DEBUG
            cout << "Successfully created Booking\n";
        #endif
        return myBooking;

    } catch(exception& e) {
        throw;              // just rethrow!
    }
}

void Booking :: Validate(const Station& from, const Station& to, const Date& dob, const BookingClass& bclass, const BookingCategory& bCategory, const Passenger& p, const Date& dor) {
    #ifdef __DEBUG
        cout << "Initiating validation Process\n";
    #endif

    if(dob > dor)
        throw Bad_Date_Of_Booking();            // date of booking after reservation
    
    #ifdef __DEBUG
        cout << "Date of Booking Is Fine!\n";
    #endif

    if(Date :: computeAge(dob, dor) >= 1)           // one year from booking date
        throw Bad_Date_Of_Booking();
    
    #ifdef __DEBUG
        cout << "Age Calculated!\n";
    #endif

    if(p.getDateOfBirth() > dor)                // born after reservation!
        throw Bad_Age_Of_Passenger();
        
    #ifdef __DEBUG
        cout << "Passenger is born before reservation date!\n";
    #endif

    #ifdef __DEBUG
        cout << "Successfully validated Booking\n";
    #endif
}

void Booking :: ChangeBaseFare(double newBaseFare) {
    Booking :: sBaseFarePerKM = newBaseFare;
}

double Booking :: GetFare() const {
    return fare_;
}

void Booking :: ChangeLuxuryTaxPercent(double newLuxuryTaxPercent) {
    Booking :: sLuxuryTaxPercent = newLuxuryTaxPercent;
}

void Booking:: UnitTest() {
    Station s1 = Station :: createStation("Kolkata");
    Station s2 = Station :: createStation("Delhi");
    const Date& d1 = Date :: createDate(16, 3, 2001);
    const Passenger p1 = Passenger :: createPassenger("Abhinandan", "", "De", "134236789345", d1, Gender :: Male :: Type(), "8279728914");
    const Date& d2 = Date :: createDate(8, 4, 2021);
    const Date& d3 = Date :: createDate(9, 8, 2021);
    const Date& d4 = Date :: createDate(12, 3, 2001);
    const Date& d5 = Date :: createDate(3, 8, 2022);
    const Date& d6 = Date :: createDate(15, 3, 2001);

    try {
        const Booking* b1 = Booking :: ReserveBooking(s1, s2, d2, BookingClass :: ACFirstClass :: Type(), GeneralCategory :: Type(), p1, d3);       // okay
        cout << "Booking Successfully done\n";
    } catch(exception& e) {
        cout << "Error!\n";
        cout << e.what() << '\n';
    }

    try {
        const Booking* b2 = Booking :: ReserveBooking(s1, s2, d3, BookingClass :: ACFirstClass :: Type(), GeneralCategory :: Type(), p1, d2);       // date of booking> reservation
    } catch(exception& e) {
        cout << "**Exception Caught!**\n";
        cout << e.what() << '\n';
    }

    try {
        const Booking* b3 = Booking :: ReserveBooking(s1, s2, d4, BookingClass :: ACFirstClass :: Type(), GeneralCategory :: Type(), p1, d6);       // not yet born!
    } catch(exception& e) {
        cout << "**Exception Caught!**\n";
        cout << e.what() << '\n';
    }

    try {
        const Booking* b4 = Booking :: ReserveBooking(s1, s2, d2, BookingClass :: ACFirstClass :: Type(), GeneralCategory :: Type(), p1, d5);           //  > one year from booking date
    } catch(exception& e) {
        cout << "**Exception Caught!**\n";
        cout << e.what() << '\n';
    }

    cout << "***TESTING FOR BOOKING IS DONE****\n";
}

ostream& operator<< (ostream& os, const Booking& b) {
    os << "\n\n" << b.bookingMessage_ << ":\n";
    os << "PNR Number        : " << b.pnr_ << '\n';
    os << "From station      : " << b.fromStation_;
    os << "To station        : " << b.toStation_;
    os << "Travel Date       : " << b.dateOfReservation_;
    os << "Booking Class     : " << b.bookingClass_;
    os << "Booking Category  : " << b.bookingCategory_;
    os << "Fare              : " << static_cast<int>(b.fare_) << "\n\n";
    
    os << "Passenger details\n";
    os << b.passenger_ << "\n";

    return os;
}

GeneralBooking :: GeneralBooking(const Station& fromStation, const Station& toStation, 
    const Date& dateOfBooking, const Date& dateOfReservation, const Passenger& p, const BookingClass& b):
    Booking(fromStation, toStation, dateOfBooking, dateOfReservation, b, p, GeneralCategory :: Type()) {
        ComputeFare();
}

GeneralBooking :: ~GeneralBooking() {

}

void GeneralBooking :: ComputeFare() {
    fare_ = (Railways::GetDistance(fromStation_, toStation_))*(Booking :: sBaseFarePerKM);
    fare_ = fare_*(bookingClass_.GetLoadFactor()) + bookingClass_.GetReservationCharges();
    fare_ += 0.5;
}

void GeneralBooking:: UnitTest() {
    Station s1 = Station :: createStation("Kolkata");
    Station s2 = Station :: createStation("Delhi");
    const Date& d1 = Date :: createDate(16, 3, 2001);
    const Passenger p1 = Passenger :: createPassenger("Abhinandan", "", "De", "134236789345", d1, Gender :: Male :: Type(), "8279728914");
    const Date& d2 = Date :: createDate(8, 4, 2021);
    const Date& d3 = Date :: createDate(9, 8, 2021);

    const Booking* b1 = Booking :: ReserveBooking(s1, s2, d2, BookingClass :: ACFirstClass :: Type(), GeneralCategory :: Type(), p1, d3);
    if(abs(b1->GetFare() -4844.5) >= 1e-3)
        cout << "Error in compute fare\n";

    cout << "***TESTING FOR GENERAL BOOKING IS DONE****\n";
}

LadiesBooking :: LadiesBooking(const Station& fromStation, const Station& toStation, 
    const Date& dateOfBooking, const Date& dateOfReservation, const Passenger& p, const BookingClass& b):
    Booking(fromStation, toStation, dateOfBooking, dateOfReservation, b, p, LadiesCategory :: Type()) {
        ComputeFare();
}

LadiesBooking :: ~LadiesBooking() {

}

void LadiesBooking :: ComputeFare() {
    fare_ = (Railways::GetDistance(fromStation_, toStation_))*(Booking :: sBaseFarePerKM);
    fare_ = fare_*(bookingClass_.GetLoadFactor()) + bookingClass_.GetReservationCharges();
    fare_ += 0.5;
}

void LadiesBooking:: UnitTest() {
    Station s1 = Station :: createStation("Kolkata");
    Station s2 = Station :: createStation("Delhi");
    const Date& d1 = Date :: createDate(16, 3, 2001);
    const Passenger p1 = Passenger :: createPassenger("Ankita", "", "De", "134236789345", d1, Gender :: Female :: Type(), "8279728914");
    const Date& d2 = Date :: createDate(8, 4, 2021);
    const Date& d3 = Date :: createDate(9, 8, 2021);

    const Booking* b1 = Booking :: ReserveBooking(s1, s2, d2, BookingClass :: ACFirstClass :: Type(), LadiesCategory :: Type(), p1, d3);
    if(abs(b1->GetFare() -4844.5) >= 1e-3)
        cout << "Error in compute fare\n";

    cout << "***TESTING FOR LADIES BOOKING IS DONE****\n";
}

SeniorCitizensBooking :: SeniorCitizensBooking(const Station& fromStation, const Station& toStation, 
    const Date& dateOfBooking, const Date& dateOfReservation, const Passenger& p, const BookingClass& b):
    Booking(fromStation, toStation, dateOfBooking, dateOfReservation, b, p, SeniorCitizenCategory :: Type()) {
        ComputeFare();
}

SeniorCitizensBooking :: ~SeniorCitizensBooking() {
    
}

void SeniorCitizensBooking :: ComputeFare(){
    fare_ = (Railways::GetDistance(fromStation_, toStation_))*(Booking :: sBaseFarePerKM);
    fare_ = fare_*(bookingClass_.GetLoadFactor());
    fare_ = fare_*(1 - (SeniorCitizenConcession :: Type()).GetConcession(passenger_));
    fare_ += bookingClass_.GetReservationCharges();
    fare_ += 0.5;
}

void SeniorCitizensBooking:: UnitTest() {
    Station s1 = Station :: createStation("Kolkata");
    Station s2 = Station :: createStation("Delhi");
    const Date& d1 = Date :: createDate(16, 3, 1951);
    const Passenger p1 = Passenger :: createPassenger("Abhinandan", "", "De", "134236789345", d1, Gender :: Male :: Type(), "8279728914");
    const Date& d2 = Date :: createDate(8, 4, 2021);
    const Date& d3 = Date :: createDate(9, 8, 2021);

    const Booking* b1 = Booking :: ReserveBooking(s1, s2, d2, BookingClass :: ACFirstClass :: Type(), SeniorCitizenCategory :: Type(), p1, d3);
    if(abs(b1->GetFare() -2930.9) >= 1e-3)
        cout << "Error in compute fare\n";

    cout << "***TESTING FOR Senior Citizens BOOKING IS DONE****\n";
}

DivyaangBooking :: DivyaangBooking(const Station& fromStation, const Station& toStation, 
    const Date& dateOfBooking, const Date& dateOfReservation, const Passenger& p, const BookingClass& b):
    Booking(fromStation, toStation, dateOfBooking, dateOfReservation, b, p, DivyaangCategory :: Type()) {
        ComputeFare();
}

DivyaangBooking :: ~DivyaangBooking() {

}

void DivyaangBooking :: ComputeFare(){
    fare_ = (Railways::GetDistance(fromStation_, toStation_))*(Booking :: sBaseFarePerKM);
    fare_ = fare_*(bookingClass_.GetLoadFactor());                                              // change this! GetConcessions!!!
    int check = passenger_.getDisabilityIndex();
    double val = 0.0;
                                                    
    switch(check) {
        case 1 :val = (DivyaangConcession :: Type()).GetConcession(bookingClass_, Divyaang :: BlindDivyaang :: Type());
                break;
        case 2 :val = (DivyaangConcession :: Type()).GetConcession(bookingClass_, Divyaang :: OrthopaedicallyHandicappedDivyaang :: Type());
                break;
        case 3 :val = (DivyaangConcession :: Type()).GetConcession(bookingClass_, Divyaang :: CancerPatientDivyaang :: Type());
                break;
        case 4 :val = (DivyaangConcession :: Type()).GetConcession(bookingClass_, Divyaang :: TBPatientDivyaang :: Type());
                break;
        default:val = 0.0;
    }

    fare_ *= (1-val);
    fare_ += bookingClass_.GetReservationCharges();
    fare_ += 0.5;
}

TatkalBooking :: TatkalBooking(const Station& fromStation, const Station& toStation, 
    const Date& dateOfBooking, const Date& dateOfReservation, const Passenger& p, const BookingClass& b):
    Booking(fromStation, toStation, dateOfBooking, dateOfReservation, b, p, TatkalCategory :: Type()) {
        ComputeFare();
}

TatkalBooking :: ~TatkalBooking() {
    
}

void TatkalBooking :: ComputeFare(){
    fare_ = (Railways::GetDistance(fromStation_, toStation_))*(Booking :: sBaseFarePerKM);
    fare_ = fare_*(bookingClass_.GetLoadFactor());
    if(Railways :: GetDistance(fromStation_, toStation_) >= bookingClass_.GetMinDistanceForCharge()) {
        double check = Railways :: GetDistance(fromStation_, toStation_);
        check *= bookingClass_.GetPremiumTatkalLoad();
        check = max(bookingClass_.GetMinTatkalCharges(), check);
        check = min(bookingClass_.GetMaxTatkalCharges(), check);
        fare_ += check;
    }
    fare_ += bookingClass_.GetReservationCharges();
    fare_ += 0.5;
}

void TatkalBooking:: UnitTest() {
    Station s1 = Station :: createStation("Kolkata");
    Station s2 = Station :: createStation("Delhi");
    const Date& d1 = Date :: createDate(16, 3, 1951);
    const Passenger p1 = Passenger :: createPassenger("Abhinandan", "", "De", "134236789345", d1, Gender :: Male :: Type(), "8279728914");
    const Date& d2 = Date :: createDate(8, 4, 2021);
    const Date& d3 = Date :: createDate(9, 4, 2021);

    const Booking* b1 = Booking :: ReserveBooking(s1, s2, d2, BookingClass :: ACFirstClass :: Type(), TatkalCategory :: Type(), p1, d3);
    if(abs(b1->GetFare() -5344.5) >= 1e-3)
        cout << "Error in compute fare\n";

    cout << "***TESTING FOR TATKAL BOOKING IS DONE****\n";
}

PremiumTatkalBooking :: PremiumTatkalBooking(const Station& fromStation, const Station& toStation, 
    const Date& dateOfBooking, const Date& dateOfReservation, const Passenger& p, const BookingClass& b):
    Booking(fromStation, toStation, dateOfBooking, dateOfReservation, b, p, PremiumTatkalCategory :: Type()) {
        ComputeFare();
}

PremiumTatkalBooking :: ~PremiumTatkalBooking() {

}

void PremiumTatkalBooking :: ComputeFare(){
    fare_ = (Railways::GetDistance(fromStation_, toStation_))*(Booking :: sBaseFarePerKM);
    fare_ = fare_*(bookingClass_.GetLoadFactor()) + bookingClass_.GetReservationCharges();
    if(Railways :: GetDistance(fromStation_, toStation_) >= bookingClass_.GetMinDistanceForCharge()) {
        double check = Railways :: GetDistance(fromStation_, toStation_);
        check *= bookingClass_.GetTatkalLoad();
        check = max(bookingClass_.GetMinTatkalCharges(), check);
        check = min(bookingClass_.GetMaxTatkalCharges(), check);
        fare_ += check;
    }
    fare_ += 0.5;
}

void PremiumTatkalBooking:: UnitTest() {
    Station s1 = Station :: createStation("Kolkata");
    Station s2 = Station :: createStation("Delhi");
    const Date& d1 = Date :: createDate(16, 3, 1951);
    const Passenger p1 = Passenger :: createPassenger("Abhinandan", "", "De", "134236789345", d1, Gender :: Male :: Type(), "8279728914");
    const Date& d2 = Date :: createDate(8, 4, 2021);
    const Date& d3 = Date :: createDate(9, 4, 2021);

    const Booking* b1 = Booking :: ReserveBooking(s1, s2, d2, BookingClass :: ACFirstClass :: Type(), PremiumTatkalCategory :: Type(), p1, d3);
    if(abs(b1->GetFare() -5286.1) >= 1e-3)
        cout << "Error in compute fare\n";

    cout << "***TESTING FOR PREMIUM TATKAL BOOKING IS DONE****\n";
}
