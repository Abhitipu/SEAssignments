/*
Name : Abhinandan De
Roll No: 19CS10069
*/
#ifndef DIVYAANG_H
#define DIVYAANG_H

#include "BookingClass.h"
#include "Divyaang.h"

// Divyaang Hierarchy implemented 
// using parametric-inclusion polymorphism!

template<typename T>
class DivyaangSubCategories;

// Convention for disability index:
// 0: No disability (DEFAULT VALUE).
// 1: Blind
// 2: Orthopaedically Handicaped
// 3: Cancer Patient
// 4: TB Patient

class Divyaang {
    struct BlindDivyaang_{};                            // the various types
    struct OrthopaedicallyHandicappedDivyaang_{};
    struct CancerPatientDivyaang_{};
    struct TBPatientDivyaang_{};
    
protected:
    Divyaang();                         // child classes need access!
    virtual ~Divyaang();
public:

    virtual double GetConcession(const BookingClass :: ACFirstClass &myClass) const=0;      // dynamic dispatch!

    virtual double GetConcession(const BookingClass :: ExecutiveChairCar &myClass) const=0;

    virtual double GetConcession(const BookingClass :: AC2Tier &myClass) const=0;

    virtual double GetConcession(const BookingClass :: FirstClass &myClass) const=0;

    virtual double GetConcession(const BookingClass :: AC3Tier &myClass) const=0;

    virtual double GetConcession(const BookingClass :: ACChairCar &myClass)  const = 0;

    virtual double GetConcession(const BookingClass :: Sleeper &myClass) const = 0;

    virtual double GetConcession(const BookingClass :: SecondSitting &myClass) const = 0;

    virtual const string GetName() const = 0;                   // to get name

    typedef DivyaangSubCategories<BlindDivyaang_> BlindDivyaang;                                               // making the code less cluttered
    typedef DivyaangSubCategories<OrthopaedicallyHandicappedDivyaang_> OrthopaedicallyHandicappedDivyaang;
    typedef DivyaangSubCategories<CancerPatientDivyaang_> CancerPatientDivyaang;
    typedef DivyaangSubCategories<TBPatientDivyaang_> TBPatientDivyaang;

    static void UnitTest();

    friend ostream& operator<<(ostream& os, const Divyaang& d);
};

// parametric + inclusion

template<typename T>
class DivyaangSubCategories : public Divyaang {
    static const string& sName;                         // all attributes are static
    static double sACFirstClass;
    static double sExecutiveChairCar;
    static double sAC2Tier;
    static double sFirstClass;
    static double sAC3Tier;
    static double sACChairCar;
    static double sSleeper;
    static double sSecondSitting;

    DivyaangSubCategories();
    ~DivyaangSubCategories();

public:
    static const DivyaangSubCategories<T>& Type();                          // for meyer's singleton

    double GetConcession(const BookingClass :: ACFirstClass &myClass) const;            // all methods are overriden!

    double GetConcession(const BookingClass :: ExecutiveChairCar &myClass) const;

    double GetConcession(const BookingClass :: AC2Tier &myClass) const;

    double GetConcession(const BookingClass :: FirstClass &myClass) const;

    double GetConcession(const BookingClass :: AC3Tier &myClass) const;

    double GetConcession(const BookingClass :: ACChairCar &myClass) const;

    double GetConcession(const BookingClass :: Sleeper &myClass) const;

    double GetConcession(const BookingClass :: SecondSitting &myClass) const;

    const string GetName() const;

    static void UnitTest();

    friend ostream& operator<<(ostream& os, const Divyaang& d);
};

#endif  // DIVYAANG_H