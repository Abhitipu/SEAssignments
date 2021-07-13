/*
Name : Abhinandan De
Roll No: 19CS10069
*/

#ifndef BOOKINGCLASS_H
#define BOOKINGCLASS_H

/*
The BookingClass hierarchy made using parametric polymorphism
*/

#include<string>
#include<iostream>
using namespace std;


template<typename T>
class BookingClasses;

class BookingClass {                                // abstract base class
    BookingClass& operator=(const BookingClass& b);
    struct ACFirstClass_{};
    struct ExecutiveChairCar_{};
    struct AC2Tier_{};
    struct AC3Tier_{};
    struct FirstClass_{};
    struct ACChairCar_{};
    struct Sleeper_{};
    struct SecondSitting_{};
    
protected:
    BookingClass();                             // since the child clases need to access these!
    virtual ~BookingClass();
    BookingClass(const BookingClass& b);


public:
    virtual double GetReservationCharges() const = 0;           // the cirtual get methods, to be overriden!

    virtual double GetLoadFactor() const = 0;

    virtual bool IsSitting() const = 0; 
    
    virtual int GetNumberOfTiers() const = 0;
    
    virtual string GetName() const = 0;
    
    virtual bool IsAC() const = 0;
    
    virtual bool IsLuxury() const = 0;

    virtual double GetMinDistanceForCharge() const = 0;

    virtual double GetMaxTatkalCharges() const = 0;

    virtual double GetMinTatkalCharges() const = 0;

    virtual double GetTatkalLoad() const = 0;

    virtual double GetPremiumTatkalLoad() const = 0;

    typedef BookingClasses<ACFirstClass_> ACFirstClass;                 // making the code less cluttered
    typedef BookingClasses<ExecutiveChairCar_> ExecutiveChairCar;
    typedef BookingClasses<AC2Tier_> AC2Tier;
    typedef BookingClasses<AC3Tier_> AC3Tier;
    typedef BookingClasses<FirstClass_> FirstClass;
    typedef BookingClasses<ACChairCar_> ACChairCar;
    typedef BookingClasses<Sleeper_> Sleeper;
    typedef BookingClasses<SecondSitting_> SecondSitting;

    static void UnitTest();

    friend ostream& operator<< (ostream& os, const BookingClass& b);
};

template<typename T>
class BookingClasses : public BookingClass {
    static const bool sIsAC;
    static const int sNoOfTiers;
    static const bool sIsSitting;
    static const string& sName;         // assign this!
    static double sLoadFactor;
    static bool sIsLuxury;
    static double sReservationCharges;
    static double sMinTatkalCharges;            // this is only defined for tatkal and premium tatkal!
    static double sMaxTatkalCharges;            // "    "   "    "    "    "    "    "    "    "    " 
    static double sMinDistanceForCharge;        // "    "   "    "    "    "    "    "    "    "    "
    static double sTatkalLoad;                  // set this value!!

    BookingClasses();
    BookingClasses(const BookingClasses<T>& b);
    BookingClasses<T>& operator=(const BookingClasses<T>& b);
    ~BookingClasses();

public:
    static const BookingClasses<T>& Type();

    static void changeLuxury(bool newLuxury);                   // some static methods for changing the static attributes!

    static void changeLoadFactor(double newLoadFactor);

    static void changeReservationCharges(double newCharges);

    static void changeMinTatkalCharge(double newCharge);

    static void changeMaxTatkalCharge(double newCharge);

    static void changeMinDistanceForCharge(double newDistance);

    static void changeTatkalLoad(double newTatkalLoad);

    virtual double GetReservationCharges() const;           // the overriden get functions

    virtual double GetLoadFactor() const;

    virtual bool IsSitting() const;      
    
    virtual int GetNumberOfTiers() const;
    
    virtual string GetName() const;
    
    virtual bool IsAC() const;
    
    virtual bool IsLuxury() const;

    virtual double GetTatkalLoad() const;

    virtual double GetPremiumTatkalLoad() const;

    virtual double GetMinDistanceForCharge() const;

    virtual double GetMinTatkalCharges() const;

    virtual double GetMaxTatkalCharges() const ;

    static void UnitTest();

    friend ostream& operator<< (ostream& os, const BookingClass& b);

};

#endif      // BOOKINGCLASS_H