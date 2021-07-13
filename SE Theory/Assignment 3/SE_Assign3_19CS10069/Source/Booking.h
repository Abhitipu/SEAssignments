/*
Name : Abhinandan De
Roll No: 19CS10069
*/
#ifndef BOOKING_H
#define BOOKING_H

#include<string>
#include<iostream>

#include "Station.h"
#include "Date.h"
#include "Passenger.h"
#include "BookingClass.h"

using namespace std;

class Booking {
    const Station from_, to_;
    const Passenger* p_ = NULL;
    const BookingClass& bClass_;        
    const int pnr_;
    const Date date_;
    double fare_;
    string bookingMessage_;

    static double sBaseFarePerKM;
    static int sBookingPNRSerial;
    static double sACSurcharge;
    static double sLuxuryTaxPercent;
    
public:
    static vector<Booking*> sBookings;

    Booking(const Station& from, const  Station& to, const Date& d, const BookingClass& bClass);
    
    void ComputeFare();

    static void ChangeLuxuryTaxPercent(double newLuxuryTaxPercent);       
    
    static void ChangeAcSurcharge(double newSurcharge);
    
    static void ChangeBaseFare(double newBaseFare);
    
    static void UnitTest();

    virtual ~Booking();
    
    friend ostream& operator<< (ostream& os, const Booking& b);
};

#endif  // BOOKING_H