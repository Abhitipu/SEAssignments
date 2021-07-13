/*
Name : Abhinandan De
Roll No: 19CS10069
*/
#include<iostream>
using namespace std;

#include "Divyaang.h"
#include<cmath>

// forward declaration of the templates to avoid linker error (eg : undefined reference)

template class DivyaangSubCategories<Divyaang :: BlindDivyaang_>;
template class DivyaangSubCategories<Divyaang :: OrthopaedicallyHandicappedDivyaang_>;
template class DivyaangSubCategories<Divyaang :: CancerPatientDivyaang_>;
template class DivyaangSubCategories<Divyaang :: TBPatientDivyaang_>;

// assigning values to the static data members

template<> const string& Divyaang :: BlindDivyaang :: sName = "Blind Divyaang";
template<> const string& Divyaang :: OrthopaedicallyHandicappedDivyaang :: sName = "Orthopaedically Handicapped Divyaang";
template<> const string& Divyaang :: CancerPatientDivyaang :: sName = "Cancer Patient Divyaang";
template<> const string& Divyaang :: TBPatientDivyaang :: sName = "TB Patient Divyaang";

template<> double Divyaang :: BlindDivyaang :: sACFirstClass = 0.50;
template<> double Divyaang :: OrthopaedicallyHandicappedDivyaang :: sACFirstClass = 0.50;
template<> double Divyaang :: CancerPatientDivyaang :: sACFirstClass = 0.50;
template<> double Divyaang :: TBPatientDivyaang :: sACFirstClass = 0.00;

template<> double Divyaang :: BlindDivyaang :: sExecutiveChairCar = 0.75;
template<> double Divyaang :: OrthopaedicallyHandicappedDivyaang :: sExecutiveChairCar = 0.75;
template<> double Divyaang :: CancerPatientDivyaang :: sExecutiveChairCar = 0.75;
template<> double Divyaang :: TBPatientDivyaang :: sExecutiveChairCar = 0.00;

template<> double Divyaang :: BlindDivyaang :: sAC2Tier = 0.50;
template<> double Divyaang :: OrthopaedicallyHandicappedDivyaang :: sAC2Tier = 0.50;
template<> double Divyaang :: CancerPatientDivyaang :: sAC2Tier = 0.50;
template<> double Divyaang :: TBPatientDivyaang :: sAC2Tier = 0.00;

template<> double Divyaang :: BlindDivyaang :: sFirstClass = 0.75;
template<> double Divyaang :: OrthopaedicallyHandicappedDivyaang :: sFirstClass = 0.75;
template<> double Divyaang :: CancerPatientDivyaang :: sFirstClass = 0.75;
template<> double Divyaang :: TBPatientDivyaang :: sFirstClass = 0.75;

template<> double Divyaang :: BlindDivyaang :: sAC3Tier = 0.75;
template<> double Divyaang :: OrthopaedicallyHandicappedDivyaang :: sAC3Tier = 0.75;
template<> double Divyaang :: CancerPatientDivyaang :: sAC3Tier = 1.00;
template<> double Divyaang :: TBPatientDivyaang :: sAC3Tier = 0.00;

template<> double Divyaang :: BlindDivyaang :: sACChairCar = 0.75;
template<> double Divyaang :: OrthopaedicallyHandicappedDivyaang :: sACChairCar = 0.75;
template<> double Divyaang :: CancerPatientDivyaang :: sACChairCar = 1.00;
template<> double Divyaang :: TBPatientDivyaang :: sACChairCar = 0.00;

template<> double Divyaang :: BlindDivyaang :: sSleeper = 0.75;
template<> double Divyaang :: OrthopaedicallyHandicappedDivyaang :: sSleeper = 0.75;
template<> double Divyaang :: CancerPatientDivyaang :: sSleeper = 1.00;
template<> double Divyaang :: TBPatientDivyaang :: sSleeper = 0.75;

template<> double Divyaang :: BlindDivyaang :: sSecondSitting = 0.75;
template<> double Divyaang :: OrthopaedicallyHandicappedDivyaang :: sSecondSitting = 0.75;
template<> double Divyaang :: CancerPatientDivyaang :: sSecondSitting = 1.00;
template<> double Divyaang :: TBPatientDivyaang :: sSecondSitting = 0.75;

Divyaang :: Divyaang() {
    // ctor
}

Divyaang :: ~Divyaang() {
    // dtor
}

void Divyaang :: UnitTest() {
    const Divyaang& d = Divyaang :: BlindDivyaang :: Type();            // cheking if mereys singleton works
    cout << d << '\n';                      // checking if operator << works

    if(d.GetName() != "Blind Divyaang")
        cout << "Error in Get Name function\n";

    if(abs(d.GetConcession(BookingClass :: ACFirstClass :: Type()) - 0.5) >= 1e-3)
        cout << "Error in Get Concession1!\n";
    if(abs(d.GetConcession(BookingClass :: AC2Tier :: Type()) - 0.5) >= 1e-3)
        cout << "Error in Get Concession2!\n";
    if(abs(d.GetConcession(BookingClass :: AC3Tier :: Type()) - 0.75) >= 1e-3)
        cout << "Error in Get Concession3!\n";
    if(abs(d.GetConcession(BookingClass :: Sleeper :: Type()) - 0.75) >= 1e-3)
        cout << "Error in Get Concession4!\n";
    
    cout << "***TESTING FOR CLASS DIVYAANG IS COMPLETE***\n";
} 

ostream& operator<<(ostream& os, const Divyaang& d) {
    os << d.GetName() << '\n';
    return os;
}

template<typename T>
DivyaangSubCategories<T> :: DivyaangSubCategories() {
    // ctor
}   

template<typename T>
DivyaangSubCategories<T> :: ~DivyaangSubCategories() {
    // dtor
}

template<typename T>
const DivyaangSubCategories<T>& DivyaangSubCategories<T> :: Type() {                // all the overriden methods
    static const DivyaangSubCategories<T> myCategory;
    return myCategory;
}

template<typename T>
double DivyaangSubCategories<T> :: GetConcession(const BookingClass :: ACFirstClass &myClass) const {
    return DivyaangSubCategories<T>::sACFirstClass;
}

template<typename T>
double DivyaangSubCategories<T> :: GetConcession(const BookingClass :: ExecutiveChairCar &myClass) const {
    return DivyaangSubCategories<T>::sExecutiveChairCar;
}

template<typename T>
double DivyaangSubCategories<T> :: GetConcession(const BookingClass :: AC2Tier &myClass)  const{
    return DivyaangSubCategories<T>::sAC2Tier;
}

template<typename T>
double DivyaangSubCategories<T> :: GetConcession(const BookingClass :: FirstClass &myClass) const {
    return DivyaangSubCategories<T>::sFirstClass;
}

template<typename T>
double DivyaangSubCategories<T> :: GetConcession(const BookingClass :: AC3Tier &myClass)  const{
    return DivyaangSubCategories<T>::sAC3Tier;
}

template<typename T>
double DivyaangSubCategories<T> :: GetConcession(const BookingClass :: ACChairCar &myClass) const {
    return DivyaangSubCategories<T>::sACChairCar;
}

template<typename T>
double DivyaangSubCategories<T> :: GetConcession(const BookingClass :: Sleeper &myClass) const {
    return DivyaangSubCategories<T>::sSleeper;
}

template<typename T>
double DivyaangSubCategories<T> :: GetConcession(const BookingClass :: SecondSitting &myClass) const {
    return DivyaangSubCategories<T>::sSecondSitting;
}

template<typename T>
const string DivyaangSubCategories<T> :: GetName() const {
    return DivyaangSubCategories<T>::sName;
}

template<typename T>
void DivyaangSubCategories<T> :: UnitTest() {
    const DivyaangSubCategories<T>& d = Type();
    cout << d << '\n';

    if(d.GetName() != sName)
        cout << "Error in Get Name function\n";

    if(abs(d.GetConcession(BookingClass :: ACFirstClass :: Type()) - sACFirstClass) >= 1e-3)
        cout << "Error in Get Concession1!\n";
    if(abs(d.GetConcession(BookingClass :: AC2Tier :: Type()) - sAC2Tier) >= 1e-3)
        cout << "Error in Get Concession2!\n";
    if(abs(d.GetConcession(BookingClass :: AC3Tier :: Type()) - sAC3Tier) >= 1e-3)
        cout << "Error in Get Concession3!\n";
    if(abs(d.GetConcession(BookingClass :: Sleeper :: Type()) - sSleeper) >= 1e-3)
        cout << "Error in Get Concession4!\n";
    
    cout << "***TESTING FOR CLASS " << sName << " IS COMPLETE***\n";
}