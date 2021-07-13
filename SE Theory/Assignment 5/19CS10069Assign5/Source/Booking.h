/*
Name : Abhinandan De
Roll No: 19CS10069
*/

#ifndef BOOKING_H
#define BOOKING_H

#include<string>
#include<iostream>

class BookingCategory;      // forward declaration

#include "Station.h"
#include "Date.h"
#include "Passenger.h"
#include "BookingClass.h"
#include "BookingCategory.h"
#include "Railways.h"
#include "Concessions.h"
#include "Divyaang.h"

// the booking category hierarchy modelled using inclusion polymorphism

using namespace std;


class Booking {
protected:
    const Station fromStation_, toStation_;             // all are const attributes 
    const Passenger passenger_;
    const BookingClass& bookingClass_;
    const BookingCategory& bookingCategory_;        
    const int pnr_;                  
    const Date dateOfReservation_;
    const Date dateOfBooking_;      
    double fare_;                 
    string bookingMessage_;             

    static double sBaseFarePerKM;                       // these keep track of the common attributes for booking!
    static int sBookingPNRSerial;
    static double sLuxuryTaxPercent;
    static double sTatkalLoad;
    static double sPremiumTatkalLoad;

    Booking(const Station& from, const  Station& to, const Date& d, const Date&, const BookingClass& bClass, const Passenger& p, const BookingCategory& bCat);
  
public:
    static vector<Booking*> sBookings;
    
    virtual void ComputeFare() = 0;

    static const Booking* ReserveBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking,           // this is the funciton which is called first     
                                const BookingClass& bClass, const BookingCategory& bCategory, const Passenger& p, 
                                const Date& dateOfReservation);

    static void Validate(const Station& from, const Station& to, const Date& dob, const BookingClass& bclass, const BookingCategory& bCategory, const Passenger& p, const Date& dor);
    // this validates the booking
    static void ChangeLuxuryTaxPercent(double newLuxuryTaxPercent);       
    
    static void ChangeAcSurcharge(double newSurcharge);         // change functions!
    
    static void ChangeBaseFare(double newBaseFare);
    
    static void UnitTest();

    double GetFare() const;

    virtual ~Booking();
    
    friend ostream& operator<< (ostream& os, const Booking& b);         // stream operator
};

class GeneralBooking : public Booking {
public:    
    GeneralBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, const Date& dateOfReservation, const Passenger& p, const BookingClass& b);
    ~GeneralBooking();
    void ComputeFare();             // all the base classes override this computefare method!
    static void UnitTest();
    friend ostream& operator<< (ostream& os, const Booking& b);
};

class LadiesBooking : public Booking {
public:
    LadiesBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, const Date& dateOfReservation, const Passenger& p, const BookingClass& b);
    ~LadiesBooking();
    void ComputeFare();
    static void UnitTest();
    friend ostream& operator<< (ostream& os, const Booking& b);
};

class SeniorCitizensBooking : public Booking {
public:
    SeniorCitizensBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, const Date& dateOfReservation, const Passenger& p, const BookingClass& b);
    ~SeniorCitizensBooking();
    void ComputeFare();
    static void UnitTest();
    friend ostream& operator<< (ostream& os, const Booking& b);
};

class DivyaangBooking : public Booking {
public:
    DivyaangBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, const Date& dateOfReservation, const Passenger& p, const BookingClass& b);
    ~DivyaangBooking();
    void ComputeFare();
    static void UnitTest();
    friend ostream& operator<< (ostream& os, const Booking& b);
};

class TatkalBooking : public Booking {
public:
    TatkalBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, const Date& dateOfReservation, const Passenger& p, const BookingClass& b);
    ~TatkalBooking();
    void ComputeFare();
    static void UnitTest();
    friend ostream& operator<< (ostream& os, const Booking& b);
};

class PremiumTatkalBooking : public Booking {
public:
    PremiumTatkalBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, const Date& dateOfReservation, const Passenger& p, const BookingClass& b);
    ~PremiumTatkalBooking();
    void ComputeFare();
    static void UnitTest();
    friend ostream& operator<< (ostream& os, const Booking& b);
};

#endif  // BOOKING_H