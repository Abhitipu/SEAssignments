/*
Name : Abhinandan De
Roll No: 19CS10069
*/

#ifndef BOOKINGCLASS_H
#define BOOKINGCLASS_H

/*
Some classes eg: Booking which dont have further derived classes have been made polymorphic to extend the design.
Encapsulation is increased as much as possible. Attributes have been made private, constructors/destructors are made private
    for singletons. Copy assignment operators and copy constructors are blocked in those cases.
Static members are used for modelling attributes which are common to all instances of a class.
*/

#include<string>
#include<iostream>
using namespace std;

class BookingClass {                                // abstract base class

protected:
    double loadFactor_;       // for the booking

    BookingClass(const double loadFactor);

public:

    BookingClass(const BookingClass& b) = delete;

    BookingClass& operator=(const BookingClass& b) = delete;

    virtual ~BookingClass();

    virtual double GetLoadFactor() const;

    virtual bool IsSitting() const = 0;             
    
    virtual int GetNumberOfTiers() const = 0;       
    
    virtual string GetName() const = 0;
    
    virtual bool IsAC() const = 0;
    
    virtual bool IsLuxury() const = 0;

    virtual string remarks() const = 0;

    static void UnitTest();

    friend ostream& operator<< (ostream& os, const BookingClass& b);
};

/**************** SITTING *********************/

class Sitting : public BookingClass {               // abstract class
protected:
    Sitting(const double loadFactor);
    virtual ~Sitting();
public:
    Sitting(const Sitting&)=delete;                 // blocking all cctors/ copy assignment operators

    Sitting& operator=(const Sitting&) = delete;

    bool IsSitting() const;

    static void UnitTest();
   
    int GetNumberOfTiers() const;
};


class ACChairCar : public Sitting {                 // concrete class
   
    static double sMyLoadFactor;
    static bool sMyLuxury;

protected:
    ACChairCar();
    virtual ~ACChairCar();

public:
    static const ACChairCar& Type();

    ACChairCar(const ACChairCar&)=delete;                 // blocking all cctors/ copy assignment operators

    ACChairCar& operator=(const ACChairCar&) = delete;

    static void ChangeLuxury(bool newLuxury);

    static void ChangeLoadFactor(double newLoadFactor);

    virtual string GetName() const;

    virtual bool IsAC() const;

    virtual bool IsLuxury() const;

    double GetLoadFactor() const;

    static void UnitTest();

    virtual string remarks() const;
};


class SecondSitting : public Sitting {                  // concrete class

    static double sMyLoadFactor;
    static bool sMyLuxury;

protected:
    SecondSitting();
    virtual ~SecondSitting();

public:
    static const SecondSitting& Type();

    SecondSitting(const SecondSitting&)=delete;                 // blocking all cctors/ copy assignment operators

    SecondSitting& operator=(const SecondSitting&) = delete;

    static void ChangeLoadFactor(double newLoadFactor);

    static void ChangeLuxury(bool newLuxury);

    virtual string GetName() const;

    virtual bool IsAC() const;

    virtual bool IsLuxury() const;

    double GetLoadFactor() const;

    static void UnitTest();

    virtual string remarks() const;
};

/*************** SLEEPING ******************/
class Sleeping : public BookingClass {              // abstract class
protected:
    Sleeping(const double loadFactor);
    virtual ~Sleeping();

public:  
    Sleeping(const Sleeping&)=delete;                 // blocking all cctors/ copy assignment operators
    Sleeping& operator=(const Sleeping&) = delete;
    bool IsSitting() const;
    static void UnitTest();
};


class ThreeTier : public Sleeping {                     // abstract class
protected:
    ThreeTier(const double loadFactor);
    virtual ~ThreeTier();
public:
    ThreeTier(const ThreeTier&)=delete;                 // blocking all cctors/ copy assignment operators
    ThreeTier& operator=(const ThreeTier&) = delete;
    static void UnitTest();
    int GetNumberOfTiers() const;
};


class Sleeper : public ThreeTier {
    static double sMyLoadFactor;
    static bool sMyLuxury;

protected:
    Sleeper();
    virtual ~Sleeper();

public:
    static const Sleeper& Type();

    Sleeper(const Sleeper&)=delete;

    Sleeper& operator=(const Sleeper&) = delete;

    static void ChangeLoadFactor(double newLoadFactor);

    static void ChangeLuxury(bool newLuxury);

    virtual string GetName() const;

    virtual bool IsAC() const;

    virtual bool IsLuxury() const;

    double GetLoadFactor() const;

    static void UnitTest();

    virtual string remarks() const;
};


class AC3Tier : public ThreeTier {                  // concrete class
    
    static double sMyLoadFactor;
    static bool sMyLuxury;

protected:
    
    AC3Tier();
    virtual ~AC3Tier();

public:
    static const AC3Tier& Type();

    AC3Tier(const AC3Tier&)=delete;

    AC3Tier& operator=(const AC3Tier&) = delete;

    static void ChangeLoadFactor(double newLoadFactor);

    static void ChangeLuxury(bool newLuxury);

    virtual string GetName() const;

    virtual bool IsAC() const;

    virtual bool IsLuxury() const;

    double GetLoadFactor() const;

    virtual string remarks() const;

    static void UnitTest();
};

class TwoTier : public Sleeping {                   // abstract class
protected:
    TwoTier(const double loadFactor);
    virtual ~TwoTier();
public:    
    static void UnitTest();
    int GetNumberOfTiers() const;
};

class ACFirstClass : public TwoTier {               // concrete class
    
    static double sMyLoadFactor;
    static bool sMyLuxury;

    ACFirstClass();
    virtual ~ACFirstClass();

public:
    static const ACFirstClass& Type();

    ACFirstClass(const ACFirstClass&)=delete;

    ACFirstClass& operator=(const ACFirstClass&) = delete;

    static void ChangeLoadFactor(double newLoadFactor);
    
    static void ChangeLuxury(bool newLuxury);

    virtual string GetName() const;

    virtual bool IsAC() const;

    virtual bool IsLuxury() const;

    double GetLoadFactor() const;

    virtual string remarks() const;

    static void UnitTest();
};

class AC2Tier : public TwoTier {

    static double sMyLoadFactor;
    static bool sMyLuxury;
    
    AC2Tier();
    virtual ~AC2Tier();

public:
    
    static const AC2Tier& Type();

    AC2Tier(const AC2Tier&)=delete;

    AC2Tier& operator=(const AC2Tier&) = delete;
    
    static void ChangeLoadFactor(double newLoadFactor);
    
    static void ChangeLuxury(bool newLuxury);
    
    virtual string GetName() const;
    
    virtual bool IsAC() const;
    
    virtual bool IsLuxury() const;

    double GetLoadFactor() const;

    virtual string remarks() const;

    static void UnitTest();
};


class FirstClass : public TwoTier {               // concrete class
    
    static double sMyLoadFactor;
    static bool sMyLuxury;

    FirstClass();
    virtual ~FirstClass();

public:
    static const FirstClass& Type();

    FirstClass(const FirstClass&)=delete;

    FirstClass& operator=(const FirstClass&) = delete;
    
    static void ChangeLoadFactor(double newLoadFactor);

    static void ChangeLuxury(bool newLuxury);

    virtual string GetName() const;

    virtual bool IsAC() const;

    virtual bool IsLuxury() const;

    double GetLoadFactor() const;

    virtual string remarks() const;

    static void UnitTest();

};

#endif      // BOOKINGCLASS_H