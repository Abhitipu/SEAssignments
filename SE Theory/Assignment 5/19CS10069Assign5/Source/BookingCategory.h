/*
Name : Abhinandan De
Roll No: 19CS10069
*/
#ifndef BOOKINGCATEGORY_H
#define BOOKINGCATEGORY_H

class Booking;          // forward declaration so that type is recognised

// the Booking category hierarchy.. made with inclusion polymorphism and virtual construction 
// in a parallel manner with the Booking hierarchy

#include "Booking.h"
#include "Station.h"
#include "Passenger.h"
#include "BookingCategory.h"
#include "Date.h"
#include "Concessions.h"
#include "Exceptions.h"
#include "Gender.h"

class BookingCategory {
protected:
    BookingCategory();
    ~BookingCategory();
public:
    static const BookingCategory& Type();               // meyers singleton
    virtual const Booking* createBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking,       // pure virtual functions
                            const Date& dateOfReservation, const Passenger& p, const BookingClass& bClass) const = 0;
    virtual const string& getName() const = 0;                                  // createBooking returns the actual booking instance using virtual construction!
    static void UnitTest();
    friend ostream& operator<< (ostream& os, const BookingCategory& b);
};

class GeneralCategory : public BookingCategory {
    const string name_;
    GeneralCategory(const string& name);
    GeneralCategory(const GeneralCategory& other);
    ~GeneralCategory();
public:
    GeneralCategory operator=(const GeneralCategory& other) = delete;                   // copy assignment operator has been blocked!
    static const GeneralCategory& Type();                                               // another meyers singleton
    static bool IsEligible(const Passenger& p, const Date& d);                          // the isEligible method which checks for eligibility for the category
    const Booking* createBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, 
                            const Date& dateOfReservation, const Passenger& p, const BookingClass& bClass) const;
    const string& getName() const;
    static void UnitTest();
    friend ostream& operator<< (ostream& os, const BookingCategory& b);
};

class LadiesCategory : public BookingCategory {
    const string name_;
    LadiesCategory(const string& name);
    ~LadiesCategory();
    LadiesCategory(const LadiesCategory& other);
public:
    LadiesCategory operator=(const LadiesCategory& other) = delete;                     // copy assignment operator has been blocked!
    static const LadiesCategory& Type();                                                // another meyers singleton
    static bool IsEligible(const Passenger& p, const Date& d);                          // the isEligible method which checks for eligibility for the category

    const Booking* createBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, 
                            const Date& dateOfReservation, const Passenger& p, const BookingClass& bClass) const;
    const string& getName() const;
    static void UnitTest();
    friend ostream& operator<< (ostream& os, const BookingCategory& b);
};

class SeniorCitizenCategory : public BookingCategory {
    const string name_;
    SeniorCitizenCategory(const string& name);
    SeniorCitizenCategory(const SeniorCitizenCategory& other);
    ~SeniorCitizenCategory();
public:
    SeniorCitizenCategory operator=(const SeniorCitizenCategory& other) = delete;           // copy assignment operator has been blocked!
    static const SeniorCitizenCategory& Type();                                             // another meyers singleton
    static bool IsEligible(const Passenger& p, const Date& d);                              // the isEligible method which checks for eligibility for the category
    const Booking* createBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, 
                            const Date& dateOfReservation, const Passenger& p, const BookingClass& bClass) const;
    const string& getName() const;
    static void UnitTest();
    friend ostream& operator<< (ostream& os, const BookingCategory& b);
};

class DivyaangCategory : public BookingCategory {
    const string name_;
    DivyaangCategory(const string& name);
    ~DivyaangCategory();
    DivyaangCategory(const DivyaangCategory& other);
public:
    DivyaangCategory operator=(const DivyaangCategory& other) = delete;
    static const DivyaangCategory& Type();
    static bool IsEligible(const Passenger& p, const Date& d);
    const Booking* createBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, 
                            const Date& dateOfReservation, const Passenger& p, const BookingClass& bClass) const;
    const string& getName() const;
    static void UnitTest();
    friend ostream& operator<< (ostream& os, const BookingCategory& b);
};

class TatkalCategory : public BookingCategory {
    const string name_;
    TatkalCategory(const string& name);
    ~TatkalCategory();
    TatkalCategory(const TatkalCategory& other);
public:
    TatkalCategory operator=(const TatkalCategory& other) = delete;
    static const TatkalCategory& Type();
    static bool IsEligible(const Date& dateOfBooking, const Date& dateOfReservation);
    const Booking* createBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, 
                            const Date& dateOfReservation, const Passenger& p, const BookingClass& bClass) const;
    const string& getName() const;
    static void UnitTest();
    friend ostream& operator<< (ostream& os, const BookingCategory& b);
};

class PremiumTatkalCategory : public BookingCategory {
    const string name_;
    PremiumTatkalCategory(const string& name);
    ~PremiumTatkalCategory();
    PremiumTatkalCategory(const PremiumTatkalCategory& other);
public:
    PremiumTatkalCategory operator=(const PremiumTatkalCategory& other) = delete;
    static const PremiumTatkalCategory& Type();
    static bool IsEligible(const Date& dateOfBooking, const Date& dateOfReservation);
    const Booking* createBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, 
                            const Date& dateOfReservation, const Passenger& p, const BookingClass& bClass) const;
    const string& getName() const;
    static void UnitTest();
    friend ostream& operator<< (ostream& os, const BookingCategory& b);
};

#endif // BOOKINGCATEGORY_H