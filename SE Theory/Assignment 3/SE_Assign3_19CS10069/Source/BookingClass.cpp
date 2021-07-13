/*
Name : Abhinandan De
Roll No: 19CS10069
*/

#include<iostream>
#include "BookingClass.h"
#include<vector>
#include<map>
#include<cmath>

using namespace std;

BookingClass :: BookingClass(const double loadFactor): loadFactor_(loadFactor) {
       
}

BookingClass :: ~BookingClass() {

}

double BookingClass :: GetLoadFactor() const {
    return loadFactor_;
}

void BookingClass :: UnitTest() {
    const BookingClass& bClass = ACChairCar :: Type();

    cout << bClass;             // stream operator

    const double error = 1e-6;

    // checking for polymorphism

    if(abs(bClass.GetLoadFactor() - 1.25) >= error || abs(bClass.loadFactor_-1.25) >= error)
        cout << "Error in storing load factor\n";
    
    if(!bClass.IsSitting())
        cout << "Wrong information regarding seat/sleep\n";
    
    if(bClass.GetNumberOfTiers() != 0)
        cout << "Wrong information regarding no. of tiers\n";
    
    if(bClass.IsLuxury())
        cout << "Wrong information regarding luxury\n";
    
    if(bClass.GetName() != "AC Chair Car")
        cout << "Wrong name stored\n";
    
    if(!bClass.IsAC())
        cout << "Wrong information regarding availability of Air Conditioning\n";
    
}

ostream& operator<< (ostream& os,const BookingClass& b) {
    os << "Travel Class: " << b.GetName() << '\n';
    os << "  : Mode: " << ((b.IsSitting()) ? "Sitting" : "Sleeping") << '\n';
    os << "  : Comfort: " << ((b.IsAC()) ? "AC" : "Non-AC") << '\n';
    os << "  : Bunks: " << b.GetNumberOfTiers() << '\n';
    os << "  : Luxury: " << ((b.IsLuxury()) ? "Yes" : "No") << '\n'; 
    os << '\n';
    return os;
}

/************************************************************************************************************************/

Sitting :: Sitting(const double loadFactor):BookingClass(loadFactor) {

}

Sitting :: ~Sitting() {

}

bool Sitting :: IsSitting() const {
    return true;
}

int Sitting :: GetNumberOfTiers() const{
    return 0;
}

void Sitting :: UnitTest() {
    const Sitting& bClass = SecondSitting :: Type();

    cout << bClass;             // stream operator

    // checking for polymorphism
    const double error = 1e-6;

    if(abs(bClass.GetLoadFactor() - 0.5) >= error || abs(bClass.loadFactor_-0.5) >= error)
        cout << "Error in storing load factor\n";
    
    if(!bClass.IsSitting())
        cout << "Wrong information regarding seat/sleep\n";
    
    if(bClass.GetNumberOfTiers() != 0)
        cout << "Wrong information regarding no. of tiers\n";
    
    if(bClass.IsLuxury())
        cout << "Wrong information regarding luxury\n";
    
    if(bClass.GetName() != "Second Sitting")
        cout << "Wrong name stored\n";
    
    if(bClass.IsAC())
        cout << "Wrong information regarding availability of Air Conditioning\n";
}

/************************************************************************************************************************/

double ACChairCar :: sMyLoadFactor = 1.25;

bool ACChairCar :: sMyLuxury = false;

ACChairCar :: ACChairCar(): Sitting(sMyLoadFactor){

}

ACChairCar :: ~ACChairCar() { 

}

const ACChairCar& ACChairCar :: Type() {
    static const ACChairCar ACChairCar_;
    return ACChairCar_; 
}

void ACChairCar :: ChangeLuxury(bool newLuxury) {
    sMyLuxury = newLuxury;
}

void ACChairCar :: ChangeLoadFactor(double newLoadFactor) {
    sMyLoadFactor = newLoadFactor;
}

string ACChairCar :: GetName() const {
    return string("AC Chair Car");
}

bool ACChairCar :: IsAC() const {
    return true;
}

bool ACChairCar :: IsLuxury() const {
    return sMyLuxury;
}

string ACChairCar :: remarks() const {
    return string("AC chairs");
}

double ACChairCar :: GetLoadFactor() const {
    return sMyLoadFactor;
}

void ACChairCar :: UnitTest()  {
    const ACChairCar& bClass = ACChairCar :: Type();

    cout << bClass;             // stream operator

    const double error = 1e-4;

    // checking for polymorphism

    if(abs(bClass.GetLoadFactor() - 1.25) >= error || abs(bClass.loadFactor_-1.25) >= error)
        cout << "Error in storing load factor\n";
    
    if(!bClass.IsSitting())
        cout << "Wrong information regarding seat/sleep\n";
    
    if(bClass.GetNumberOfTiers() != 0)
        cout << "Wrong information regarding no. of tiers\n";
    
    if(bClass.IsLuxury())
        cout << "Wrong information regarding luxury\n";
    
    if(bClass.GetName() != "AC Chair Car")
        cout << "Wrong name stored\n";
    
    if(!bClass.IsAC())
        cout << "Wrong information regarding availability of Air Conditioning\n";
    

    ACChairCar :: ChangeLoadFactor(1.35);
    ACChairCar :: ChangeLuxury(true);

    if(!bClass.IsLuxury())
        cout << "Couldn't apply changes to luxury\n";
    else
        ACChairCar :: ChangeLuxury(false);
    
    if(abs(bClass.GetLoadFactor()-1.35) >= error)
        cout << "Couldn't apply changes to load factor\n";
    else
        ACChairCar :: ChangeLoadFactor(1.25);
}

/************************************************************************************************************************/

double SecondSitting :: sMyLoadFactor = 0.5;

bool SecondSitting :: sMyLuxury = false;


SecondSitting :: SecondSitting():Sitting(sMyLoadFactor) {
    sMyLoadFactor = 0.5;
    sMyLuxury = false;
}

SecondSitting :: ~SecondSitting() {

}

const SecondSitting& SecondSitting :: Type() {
    static const SecondSitting SecondSitting_;
    return SecondSitting_; 
}

void SecondSitting :: ChangeLoadFactor(double newLoadFactor) {
    sMyLoadFactor = newLoadFactor;
}

void SecondSitting :: ChangeLuxury(bool newLuxury) {
    sMyLuxury = newLuxury;
}

string SecondSitting :: GetName() const {
    return string("Second Sitting");
}

bool SecondSitting :: IsAC() const {
    return false;
}

bool SecondSitting :: IsLuxury() const {
    return sMyLuxury;
}

string SecondSitting :: remarks() const {
    return string("Bench seating");
}

void SecondSitting :: UnitTest()  {
    const SecondSitting& bClass = SecondSitting :: Type();

    cout << bClass;             // stream operator

    const double error = 1e-6;

    // checking for polymorphism

    if(abs(bClass.GetLoadFactor() - 0.5) >= error || abs(bClass.loadFactor_-0.5) >= error)
        cout << "Error in storing load factor\n";
    
    if(!bClass.IsSitting())
        cout << "Wrong information regarding seat/sleep\n";
    
    if(bClass.GetNumberOfTiers() != 0)
        cout << "Wrong information regarding no. of tiers\n";
    
    if(bClass.IsLuxury())
        cout << "Wrong information regarding luxury\n";
    
    if(bClass.GetName() != "Second Sitting")
        cout << "Wrong name stored\n";
    
    if(bClass.IsAC())
        cout << "Wrong information regarding availability of Air Conditioning\n";
    

    SecondSitting :: ChangeLoadFactor(1.35);
    SecondSitting :: ChangeLuxury(true);

    if(!bClass.IsLuxury())
        cout << "Couldn't apply changes to luxury\n";
    else
        SecondSitting :: ChangeLuxury(false);
    
    if(abs(bClass.GetLoadFactor()-1.35) >= error)
        cout << "Couldn't apply changes to load factor\n";
    else
        SecondSitting :: ChangeLoadFactor(1.35);
}

double SecondSitting :: GetLoadFactor() const {
    return sMyLoadFactor;
}

/************************************************************************************************************************/

Sleeping :: Sleeping(const double loadFactor):BookingClass(loadFactor) {
        
}


Sleeping :: ~Sleeping() {

}

bool Sleeping :: IsSitting() const { 
    return false;
}

void Sleeping :: UnitTest()  {
    const Sleeping& bClass = FirstClass :: Type();

    cout << bClass;             // stream operator

    const double error = 1e-6;

    // checking for polymorphism

    if(abs(bClass.GetLoadFactor() - 2.00) >= error || abs(bClass.loadFactor_-2.00) >= error)
        cout << "Error in storing load factor\n";
    
    if(bClass.IsSitting())
        cout << "Wrong information regarding seat/sleep\n";
    
    if(bClass.GetNumberOfTiers() != 2)
        cout << "Wrong information regarding no. of tiers\n";
    
    if(!bClass.IsLuxury())
        cout << "Wrong information regarding luxury\n";
    
    if(bClass.GetName() != "First Class")
        cout << "Wrong name stored\n";
    
    if(bClass.IsAC())
        cout << "Wrong information regarding availability of Air Conditioning\n";
    

    FirstClass :: ChangeLoadFactor(2.35);
    FirstClass :: ChangeLuxury(false);

    if(bClass.IsLuxury())
        cout << "Couldn't apply changes to luxury\n";
    else
        FirstClass :: ChangeLuxury(true);
    
    if(abs(bClass.GetLoadFactor()-2.35) >= error)
        cout << "Couldn't apply changes to load factor\n";
    else
        FirstClass :: ChangeLoadFactor(2.00);
}

/************************************************************************************************************************/

ThreeTier :: ThreeTier(const double loadFactor):Sleeping(loadFactor) {

}

ThreeTier :: ~ThreeTier() {

}

int ThreeTier :: GetNumberOfTiers() const{
    return 3;
}

void ThreeTier :: UnitTest()  {
    const ThreeTier& bClass = AC3Tier :: Type();

    cout << bClass;             // stream operator

    const double error = 1e-6;

    // checking for polymorphism

    if(abs(bClass.GetLoadFactor() - 1.75) >= error || abs(bClass.loadFactor_-1.75) >= error)
        cout << "Error in storing load factor\n";
    
    if(bClass.IsSitting())
        cout << "Wrong information regarding seat/sleep\n";
    
    if(bClass.GetNumberOfTiers() != 3)
        cout << "Wrong information regarding no. of tiers\n";
    
    if(bClass.IsLuxury())
        cout << "Wrong information regarding luxury\n";
    
    if(bClass.GetName() != "AC Three Tier")
        cout << "Wrong name stored\n";
    
    if(!bClass.IsAC())
        cout << "Wrong information regarding availability of Air Conditioning\n";
    

    AC3Tier :: ChangeLoadFactor(1.65);
    AC3Tier :: ChangeLuxury(true);

    if(!bClass.IsLuxury())
        cout << "Couldn't apply changes to luxury\n";
    else
        AC3Tier :: ChangeLuxury(false);
    
    if(abs(bClass.GetLoadFactor()-1.65) >= error)
        cout << "Couldn't apply changes to load factor\n";
    else
        AC3Tier :: ChangeLoadFactor(1.75);
}

/************************************************************************************************************************/

double Sleeper :: sMyLoadFactor = 1.00;

bool Sleeper :: sMyLuxury = false;

Sleeper :: Sleeper():ThreeTier(sMyLoadFactor) {

}

Sleeper :: ~Sleeper() {

}

const Sleeper& Sleeper :: Type() {
    static const Sleeper Sleeper_;
    return Sleeper_; 
}

void Sleeper :: ChangeLoadFactor(double newLoadFactor) {
    sMyLoadFactor = newLoadFactor;
}

void Sleeper :: ChangeLuxury(bool newLuxury) {
    sMyLuxury = newLuxury;
}

string Sleeper :: GetName() const {
    return string("Sleeper");
}

bool Sleeper :: IsAC() const {
    return false;
}

bool Sleeper :: IsLuxury() const {
    return sMyLuxury;
}

string Sleeper :: remarks() const {
    return string("Non-AC 3 berths inside, 2 berths on side");
}


double Sleeper :: GetLoadFactor() const {
    return sMyLoadFactor;
}

void Sleeper :: UnitTest()  {
    const Sleeper& bClass = Sleeper :: Type();

    cout << bClass;             // stream operator

    const double error = 1e-6;

    // checking for polymorphism

    if(abs(bClass.GetLoadFactor() - 1.00) >= error || abs(bClass.loadFactor_-1.00) >= error)
        cout << "Error in storing load factor\n";
    
    if(bClass.IsSitting())
        cout << "Wrong information regarding seat/sleep\n";
    
    if(bClass.GetNumberOfTiers() != 3)
        cout << "Wrong information regarding no. of tiers\n";
    
    if(bClass.IsLuxury())
        cout << "Wrong information regarding luxury\n";
    
    if(bClass.GetName() != "Sleeper")
        cout << "Wrong name stored\n";
    
    if(bClass.IsAC())
        cout << "Wrong information regarding availability of Air Conditioning\n";
    

    ChangeLoadFactor(1.1);
    ChangeLuxury(true);

    if(!bClass.IsLuxury())
        cout << "Couldn't apply changes to luxury\n";
    else
        ChangeLuxury(false);
    
    if(abs(bClass.GetLoadFactor()-1.1) >= error)
        cout << "Couldn't apply changes to load factor\n";
    else
        ChangeLoadFactor(1.00);
}

/************************************************************************************************************************/

double AC3Tier :: sMyLoadFactor = 1.75;

bool AC3Tier :: sMyLuxury = false;

AC3Tier :: AC3Tier():ThreeTier(sMyLoadFactor) {
    
}

AC3Tier :: ~AC3Tier() {

}

const AC3Tier& AC3Tier :: Type() {
    static const AC3Tier AC3Tier_;
    return AC3Tier_; 
}

void AC3Tier :: ChangeLoadFactor(double newLoadFactor) {
    sMyLoadFactor = newLoadFactor;
}

void AC3Tier :: ChangeLuxury(bool newLuxury) {
    sMyLuxury = newLuxury;
}

string AC3Tier :: GetName() const {
    return string("AC Three Tier");
}

bool AC3Tier :: IsAC() const {
    return true;
}

bool AC3Tier :: IsLuxury() const {
    return sMyLuxury;
}

string AC3Tier :: remarks() const {
    return string("AC 3 berths inside, 2 berths on side");
}


double AC3Tier :: GetLoadFactor() const {
    return sMyLoadFactor;
}

void AC3Tier :: UnitTest()  {
    const AC3Tier& bClass = AC3Tier :: Type();

    cout << bClass;             // stream operator

    const double error = 1e-6;

    // checking for polymorphism

    if(abs(bClass.GetLoadFactor() - 1.75) >= error || abs(bClass.loadFactor_-1.75) >= error)
        cout << "Error in storing load factor\n";
    
    if(bClass.IsSitting())
        cout << "Wrong information regarding seat/sleep\n";
    
    if(bClass.GetNumberOfTiers() != 3)
        cout << "Wrong information regarding no. of tiers\n";
    
    if(bClass.IsLuxury())
        cout << "Wrong information regarding luxury\n";
    
    if(bClass.GetName() != "AC Three Tier")
        cout << "Wrong name stored\n";
    
    if(!bClass.IsAC())
        cout << "Wrong information regarding availability of Air Conditioning\n";
    

    ChangeLoadFactor(1.67);
    ChangeLuxury(true);

    if(!bClass.IsLuxury())
        cout << "Couldn't apply changes to luxury\n";
    else
        ChangeLuxury(false);
    
    if(abs(bClass.GetLoadFactor()-1.67) >= error)
        cout << "Couldn't apply changes to load factor\n";
    else
        ChangeLoadFactor(1.75);
}

/************************************************************************************************************************/

TwoTier :: TwoTier(const double loadFactor):Sleeping(loadFactor) {

}

TwoTier :: ~TwoTier() {

}

int TwoTier :: GetNumberOfTiers() const{
    return 2;
}

void TwoTier :: UnitTest() {
    const TwoTier& bClass = ACFirstClass :: Type();

    cout << bClass;             // stream operator

    const double error = 1e-6;

    // checking for polymorphism

    if(abs(bClass.GetLoadFactor() - 3.00) >= error || abs(bClass.loadFactor_-3.00) >= error)
        cout << "Error in storing load factor\n";
    
    if(bClass.IsSitting())
        cout << "Wrong information regarding seat/sleep\n";
    
    if(bClass.GetNumberOfTiers() != 2)
        cout << "Wrong information regarding no. of tiers\n";
    
    if(!bClass.IsLuxury())
        cout << "Wrong information regarding luxury\n";
    
    if(bClass.GetName() != "AC First Class")
        cout << "Wrong name stored\n";
    
    if(!bClass.IsAC())
        cout << "Wrong information regarding availability of Air Conditioning\n";
    

    ACFirstClass :: ChangeLoadFactor(2.65);
    ACFirstClass :: ChangeLuxury(false);

    if(bClass.IsLuxury())
        cout << "Couldn't apply changes to luxury\n";
    else
        ACFirstClass :: ChangeLuxury(true);
    
    if(abs(bClass.GetLoadFactor()-2.65) >= error)
        cout << "Couldn't apply changes to load factor\n";
    else
        ACFirstClass :: ChangeLoadFactor(3.00);
}

/************************************************************************************************************************/

double ACFirstClass :: sMyLoadFactor = 3.00;

bool ACFirstClass :: sMyLuxury = true;

ACFirstClass :: ACFirstClass():TwoTier(sMyLoadFactor) {
    
}

ACFirstClass ::  ~ACFirstClass() {

}

const ACFirstClass& ACFirstClass :: Type() {
    static const ACFirstClass ACFirstClass_;
    return ACFirstClass_;
}
void ACFirstClass :: ChangeLoadFactor(double newLoadFactor) {
    sMyLoadFactor = newLoadFactor;
}

void ACFirstClass :: ChangeLuxury(bool newLuxury) {
    sMyLuxury = newLuxury;
}

string ACFirstClass :: GetName() const {
    return string("AC First Class");
}

bool ACFirstClass :: IsAC() const {
    return true;
}

bool ACFirstClass :: IsLuxury() const {
    return sMyLuxury;
}

string ACFirstClass :: remarks() const {
    return string("AC 2 berth coupe");
}

double ACFirstClass :: GetLoadFactor() const {
    return sMyLoadFactor;
}

void ACFirstClass :: UnitTest()  {
    const ACFirstClass& bClass = ACFirstClass :: Type();

    cout << bClass;             // stream operator

    const double error = 1e-6;

    // checking for polymorphism

    if(abs(bClass.GetLoadFactor() - 3.00) >= error || abs(bClass.loadFactor_-3.00) >= error)
        cout << "Error in storing load factor\n";
    
    if(bClass.IsSitting())
        cout << "Wrong information regarding seat/sleep\n";
    
    if(bClass.GetNumberOfTiers() != 2)
        cout << "Wrong information regarding no. of tiers\n";
    
    if(!bClass.IsLuxury())
        cout << "Wrong information regarding luxury\n";
    
    if(bClass.GetName() != "AC First Class")
        cout << "Wrong name stored\n";
    
    if(!bClass.IsAC())
        cout << "Wrong information regarding availability of Air Conditioning\n";
    

    ChangeLoadFactor(2.75);
    ChangeLuxury(false);

    if(bClass.IsLuxury())
        cout << "Couldn't apply changes to luxury\n";
    else
        ChangeLuxury(true);
    
    if(abs(bClass.GetLoadFactor()-2.75) >= error)
        cout << "Couldn't apply changes to load factor\n";
    else
        ChangeLoadFactor(3.00);
}

/************************************************************************************************************************/

double AC2Tier :: sMyLoadFactor = 2.00;

bool AC2Tier :: sMyLuxury = false;

AC2Tier :: AC2Tier():TwoTier(sMyLoadFactor) {
    
}

AC2Tier :: ~AC2Tier() {

}

const AC2Tier& AC2Tier :: Type() {
    static const AC2Tier AC2Tier_;
    return AC2Tier_;
}

void AC2Tier :: ChangeLoadFactor(double newLoadFactor) {
    sMyLoadFactor = newLoadFactor;
}

void AC2Tier :: ChangeLuxury(bool newLuxury) {
    sMyLuxury = newLuxury;
}

string AC2Tier :: GetName() const {
    return string("AC Two Tier");
}

bool AC2Tier :: IsAC() const {
    return true;
}

bool AC2Tier :: IsLuxury() const {
    return sMyLuxury;
}

string AC2Tier :: remarks() const {
    return string("AC 2 berths inside, 2 berths on side");
}

double AC2Tier :: GetLoadFactor() const {
    return sMyLoadFactor;
}

void AC2Tier :: UnitTest()  {
    const AC2Tier& bClass = AC2Tier :: Type();

    cout << bClass;             // stream operator

    const double error = 1e-6;

    // checking for polymorphism

    if(abs(bClass.GetLoadFactor() - 2.00) >= error || abs(bClass.loadFactor_-2.00) >= error)
        cout << "Error in storing load factor\n";
    
    if(bClass.IsSitting())
        cout << "Wrong information regarding seat/sleep\n";
    
    if(bClass.GetNumberOfTiers() != 2)
        cout << "Wrong information regarding no. of tiers\n";
    
    if(bClass.IsLuxury())
        cout << "Wrong information regarding luxury\n";
    
    if(bClass.GetName() != "AC Two Tier")
        cout << "Wrong name stored\n";
    
    if(!bClass.IsAC())
        cout << "Wrong information regarding availability of Air Conditioning\n";
    

    ChangeLoadFactor(2.75);
    ChangeLuxury(true);

    if(!bClass.IsLuxury())
        cout << "Couldn't apply changes to luxury\n";
    else
        ChangeLuxury(false);
    
    if(abs(bClass.GetLoadFactor()-2.75) >= error)
        cout << "Couldn't apply changes to load factor\n";
    else
        ChangeLoadFactor(2.00);
}


/************************************************************************************************************************/

double FirstClass :: sMyLoadFactor = 2.00;

bool FirstClass :: sMyLuxury = true;

FirstClass :: FirstClass():TwoTier(sMyLoadFactor) {
    
}

FirstClass :: ~FirstClass() {

}

const FirstClass& FirstClass :: Type() {
    static const FirstClass FirstClass_;
    return FirstClass_;
}
void FirstClass :: ChangeLoadFactor(double newLoadFactor) {
    sMyLoadFactor = newLoadFactor;
}

void FirstClass :: ChangeLuxury(bool newLuxury) {
    sMyLuxury = newLuxury;
}

string FirstClass :: GetName() const {
    return string("First Class");
}

bool FirstClass :: IsAC() const {
    return false;
}

bool FirstClass :: IsLuxury() const {
    return sMyLuxury;
}

double FirstClass :: GetLoadFactor() const {
    return sMyLoadFactor;
}

string FirstClass :: remarks() const {
    return string("Non-AC 2 berth coupe");
}

void FirstClass :: UnitTest()  {
    const FirstClass& bClass = FirstClass :: Type();

    cout << bClass;             // stream operator

    const double error = 1e-6;

    // checking for polymorphism

    if(abs(bClass.GetLoadFactor() - 2.00) >= error || abs(bClass.loadFactor_-2.00) >= error)
        cout << "Error in storing load factor\n";
    
    if(bClass.IsSitting())
        cout << "Wrong information regarding seat/sleep\n";
    
    if(bClass.GetNumberOfTiers() != 2)
        cout << "Wrong information regarding no. of tiers\n";
    
    if(!bClass.IsLuxury())
        cout << "Wrong information regarding luxury\n";
    
    if(bClass.GetName() != "First Class")
        cout << "Wrong name stored\n";
    
    if(bClass.IsAC())
        cout << "Wrong information regarding availability of Air Conditioning\n";
    

    ChangeLoadFactor(2.15);
    ChangeLuxury(false);

    if(bClass.IsLuxury())
        cout << "Couldn't apply changes to luxury\n";
    else
        ChangeLuxury(true);
    
    if(abs(bClass.GetLoadFactor()-2.15) >= error)
        cout << "Couldn't apply changes to load factor\n";
    else
        ChangeLoadFactor(3.00);
}

/************************************************************************************************************************/