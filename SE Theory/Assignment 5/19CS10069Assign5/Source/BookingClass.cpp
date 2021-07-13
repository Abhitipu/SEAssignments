/*
Name : Abhinandan De
Roll No: 19CS10069
*/

#include<iostream>
#include "BookingClass.h"
#include<vector>
#include<map>
#include<cmath>

// #define __DEBUG
// comment this out while running

using namespace std;

// forward declaration of templates!

template class BookingClasses<BookingClass :: ACFirstClass_>;
template class BookingClasses<BookingClass :: ExecutiveChairCar_>;
template class BookingClasses<BookingClass :: AC2Tier_>;
template class BookingClasses<BookingClass :: AC3Tier_>;
template class BookingClasses<BookingClass :: FirstClass_>;
template class BookingClasses<BookingClass :: ACChairCar_>;
template class BookingClasses<BookingClass :: Sleeper_>;
template class BookingClasses<BookingClass :: SecondSitting_>;

// todo : complete all definitions and complete the method definitions

template<> const bool BookingClass :: ACFirstClass :: sIsAC = true;
template<> const bool BookingClass :: ExecutiveChairCar :: sIsAC = true;
template<> const bool BookingClass :: AC2Tier :: sIsAC = true;
template<> const bool BookingClass :: AC3Tier :: sIsAC = true;
template<> const bool BookingClass :: FirstClass :: sIsAC = false;
template<> const bool BookingClass :: ACChairCar :: sIsAC = true;
template<> const bool BookingClass :: Sleeper :: sIsAC = false;
template<> const bool BookingClass :: SecondSitting :: sIsAC = false;

template<> const int BookingClass :: ACFirstClass :: sNoOfTiers = 2;
template<> const int BookingClass :: ExecutiveChairCar :: sNoOfTiers = 0;
template<> const int BookingClass :: AC2Tier :: sNoOfTiers = 2;
template<> const int BookingClass :: AC3Tier :: sNoOfTiers = 3;
template<> const int BookingClass :: FirstClass :: sNoOfTiers = 2;
template<> const int BookingClass :: ACChairCar :: sNoOfTiers = 0;
template<> const int BookingClass :: Sleeper :: sNoOfTiers = 3;
template<> const int BookingClass :: SecondSitting :: sNoOfTiers = 3;

template<> const bool BookingClass:: ACFirstClass :: sIsSitting = false;
template<> const bool BookingClass:: ExecutiveChairCar :: sIsSitting = true;
template<> const bool BookingClass:: AC2Tier :: sIsSitting = false;
template<> const bool BookingClass:: AC3Tier :: sIsSitting = false;
template<> const bool BookingClass:: FirstClass :: sIsSitting = false;
template<> const bool BookingClass:: ACChairCar :: sIsSitting = true;
template<> const bool BookingClass:: Sleeper :: sIsSitting = false;
template<> const bool BookingClass:: SecondSitting :: sIsSitting = true;

template<> double BookingClass :: ACFirstClass :: sLoadFactor = 6.50;
template<> double BookingClass :: ExecutiveChairCar :: sLoadFactor = 5.00;
template<> double BookingClass :: AC2Tier :: sLoadFactor = 4.00;
template<> double BookingClass :: FirstClass :: sLoadFactor = 3.00;
template<> double BookingClass :: AC3Tier :: sLoadFactor = 2.50;
template<> double BookingClass :: ACChairCar :: sLoadFactor = 2.00;
template<> double BookingClass :: Sleeper :: sLoadFactor = 1.00;
template<> double BookingClass :: SecondSitting :: sLoadFactor = 0.60;

template<> bool BookingClass :: ACFirstClass :: sIsLuxury = true;
template<> bool BookingClass :: ExecutiveChairCar :: sIsLuxury = true;
template<> bool BookingClass :: AC2Tier :: sIsLuxury = false;
template<> bool BookingClass :: FirstClass :: sIsLuxury = true;
template<> bool BookingClass :: AC3Tier :: sIsLuxury = false;
template<> bool BookingClass :: ACChairCar :: sIsLuxury = false;
template<> bool BookingClass :: Sleeper :: sIsLuxury = false;
template<> bool BookingClass :: SecondSitting :: sIsLuxury = false;

template<> const string& BookingClass :: ACFirstClass :: sName = "AC First Class";
template<> const string& BookingClass :: ExecutiveChairCar :: sName = "Executive Chair Car";
template<> const string& BookingClass :: AC2Tier :: sName = "AC 2 Tier";
template<> const string& BookingClass :: FirstClass :: sName = "First Class";
template<> const string& BookingClass :: AC3Tier :: sName = "AC 3 Tier";
template<> const string& BookingClass :: ACChairCar :: sName = "AC Chair Car";
template<> const string& BookingClass :: Sleeper :: sName = "Sleeper";
template<> const string& BookingClass :: SecondSitting :: sName = "Second Sitting";

template<> double BookingClass :: ACFirstClass :: sReservationCharges = 60.00;
template<> double BookingClass :: ExecutiveChairCar :: sReservationCharges = 60.00;
template<> double BookingClass :: AC2Tier :: sReservationCharges = 50.00;
template<> double BookingClass :: FirstClass :: sReservationCharges = 50.00;
template<> double BookingClass :: AC3Tier :: sReservationCharges = 40.00;
template<> double BookingClass :: ACChairCar :: sReservationCharges = 40.00;
template<> double BookingClass :: Sleeper :: sReservationCharges = 20.00;
template<> double BookingClass :: SecondSitting :: sReservationCharges = 15.00;

template<> double BookingClass :: ACFirstClass :: sMinTatkalCharges = 400.00;
template<> double BookingClass :: ExecutiveChairCar :: sMinTatkalCharges = 400.00;
template<> double BookingClass :: AC2Tier :: sMinTatkalCharges = 400.00;
template<> double BookingClass :: FirstClass :: sMinTatkalCharges = 400.00;
template<> double BookingClass :: AC3Tier :: sMinTatkalCharges = 300.00;
template<> double BookingClass :: ACChairCar :: sMinTatkalCharges = 125.00;
template<> double BookingClass :: Sleeper :: sMinTatkalCharges = 100.00;
template<> double BookingClass :: SecondSitting :: sMinTatkalCharges = 10.00;

template<> double BookingClass :: ACFirstClass :: sMaxTatkalCharges = 500.00;
template<> double BookingClass :: ExecutiveChairCar :: sMaxTatkalCharges = 500.00;
template<> double BookingClass :: AC2Tier :: sMaxTatkalCharges = 500.00;
template<> double BookingClass :: FirstClass :: sMaxTatkalCharges = 500.00;
template<> double BookingClass :: AC3Tier :: sMaxTatkalCharges = 400.00;
template<> double BookingClass :: ACChairCar :: sMaxTatkalCharges = 225.00;
template<> double BookingClass :: Sleeper :: sMaxTatkalCharges = 200.00;
template<> double BookingClass :: SecondSitting :: sMaxTatkalCharges = 15.00;

template<> double BookingClass :: ACFirstClass :: sMinDistanceForCharge = 500.0;
template<> double BookingClass :: ExecutiveChairCar :: sMinDistanceForCharge = 250.0;
template<> double BookingClass :: AC2Tier :: sMinDistanceForCharge = 500.0;
template<> double BookingClass :: FirstClass :: sMinDistanceForCharge = 500.0;
template<> double BookingClass :: AC3Tier :: sMinDistanceForCharge = 500.0;
template<> double BookingClass :: ACChairCar :: sMinDistanceForCharge = 250.0;
template<> double BookingClass :: Sleeper :: sMinDistanceForCharge = 500.0;
template<> double BookingClass :: SecondSitting :: sMinDistanceForCharge = 100.0;

template<> double BookingClass :: ACFirstClass :: sTatkalLoad = 0.30;
template<> double BookingClass :: ExecutiveChairCar :: sTatkalLoad = 0.30;
template<> double BookingClass :: AC2Tier :: sTatkalLoad = 0.30;
template<> double BookingClass :: AC3Tier :: sTatkalLoad = 0.30;
template<> double BookingClass :: FirstClass :: sTatkalLoad = 0.30;
template<> double BookingClass :: ACChairCar :: sTatkalLoad = 0.30;
template<> double BookingClass :: Sleeper :: sTatkalLoad = 0.30;
template<> double BookingClass :: SecondSitting :: sTatkalLoad = 0.10;


BookingClass :: BookingClass() {
    // ctor
}

BookingClass :: ~BookingClass() {
    // dtor
}

void BookingClass :: UnitTest() {
    const BookingClass& b = BookingClass :: SecondSitting :: Type();            // meyers singleton
    cout << b;                                      // operator <<

    if(abs(b.GetReservationCharges() - 15.0) >= 1e-3)
        cout << "Error in GetReservationCharges\n";
    if(abs(b.GetLoadFactor() - 0.60) >= 1e-3)
        cout << "Error in GetLoadFactor\n";
    if(!b.IsSitting())
        cout << "Error in Getting sit/sleep info\n";
    if(b.GetNumberOfTiers() != 3)
        cout << "Error in No of tiers\n";
    if(b.GetName() != "Second Sitting")
        cout << "Error in get reservation charges\n";
    if(b.IsAC())
        cout << "Error in get AC Info\n";
    if(b.IsLuxury())
        cout << "Error in Luxury\n";
    if(abs(b.GetMinDistanceForCharge() - 100.0) >= 1e-3)
        cout << "Error in GetMinDistanceForCharge\n";
    if(abs(b.GetMaxTatkalCharges() - 15.00) >= 1e-3)
        cout << "Error in GetMaxTatkalCharges\n";
    if(abs(b.GetMinTatkalCharges() - 10.00) >= 1e-3)
        cout << "Error in GetMinTatkalCharges\n";
    if(abs(b.GetTatkalLoad() - 0.1) >= 1e-3)
        cout << "Error in GetTatkalLoad\n";
    if(abs(b.GetPremiumTatkalLoad() - 0.2) >= 1e-3)
        cout << "Error in GetPremiumTatkalLoad\n";

    SecondSitting :: changeLuxury(true);
    if(!b.IsLuxury())
        cout << "Error in changing Luxury\n";
    SecondSitting :: changeLuxury(false);

    SecondSitting :: changeLoadFactor(0.70);
    if(abs(b.GetLoadFactor() - 0.70) >= 1e-3)
        cout << "Error in changeLoadFactor\n";
    SecondSitting :: changeLoadFactor(0.6);

    SecondSitting :: changeReservationCharges(20.00);
    if(abs(b.GetReservationCharges() - 20.0) >= 1e-3)
        cout << "Error in changeReservationCharges\n";
    SecondSitting :: changeReservationCharges(15.00); 

    SecondSitting :: changeTatkalLoad(0.2);
    if(abs(b.GetTatkalLoad() - 0.2) >= 1e-3)
        cout << "Error in change TatkalLoad\n";
    SecondSitting :: changeTatkalLoad(0.1);

    SecondSitting :: changeMinTatkalCharge(20.00);
    if(abs(b.GetMinTatkalCharges() - 20.00) >= 1e-3)
        cout << "Error in GetMinTatkalCharges\n";
    SecondSitting :: changeMinTatkalCharge(10.00);

    SecondSitting :: changeMaxTatkalCharge(20.00);
    if(abs(b.GetMaxTatkalCharges() - 20.00) >= 1e-3)
        cout << "Error in changeMaxTatkalCharge\n";
    SecondSitting :: changeMaxTatkalCharge(15.00);

    cout << "****TESTING FOR BOOKINGCLASS IS COMPLETE****\n";
}

ostream& operator<< (ostream& os, const BookingClass& b) {
    os << b.GetName() << '\n';
    os << ": AC: " << ((b.IsAC()) ? "YES\n" : "NO\n");
    os << ": Bunks: " << b.GetNumberOfTiers() << '\n';
    os << ": Luxury: " << ((b.IsLuxury()) ? "YES\n" : "NO\n");

#ifdef __DEBUG    
    os << ": Reservation Charges: " << (b.GetReservationCharges()) << '\n';
    os << ": Sitting: " << ((b.IsSitting()) ? "YES\n" : "NO\n");
    os << ": Luxury: " << ((b.IsLuxury()) ? "YES\n" : "NO\n");
    os << ": Load Factor: " << (b.GetLoadFactor()) << '\n';
    os << ": Min Tatkal Charges: " << (b.GetMinTatkalCharges()) << '\n';
    os << ": Max tatkal charges: " << (b.GetMaxTatkalCharges()) << '\n';
    os << ": Minimum distance for charge: " << (b.GetMinDistanceForCharge()) << '\n';
    os << ": Tatkal load Factor: " << (b.GetTatkalLoad()) << '\n';
    os << ": Premium Tatkal load Factor: " << (b.GetPremiumTatkalLoad()) << '\n';
#endif  // __DEBUG
}

template<typename T>
BookingClasses<T> :: BookingClasses() {

}

template<typename T>
BookingClasses<T> :: BookingClasses(const BookingClasses<T>& b) {

}

template<typename T>
BookingClasses<T>& BookingClasses<T> :: operator=(const BookingClasses<T>& b) {

}

template<typename T>
BookingClasses<T> :: ~BookingClasses() {

}

template<typename T>
const BookingClasses<T>& BookingClasses<T> :: Type() {                    // returns the only instance!
    static const BookingClasses<T> myBookingClass;
    return myBookingClass;
}

template<typename T>
void BookingClasses<T> :: changeLuxury(bool newLuxury) {          //  since it is being changed for all instances
    BookingClasses<T>::sIsLuxury = newLuxury;
}

template<typename T>
void BookingClasses<T> :: changeLoadFactor(double newLoadFactor) {
    BookingClasses<T>::sLoadFactor = newLoadFactor;
}

template<typename T>
void BookingClasses<T> :: changeReservationCharges(double newCharges) {
    BookingClasses<T>::sReservationCharges = newCharges;
}

template<typename T>
void BookingClasses<T> :: changeMinTatkalCharge(double newCharge) {
    BookingClasses<T>::sMinTatkalCharges = newCharge;
}

template<typename T>
void BookingClasses<T> :: changeMaxTatkalCharge(double newCharge) {
    BookingClasses<T>::sMaxTatkalCharges = newCharge;
}

template<typename T>
void BookingClasses<T> :: changeMinDistanceForCharge(double newDistance) {
    BookingClasses<T>::sMinDistanceForCharge = newDistance;
}

template<typename T>
void BookingClasses<T> :: changeTatkalLoad(double newTatkalLoad) {
    BookingClasses<T>::sTatkalLoad = newTatkalLoad;
}

template<typename T>
double BookingClasses<T> :: GetReservationCharges() const {
    return BookingClasses<T>::sReservationCharges;
}

template<typename T>
double BookingClasses<T> :: GetLoadFactor() const {
    return BookingClasses<T>::sLoadFactor;
}

template<typename T>
bool BookingClasses<T> :: IsSitting() const {
    return BookingClasses<T>::sIsSitting;
}       

template<typename T>
int BookingClasses<T> :: GetNumberOfTiers() const {
    return BookingClasses<T>::sNoOfTiers;
}

template<typename T>
string BookingClasses<T> :: GetName() const {
    return BookingClasses<T>::sName;
}

template<typename T>
bool BookingClasses<T> :: IsAC() const {
    return BookingClasses<T>::sIsAC;
}

template<typename T>
bool BookingClasses<T> :: IsLuxury() const {
    return BookingClasses<T>::sIsLuxury;
}

template<typename T>
double BookingClasses<T> :: GetTatkalLoad() const {
    return BookingClasses<T>::sTatkalLoad;
}

template<typename T>
double BookingClasses<T> :: GetPremiumTatkalLoad() const {
    return 2.0*BookingClasses<T>::sTatkalLoad;
}

template<typename T>
double BookingClasses<T> :: GetMinDistanceForCharge() const {
    return BookingClasses<T>::sMinDistanceForCharge;
}

template<typename T>
double BookingClasses<T> :: GetMinTatkalCharges() const {
    return BookingClasses<T>::sMinTatkalCharges;
}

template<typename T>
double BookingClasses<T> :: GetMaxTatkalCharges() const {
    return BookingClasses<T>::sMaxTatkalCharges;
}

template<typename T>
void BookingClasses<T> :: UnitTest() {
    const BookingClasses<T>& b = Type();            // meyers singleton
    cout << b;                                      // operator <<

    if(abs(b.GetReservationCharges() - sReservationCharges) >= 1e-3)            // checking the get methods
        cout << "Error in GetReservationCharges\n";
    if(abs(b.GetLoadFactor() - sLoadFactor) >= 1e-3)
        cout << "Error in GetLoadFactor\n";
    if(b.IsSitting() != sIsSitting)
        cout << "Error in Getting sit/sleep info\n";
    if(b.GetNumberOfTiers() != sNoOfTiers)
        cout << "Error in No of tiers\n";
    if(b.GetName() != sName)
        cout << "Error in get reservation charges\n";
    if(b.IsAC() != sIsAC)
        cout << "Error in get AC Info\n";
    if(b.IsLuxury() != sIsLuxury)
        cout << "Error in Luxury\n";
    if(abs(b.GetMinDistanceForCharge() - sMinDistanceForCharge) >= 1e-3)
        cout << "Error in GetMinDistanceForCharge\n";
    if(abs(b.GetMaxTatkalCharges() - sMaxTatkalCharges) >= 1e-3)
        cout << "Error in GetMaxTatkalCharges\n";
    if(abs(b.GetMinTatkalCharges() - sMinTatkalCharges) >= 1e-3)
        cout << "Error in GetMinTatkalCharges\n";
    if(abs(b.GetTatkalLoad() - sTatkalLoad) >= 1e-3)
        cout << "Error in GetTatkalLoad\n";
    if(abs(b.GetPremiumTatkalLoad() - 2*sTatkalLoad) >= 1e-3)
        cout << "Error in GetPremiumTatkalLoad\n";

    bool prev = sIsLuxury;
    BookingClasses<T> :: changeLuxury(true);                        // changing checking and resetting!
    if(!b.IsLuxury())
        cout << "Error in changing Luxury\n";
    BookingClasses<T> :: changeLuxury(prev);

    double prev1 = sLoadFactor;
    BookingClasses<T> :: changeLoadFactor(0.70);
    if(abs(b.GetLoadFactor() - 0.70) >= 1e-3)
        cout << "Error in changeLoadFactor\n";
    BookingClasses<T> :: changeLoadFactor(prev1);

    double prev2 = sReservationCharges;
    BookingClasses<T> :: changeReservationCharges(20.00);
    if(abs(b.GetReservationCharges() - 20.0) >= 1e-3)
        cout << "Error in changeReservationCharges\n";
    BookingClasses<T> :: changeReservationCharges(prev2); 

    double prev3 = sTatkalLoad;
    BookingClasses<T> :: changeTatkalLoad(0.2);
    if(abs(b.GetTatkalLoad() - 0.2) >= 1e-3)
        cout << "Error in change TatkalLoad\n";
    BookingClasses<T> :: changeTatkalLoad(prev3);

    double prev4 = sMinTatkalCharges;
    BookingClasses<T> :: changeMinTatkalCharge(20.00);
    if(abs(b.GetMinTatkalCharges() - 20.00) >= 1e-3)
        cout << "Error in GetMinTatkalCharges\n";
    BookingClasses<T> :: changeMinTatkalCharge(prev4);

    double prev5 = sMaxTatkalCharges;
    BookingClasses<T> :: changeMaxTatkalCharge(20.00);
    if(abs(b.GetMaxTatkalCharges() - 20.00) >= 1e-3)
        cout << "Error in changeMaxTatkalCharge\n";
    BookingClasses<T> :: changeMaxTatkalCharge(prev5);

    cout << "****TESTING FOR " << sName << " IS COMPLETE****\n";
}