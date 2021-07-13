/*
Name : Abhinandan De
Roll No: 19CS10069
*/
#include<iostream>
#include "Concessions.h"
#include "Divyaang.h"
#include<cmath>

using namespace std;

Concession :: Concession(const string& name):name_(name) {
    // ctor
}

Concession :: ~Concession() {
    // dtor
}

const string Concession :: GetName() const{
    return name_;
}

ostream& operator<< (ostream& os, const Concession& c) {
    os << c.GetName() << '\n';
    return os;
}

void Concession :: UnitTest() {
    const Concession& lC = LadiesConcession :: Type();                  // polymorphic binding!
    cout << lC << '\n';                 // testing the << operator

    if(lC.GetName() != "Ladies Concession")         // this is the only testable method!
        cout << "Error in GetName\n";
    
    cout << "****TESTING FOR CONCESSION IS COMPLETE****\n";
}

// setting the static variables
double LadiesConcession :: sConcessionValue = 0.00;

LadiesConcession :: LadiesConcession(const string& name): Concession(name){
    // ctor
}

LadiesConcession :: ~LadiesConcession() {
    // dtor
}

const LadiesConcession& LadiesConcession :: Type() {
    static const LadiesConcession ladiesConcession_("Ladies Concession");
    return ladiesConcession_;
}

double LadiesConcession :: GetConcession() const {
    return sConcessionValue;
}

void LadiesConcession :: ChangeConcession(double newConcession) {
    sConcessionValue = newConcession;
}

void LadiesConcession :: UnitTest() {
    const LadiesConcession& lC = LadiesConcession :: Type();                  // polymorphic binding!
    cout << lC << '\n';                 // testing the << operator

    if(lC.GetName() != "Ladies Concession")         // this is the only testable method!
        cout << "Error in GetName\n";
    
    if(abs(lC.GetConcession() - 0) >= 1e-3)
        cout << "Error in GetConcession\n";
    
    LadiesConcession :: ChangeConcession(0.2);          // try to change concession

    if(abs(lC.GetConcession() - 0.2) >= 1e-3)
        cout << "Error in Change Concession\n";
    
    LadiesConcession :: ChangeConcession(0.0);          // changing it back!

    cout << "****TESTING FOR LADIES CONCESSION IS COMPLETE****\n";
}

// here the concessions structure is complex and are stored in Divyaang Hierarchy!
DivyaangConcession :: DivyaangConcession(const string& name): Concession(name){
    // ctor
}

DivyaangConcession :: ~DivyaangConcession() {
    // dtor
}

const DivyaangConcession& DivyaangConcession :: Type() {
    static const DivyaangConcession divyaangConcession_("Divyaang Concession");
    return divyaangConcession_;
}

double DivyaangConcession :: GetConcession(const BookingClass& bClass, const Divyaang& subCategory) const {
    string check = bClass.GetName();
    double val = 0.0;
    if(check == "AC First Class") {
        val = GetConcession(BookingClass :: ACFirstClass :: Type(), subCategory);
    } else if(check == "Executive Chair Car") {
        val = GetConcession(BookingClass :: ExecutiveChairCar :: Type(), subCategory);
    } else if (check == "AC 2 Tier") {
        val = GetConcession(BookingClass :: AC2Tier :: Type(), subCategory);
    } else if(check == "AC 3 Tier") {
        val = GetConcession(BookingClass :: BookingClass :: AC2Tier :: Type(), subCategory);
    } else if(check == "First Class") {
        val = GetConcession(BookingClass :: FirstClass :: Type(), subCategory);
    } else if(check == "AC Chair Car") {
        val = GetConcession(BookingClass :: ACChairCar :: Type(), subCategory);
    } else if(check == "Sleeper") {
        val = GetConcession(BookingClass :: Sleeper :: Type(), subCategory);
    } else if(check == "Second Sitting") {
        val = GetConcession(BookingClass :: SecondSitting :: Type(), subCategory);
    }
    return val;
}

double DivyaangConcession :: GetConcession(const BookingClass :: ACFirstClass &myClass, const Divyaang& subCategory) const{ 
    return subCategory.GetConcession(myClass);
}

double DivyaangConcession :: GetConcession(const BookingClass :: ExecutiveChairCar &myClass, const Divyaang& subCategory) const {
    return subCategory.GetConcession(myClass);
}

double DivyaangConcession :: GetConcession(const BookingClass :: AC2Tier &myClass, const Divyaang& subCategory) const {
    return subCategory.GetConcession(myClass);
}

double DivyaangConcession :: GetConcession(const BookingClass :: AC3Tier &myClass, const Divyaang& subCategory) const {
    return subCategory.GetConcession(myClass);
}

double DivyaangConcession :: GetConcession(const BookingClass :: FirstClass &myClass, const Divyaang& subCategory) const {
    return subCategory.GetConcession(myClass);
}

double DivyaangConcession :: GetConcession(const BookingClass :: ACChairCar &myClass, const Divyaang& subCategory) const {
    return subCategory.GetConcession(myClass);
}

double DivyaangConcession :: GetConcession(const BookingClass :: Sleeper &myClass, const Divyaang& subCategory) const {
    return subCategory.GetConcession(myClass);
}

double DivyaangConcession :: GetConcession(const BookingClass :: SecondSitting &myClass, const Divyaang& subCategory) const {
    return subCategory.GetConcession(myClass);
}

void DivyaangConcession :: UnitTest() {
    const DivyaangConcession& dC = DivyaangConcession :: Type();            // the only occurence
    // cout << dC << '\n';                         // checking the << operator

    if(dC.GetName() != "Divyaang Concession")           // getname check
        cout << "Error in GetName function\n";

    if(abs(dC.GetConcession(BookingClass :: Sleeper :: Type(), Divyaang :: BlindDivyaang :: Type()) - 0.75) >= 1e-3)            // checking some random getConcessions
        cout << "Error in getConcession1\n";
    if(abs(dC.GetConcession(BookingClass :: ACFirstClass :: Type(), Divyaang :: OrthopaedicallyHandicappedDivyaang :: Type()) - 0.5) >= 1e-3)
        cout << "Error in getConcession2\n";
    if(abs(dC.GetConcession(BookingClass :: FirstClass :: Type(), Divyaang :: CancerPatientDivyaang :: Type()) - 0.75) >= 1e-3)
        cout << "Error in getConcession3\n";
    if(abs(dC.GetConcession(BookingClass :: SecondSitting :: Type(), Divyaang :: TBPatientDivyaang :: Type()) - 0.75) >= 1e-3)
        cout << "Error in getConcession4\n";

    cout << "****TESTING FOR DIVYAANG CONCESSION IS COMPLETE****\n";
}

// setting the static variables
double SeniorCitizenConcession :: sMaleConcessionValue = 0.4;
double SeniorCitizenConcession :: sFemaleConcessionValue = 0.5;

SeniorCitizenConcession :: SeniorCitizenConcession(const string& name): Concession(name){
    // ctor
}

SeniorCitizenConcession :: ~SeniorCitizenConcession() {
    // dtor
}

const SeniorCitizenConcession& SeniorCitizenConcession :: Type() {
    static const SeniorCitizenConcession seniorCitizenConcession_("Senior Citizens Concession");
    return seniorCitizenConcession_;
}

double SeniorCitizenConcession :: GetConcession(const Passenger& p) const{
    if(Gender :: IsMale(p.getGender()))           
            return sMaleConcessionValue;
        else
            return sFemaleConcessionValue;
}

void SeniorCitizenConcession :: ChangeMaleConcession(double newMaleConcession) {
    sMaleConcessionValue = newMaleConcession;
}

void SeniorCitizenConcession :: ChangeFemaleConcession(double newFemaleConcession) {
    sFemaleConcessionValue = newFemaleConcession;
}

void SeniorCitizenConcession :: UnitTest() {
    const SeniorCitizenConcession& sC = SeniorCitizenConcession :: Type();                  // polymorphic binding!
    cout << sC << '\n';                 // testing the << operator

    const Date d1 = Date :: createDate(16, 03, 2000);
    const Date d2 = Date :: createDate(13, 04, 2001);

    const Passenger p1 = Passenger :: createPassenger("Abhi", "", "", "123456789123", d1, Gender :: Male :: Type());        // for GetConcession!
    const Passenger p2 = Passenger :: createPassenger("Ankita", "", "", "123456737123", d2, Gender :: Female :: Type());        // 1 male, 1 female

    if(sC.GetName() != "Senior Citizens Concession")         // this is the only testable method!
        cout << "Error in GetName\n";
    
    if(abs(sC.GetConcession(p1) - 0.4) >= 1e-3)
        cout << "Error in GetConcession\n";
    
    SeniorCitizenConcession :: ChangeMaleConcession(0.2);          // try to change concession

    if(abs(sC.GetConcession(p1) - 0.2) >= 1e-3)
        cout << "Error in ChangeMaleConcession\n";

    SeniorCitizenConcession :: ChangeMaleConcession(0.4);           // change it back!

    if(abs(sC.GetConcession(p2) - 0.5) >= 1e-3)
        cout << "Error in GetConcession\n";
    
    SeniorCitizenConcession :: ChangeFemaleConcession(0.6);          // changing female concession!

    if(abs(sC.GetConcession(p2) - 0.6) >= 1e-3)
        cout << "Error in GetConcession\n";
    
    SeniorCitizenConcession :: ChangeFemaleConcession(0.5);         // changing it back

    cout << "****TESTING FOR SENIOR CITIZENS CONCESSION IS COMPLETE****\n";
}