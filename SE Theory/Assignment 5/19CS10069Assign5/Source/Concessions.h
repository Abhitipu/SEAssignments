/*
Name : Abhinandan De
Roll No: 19CS10069
*/
#ifndef CONCESSIONS_H
#define CONCESSIONS_H

#include "BookingClass.h"
#include "Divyaang.h"
#include "Passenger.h"
#include "BookingCategory.h"
#include "Gender.h"
#include<string>

// Concessions hierarchy modelled using Ad-Hoc ploymorphism (function overloading)

class Concession {
    const string name_;                    // storing the name of the Concession leaf class
protected:
    Concession(const string& name);         // Since base classes need to access them!
    virtual ~Concession();
public:
    const string GetName() const;
    static void UnitTest();
    friend ostream& operator<< (ostream& os, const Concession& c);
};


class LadiesConcession : public Concession {        
    static double sConcessionValue;                 // static declaration
    LadiesConcession(const string&);
    ~LadiesConcession();
public:
    static const LadiesConcession& Type();          // Meyers singleton implementation
    double GetConcession() const;                   // the get and change methods
    static void ChangeConcession(double newConcession);        
    static void UnitTest();
    friend ostream& operator<< (ostream& os, const Concession& c);
};


class DivyaangConcession : public Concession  {
    DivyaangConcession(const string&);
    ~DivyaangConcession();
public:
    
    static const DivyaangConcession& Type();        // Meyers singleton implementation

    double GetConcession(const BookingClass& bClass, const Divyaang& subCategory) const;                // using function overloading design!

    double GetConcession(const BookingClass :: ACFirstClass &myClass, const Divyaang& subCategory) const;   // one for each booking class

    double GetConcession(const BookingClass :: ExecutiveChairCar &myClass, const Divyaang& subCategory) const;

    double GetConcession(const BookingClass :: AC2Tier &myClass, const Divyaang& subCategory) const;

    double GetConcession(const BookingClass :: AC3Tier &myClass, const Divyaang& subCategory) const;

    double GetConcession(const BookingClass :: FirstClass &myClass, const Divyaang& subCategory) const;

    double GetConcession(const BookingClass :: ACChairCar &myClass, const Divyaang& subCategory) const;

    double GetConcession(const BookingClass :: Sleeper &myClass, const Divyaang& subCategory) const;

    double GetConcession(const BookingClass :: SecondSitting &myClass, const Divyaang& subCategory) const;

    static void UnitTest();

    friend ostream& operator<< (ostream& os, const Concession& c);
};

class SeniorCitizenConcession : public Concession  {
    static double sMaleConcessionValue;                 // the two values!
    static double sFemaleConcessionValue;
    SeniorCitizenConcession(const string&);         
    ~SeniorCitizenConcession();
public:
    
    static const SeniorCitizenConcession& Type();           // Meyers singleton
    double GetConcession(const Passenger& p) const;
    static void ChangeMaleConcession(double newMaleConcession);            // the get and change methods (separate for male and female)
    static void ChangeFemaleConcession(double newFemaleConcession);
    static void UnitTest();
    friend ostream& operator<< (ostream& os, const Concession& c);
};

#endif  // CONCESSIONS_H