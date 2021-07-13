/*
Name : Abhinandan De
Roll No: 19CS10069
*/
#include<iostream>
using namespace std;

#include "BookingCategory.h"
// #define __DEBUG

BookingCategory :: BookingCategory() {

}

BookingCategory :: ~BookingCategory() {

}

void BookingCategory :: UnitTest() {
    const BookingCategory& b = LadiesCategory :: Type();

    cout << b;                  // testing the operator <<

    if(b.getName() != "Ladies Category")            // the getName test
        cout << "Error in GetName\n";

    const Date d1 = Date :: createDate(16, 3, 2001);
    const Date d2 = Date :: createDate(16, 3, 1950);
    const Date d3 = Date :: createDate(16, 3, 1956);
    const Date d4 = Date :: createDate(13, 04, 2001);

    const Passenger p1 = Passenger :: createPassenger("Abhinandan", "", "De", "134236789345", d1, Gender :: Male :: Type(), "8279728914");
    const Passenger p2 = Passenger :: createPassenger("Prabhat", "Kumar", "Hajra", "134236789345", d2, Gender :: Male :: Type(), "9412056328");
    const Passenger p3 = Passenger :: createPassenger("Mamata", "", "Hajra", "134236789345", d3, Gender :: Female :: Type(), "9921133112");
    const Passenger p4 = Passenger :: createPassenger("Ankita", "", "", "123456737123", d4, Gender :: Female :: Type());

    try {
        Station s1 = Station :: createStation("Kolkata");           
        Station s2 = Station :: createStation("Delhi");
        const Date& d2 = Date :: createDate(8, 4, 2021);
        const Date& d3 = Date :: createDate(9, 8, 2021);
        const Booking* b3 = b.createBooking(s1, s2, d2, d3, p3, BookingClass :: SecondSitting :: Type());       // for p3 // checking if polymorphic binding is done or not!
        const Booking* b4 = b.createBooking(s1, s2, d2, d3, p4, BookingClass :: ACFirstClass :: Type());            // for p4
        cout << "Booking successfully done!\n";
    } catch(exception& e) {
        cout << e.what() << '\n';
    }

    if(LadiesCategory :: IsEligible(p1, Date :: createDate(12, 3, 2021)))                // checking the IsEligible function     p1 is male // here d3 is the reservation date!!
        cout << "Error in eligibility criteria\n";

    try {
        Station s1 = Station :: createStation("Kolkata");           
        Station s2 = Station :: createStation("Delhi");
        const Date& d2 = Date :: createDate(8, 4, 2021);
        const Date& d3 = Date :: createDate(9, 8, 2021);
        const Booking* b3 = b.createBooking(s1, s2, d2, d3, p2, BookingClass :: Sleeper :: Type());     // p2 is also male!
        cout << "Erroneous booking created\n";                  // flow doesnt come here
    } catch(exception& e) {
        cout << "***Exception caught!***\n";
        cout << e.what() << '\n';
    }
    cout << "***TESTING FOR BOOKINGCATEGORY IS DONE****\n";
}

ostream& operator<< (ostream& os, const BookingCategory& b) {
    os << b.getName() << '\n';
    return os;
}

GeneralCategory :: GeneralCategory(const string& name) : name_(name) {

}

GeneralCategory :: GeneralCategory(const GeneralCategory& other) {
    // copy constructor with no implementation
}

GeneralCategory :: ~GeneralCategory() {

}

const GeneralCategory& GeneralCategory :: Type() {
    static const GeneralCategory gCat("General Category");
    return gCat;
}

bool GeneralCategory :: IsEligible(const Passenger& p, const Date& d) {
    return true;
}

const Booking* GeneralCategory :: createBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, 
                        const Date& dateOfReservation, const Passenger& p, const BookingClass& bClass) const{

    if(IsEligible(p, dateOfReservation)) {
        const Booking* b = new GeneralBooking(fromStation, toStation, dateOfBooking, dateOfReservation, p, bClass);
        #ifdef __DEBUG
            cout << "Successfully verified and created General Booking\n";
        #endif
        return b;
    }
    else
        throw Inconsistent_Booking_Category();
}

void GeneralCategory :: UnitTest() {
    const GeneralCategory& b = GeneralCategory :: Type();           // here created object is also of the same type

    cout << b;                  // testing the operator <<

    if(b.getName() != "General Category")            // the getName test
        cout << "Error in GetName\n";

    const Date d1 = Date :: createDate(16, 3, 2001);
    const Date d2 = Date :: createDate(16, 3, 1950);
    const Date d3 = Date :: createDate(16, 3, 1956);
    const Date d4 = Date :: createDate(13, 04, 2001);

    const Passenger p1 = Passenger :: createPassenger("Abhinandan", "", "De", "134236789345", d1, Gender :: Male :: Type(), "8279728914");
    const Passenger p2 = Passenger :: createPassenger("Prabhat", "Kumar", "Hajra", "134236789345", d2, Gender :: Male :: Type(), "9412056328");
    const Passenger p3 = Passenger :: createPassenger("Mamata", "", "Hajra", "134236789345", d3, Gender :: Female :: Type(), "9921133112");
    const Passenger p4 = Passenger :: createPassenger("Ankita", "", "", "123456737123", d4, Gender :: Female :: Type());

    try {
        Station s1 = Station :: createStation("Chennai");           
        Station s2 = Station :: createStation("Delhi");
        const Date& d2 = Date :: createDate(8, 4, 2021);
        const Date& d3 = Date :: createDate(9, 8, 2021);
        const Booking* b3 = b.createBooking(s1, s2, d2, d3, p1, BookingClass :: ACFirstClass :: Type());       // for p1
        const Booking* b4 = b.createBooking(s1, s2, d2, d3, p4, BookingClass :: ACFirstClass :: Type());            // for p4
        cout << "Booking successfully done!\n";
    } catch(exception& e) {
        cout << "Error in booking!\n";
        cout << e.what() << '\n';
    }

    if(!IsEligible(p1, Date :: createDate(12, 3, 2021)))                // always eligible!
        cout << "Error in eligibility criteria\n";

    try {
        Station s1 = Station :: createStation("Kolkata");           
        Station s2 = Station :: createStation("Delhi");
        const Date& d2 = Date :: createDate(8, 4, 2021);
        const Date& d3 = Date :: createDate(9, 8, 2021);
        const Booking* b3 = b.createBooking(s1, s2, d2, d3, p2, BookingClass :: Sleeper :: Type());     // p2 is also male!
        cout << "Booking Successfully done\n";                  // flow doesnt come here
    } catch(exception& e) {
        cout << "***Error in booking!***\n";                // here the flow should never each, since once the basic things are validated, only the bookingCategory needs validation!
        cout << e.what() << '\n';
    }

    cout << "***TESTING FOR GENERAL CATEGORY IS DONE****\n";
}

const string& GeneralCategory :: getName() const { 
    return name_;
}

LadiesCategory :: LadiesCategory(const string& name): name_(name) {

}

LadiesCategory :: ~LadiesCategory() {

}

LadiesCategory :: LadiesCategory(const LadiesCategory& other) {
    // cctor has no implementation
}

const LadiesCategory& LadiesCategory :: Type() {
    static const LadiesCategory lCat("Ladies Category");
    return lCat;
}

bool LadiesCategory :: IsEligible(const Passenger& p, const Date& d) {
    if(!(Gender :: IsMale(p.getGender())))
        return true;
    else
        return Date :: computeAge(p.getDateOfBirth(), d) <= 12;             // 12 year old boys also get this!
}

const Booking* LadiesCategory :: createBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, 
                        const Date& dateOfReservation, const Passenger& p, const BookingClass& bClass) const{
    if(IsEligible(p, dateOfReservation)) {
        const Booking* b = new LadiesBooking(fromStation, toStation, dateOfBooking, dateOfReservation, p, bClass);
        #ifdef __DEBUG
            cout << "Successfully verified and created Ladies Booking\n";
        #endif
        return b;
    }
    else
        throw Inconsistent_Booking_Category();
}

void LadiesCategory :: UnitTest() {
    const LadiesCategory& b = LadiesCategory :: Type();

    cout << b;                  // testing the operator <<

    if(b.getName() != "Ladies Category")            // the getName test
        cout << "Error in GetName\n";

    const Date d1 = Date :: createDate(16, 3, 2001);
    const Date d2 = Date :: createDate(16, 3, 1950);
    const Date d3 = Date :: createDate(16, 3, 1956);
    const Date d4 = Date :: createDate(13, 04, 2001);

    const Passenger p1 = Passenger :: createPassenger("Abhinandan", "", "De", "134236789345", d1, Gender :: Male :: Type(), "8279728914");
    const Passenger p2 = Passenger :: createPassenger("Prabhat", "Kumar", "Hajra", "134236789345", d2, Gender :: Male :: Type(), "9412056328");
    const Passenger p3 = Passenger :: createPassenger("Mamata", "", "Hajra", "134236789345", d3, Gender :: Female :: Type(), "9921133112");
    const Passenger p4 = Passenger :: createPassenger("Ankita", "", "", "123456737123", d4, Gender :: Female :: Type());

    try {
        Station s1 = Station :: createStation("Bangalore");           
        Station s2 = Station :: createStation("Delhi");
        const Date& d2 = Date :: createDate(8, 4, 2021);
        const Date& d3 = Date :: createDate(9, 8, 2021);
        const Booking* b3 = b.createBooking(s1, s2, d2, d3, p3, BookingClass :: FirstClass :: Type());       // for p3
        const Booking* b4 = b.createBooking(s1, s2, d2, d3, p4, BookingClass :: ACFirstClass :: Type());            // for p4
        cout << "Booking successfully done!\n";
    } catch(exception& e) {
        cout << "Error in booking\n";
        cout << e.what() << '\n';
    }

    if(!LadiesCategory :: IsEligible(p1, Date :: createDate(12, 3, 2010)))         // MALES less than 12 years of age are also eligible!
        cout << "Error in eligibility criteria\n";

    try {
        Station s1 = Station :: createStation("Kolkata");           
        Station s2 = Station :: createStation("Delhi");
        const Date& d2 = Date :: createDate(8, 4, 2021);
        const Date& d3 = Date :: createDate(9, 8, 2021);
        const Booking* b3 = b.createBooking(s1, s2, d2, d3, p2, BookingClass :: Sleeper :: Type());     // p2 is also male!
        cout << "Erroneous booking created\n";                  // flow doesnt come here
    } catch(exception& e) {
        cout << "***Exception caught!***\n";
        cout << e.what() << '\n';
    }
    cout << "***TESTING FOR LADIES CATEGORY IS DONE****\n";
}

const string& LadiesCategory :: getName() const {
    return name_;
}

SeniorCitizenCategory :: SeniorCitizenCategory(const string& name): name_(name) {

}

SeniorCitizenCategory :: SeniorCitizenCategory(const SeniorCitizenCategory& other) {
    // cctor with no implementation
}

SeniorCitizenCategory :: ~SeniorCitizenCategory() {

}

const SeniorCitizenCategory& SeniorCitizenCategory :: Type() {
    static const SeniorCitizenCategory scCat("Senior Citizens Category");
    return scCat;
}
bool SeniorCitizenCategory :: IsEligible(const Passenger& p, const Date& d) {
    if(Gender :: IsMale(p.getGender())) {
        return Date :: computeAge(p.getDateOfBirth(), d) >= 60;
    } else {
        return Date :: computeAge(p.getDateOfBirth(), d) >= 58;
    }
}

const Booking* SeniorCitizenCategory :: createBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, 
                        const Date& dateOfReservation, const Passenger& p, const BookingClass& bClass) const {
    if(IsEligible(p, dateOfReservation)) {
        const Booking* b = new SeniorCitizensBooking(fromStation, toStation, dateOfBooking, dateOfReservation, p, bClass);
        #ifdef __DEBUG
            cout << "Successfully verified and created Senior Citizens Booking\n";
        #endif
        return b;
    }
    else
        throw Inconsistent_Booking_Category();
}

void SeniorCitizenCategory :: UnitTest() {
    const SeniorCitizenCategory& b = SeniorCitizenCategory :: Type();

    cout << b;                  // testing the operator <<

    if(b.getName() != "Senior Citizens Category")            // the getName test
        cout << "Error in GetName\n";

    const Date d1 = Date :: createDate(16, 3, 2001);
    const Date d2 = Date :: createDate(16, 3, 1950);            //  for senior citzen
    const Date d3 = Date :: createDate(16, 3, 1956);            // "" "" "" 
    const Date d4 = Date :: createDate(13, 04, 2001);

    const Passenger p1 = Passenger :: createPassenger("Abhinandan", "", "De", "134236789345", d1, Gender :: Male :: Type(), "8279728914");
    const Passenger p2 = Passenger :: createPassenger("Prabhat", "Kumar", "Hajra", "134236789345", d2, Gender :: Male :: Type(), "9412056328");
    const Passenger p3 = Passenger :: createPassenger("Mamata", "", "Hajra", "134236789345", d3, Gender :: Female :: Type(), "9921133112");
    const Passenger p4 = Passenger :: createPassenger("Ankita", "", "", "123456737123", d4, Gender :: Female :: Type());

    try {
        Station s1 = Station :: createStation("Bangalore");           
        Station s2 = Station :: createStation("Delhi");
        const Date& d2 = Date :: createDate(8, 4, 2021);
        const Date& d3 = Date :: createDate(9, 8, 2021);
        const Booking* b3 = b.createBooking(s1, s2, d2, d3, p2, BookingClass :: FirstClass :: Type());       // for p2
        const Booking* b4 = b.createBooking(s1, s2, d2, d3, p3, BookingClass :: ACFirstClass :: Type());            // for p3
        cout << "Booking successfully done!\n";
    } catch(exception& e) {
        cout << "Error in booking\n";
        cout << e.what() << '\n';
    }

    if(!SeniorCitizenCategory :: IsEligible(p2, Date :: createDate(12, 3, 2010)))         // Positive
        cout << "Error in eligibility criteria\n";

    if(SeniorCitizenCategory :: IsEligible(p1, Date :: createDate(12, 3, 2010)))         // Negative
        cout << "Error in eligibility criteria\n";

    try {
        Station s1 = Station :: createStation("Kolkata");           
        Station s2 = Station :: createStation("Chennai");
        const Date& d2 = Date :: createDate(8, 4, 2021);
        const Date& d3 = Date :: createDate(9, 8, 2021);
        const Booking* b3 = b.createBooking(s1, s2, d2, d3, p1, BookingClass :: ACFirstClass :: Type());     // p2 is also male!
        cout << "Erroneous booking created\n";                  // flow doesnt come here
    } catch(exception& e) {
        cout << "***Exception caught!***\n";
        cout << e.what() << '\n';
    }
    cout << "***TESTING FOR SENIOR CITIZEN CATEGORY IS DONE****\n";
}

const string& SeniorCitizenCategory :: getName() const { 
    return name_;
}

DivyaangCategory :: DivyaangCategory(const string& name): name_(name) {

}

DivyaangCategory :: ~DivyaangCategory() {

}

DivyaangCategory :: DivyaangCategory(const DivyaangCategory& other) {
    // cctor with no implementation
}

const DivyaangCategory& DivyaangCategory :: Type() {
    static const DivyaangCategory dCat("Divyaang Category");
    return dCat;
}

bool DivyaangCategory :: IsEligible(const Passenger& p, const Date& d) {
    return (p.getDivyaangId() != "NA");
}

const Booking* DivyaangCategory :: createBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, 
                        const Date& dateOfReservation, const Passenger& p, const BookingClass& bClass) const{
    if(IsEligible(p, dateOfReservation)) {
        const Booking* b = new DivyaangBooking(fromStation, toStation, dateOfBooking, dateOfReservation, p, bClass);
        #ifdef __DEBUG
            cout << "Successfully verified and created Divyaang Booking\n";
        #endif
        return b;
    }
    else
        throw Inconsistent_Booking_Category();
}

void DivyaangCategory :: UnitTest() {
    const DivyaangCategory& b = DivyaangCategory :: Type();

    cout << b;                  // testing the operator <<

    if(b.getName() != "Divyaang Category")            // the getName test
        cout << "Error in GetName\n";

    const Date d1 = Date :: createDate(16, 3, 2001);
    const Date d2 = Date :: createDate(16, 3, 1950);
    const Date d3 = Date :: createDate(16, 3, 1956);
    const Date d4 = Date :: createDate(13, 04, 2001);

    const Passenger p1 = Passenger :: createPassenger("Abhinandan", "", "De", "134236789345", d1, Gender :: Male :: Type(), "8279728914", "D12344", 1);     // divyaang
    const Passenger p2 = Passenger :: createPassenger("Prabhat", "Kumar", "Hajra", "134236789345", d2, Gender :: Male :: Type(), "9412056328");
    const Passenger p3 = Passenger :: createPassenger("Mamata", "", "Hajra", "134236789345", d3, Gender :: Female :: Type(), "9921133112");
    const Passenger p4 = Passenger :: createPassenger("Ankita", "", "", "123456737123", d4, Gender :: Female :: Type(), "8922234567", "d566ygv", 3);        // divyaang

    try {
        Station s1 = Station :: createStation("Kolkata");           
        Station s2 = Station :: createStation("Delhi");
        const Date& d2 = Date :: createDate(8, 4, 2021);
        const Date& d3 = Date :: createDate(9, 8, 2021);
        const Booking* b3 = b.createBooking(s1, s2, d2, d3, p1, BookingClass :: FirstClass :: Type());       // for p1
        const Booking* b4 = b.createBooking(s1, s2, d2, d3, p4, BookingClass :: ACFirstClass :: Type());            // for p4
        cout << "Booking successfully done!\n";
    } catch(exception& e) {
        cout << "Error in booking\n";
        cout << e.what() << '\n';
    }

    if(DivyaangCategory :: IsEligible(p2, Date :: createDate(12, 3, 2010)))         // Should not be eligible!
        cout << "Error in eligibility criteria\n";

    try {
        Station s1 = Station :: createStation("Kolkata");           
        Station s2 = Station :: createStation("Delhi");
        const Date& d2 = Date :: createDate(8, 4, 2021);
        const Date& d3 = Date :: createDate(9, 8, 2021);
        const Booking* b3 = b.createBooking(s1, s2, d2, d3, p3, BookingClass :: Sleeper :: Type());     // p2 is not divyaang
        cout << "Erroneous booking created\n";                  // flow doesnt come here
    } catch(exception& e) {
        cout << "***Exception caught!***\n";
        cout << e.what() << '\n';
    }
    cout << "***TESTING FOR DIVYAANG CATEGORY IS DONE****\n";
}

const string& DivyaangCategory :: getName() const { 
    return name_;
}

TatkalCategory :: TatkalCategory(const string& name): name_(name) { 

}

TatkalCategory :: ~TatkalCategory() { 

}

TatkalCategory :: TatkalCategory(const TatkalCategory& other) { 
    // cctor with no implementation
}

const TatkalCategory& TatkalCategory :: Type() {
    static const TatkalCategory tCat("Tatkal Category");
    return tCat;
}

bool TatkalCategory :: IsEligible(const Date& dateOfBooking, const Date& dateOfReservation) {
    const Date& check = Date :: addOne(dateOfBooking);
    return !(check != dateOfReservation);
}

const Booking* TatkalCategory :: createBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, 
                        const Date& dateOfReservation, const Passenger& p, const BookingClass& bClass) const{
    if(IsEligible(dateOfBooking, dateOfReservation)) {
        const Booking* b = new TatkalBooking(fromStation, toStation, dateOfBooking, dateOfReservation, p, bClass);
        #ifdef __DEBUG
            cout << "Successfully verified and created Tatkal Booking\n";
        #endif
        return b;
    }
    else
        throw Inconsistent_Booking_Category();
}

void TatkalCategory :: UnitTest() {
    const TatkalCategory& b = TatkalCategory :: Type();

    cout << b;                  // testing the operator <<

    if(b.getName() != "Tatkal Category")            // the getName test
        cout << "Error in GetName\n";

    const Date d1 = Date :: createDate(16, 3, 2001);
    const Date d2 = Date :: createDate(16, 3, 1950);

    const Passenger p1 = Passenger :: createPassenger("Abhinandan", "", "De", "134236789345", d1, Gender :: Male :: Type(), "8279728914");
    const Passenger p2 = Passenger :: createPassenger("Prabhat", "Kumar", "Hajra", "134236789345", d2, Gender :: Male :: Type(), "9412056328");

    try {
        Station s1 = Station :: createStation("Bangalore");           
        Station s2 = Station :: createStation("Delhi");
        const Date& d2 = Date :: createDate(8, 4, 2021);
        const Date& d3 = Date :: createDate(9, 4, 2021);
        const Booking* b4 = b.createBooking(s1, s2, d2, d3, p1, BookingClass :: ACFirstClass :: Type());            // for p1
        cout << "Booking successfully done!\n";
    } catch(exception& e) {
        cout << "Error in booking\n";
        cout << e.what() << '\n';
    }

    if(!TatkalCategory :: IsEligible(Date :: createDate(11, 3, 2010), Date :: createDate(12, 3, 2010)))         // Should be eligible // 1 day!!
        cout << "Error in eligibility criteria\n";

    try {
        Station s1 = Station :: createStation("Kolkata");           
        Station s2 = Station :: createStation("Delhi");
        const Date& d2 = Date :: createDate(8, 4, 2021);
        const Date& d3 = Date :: createDate(9, 8, 2021);            // not within 1 day!!
        const Booking* b3 = b.createBooking(s1, s2, d2, d3, p2, BookingClass :: Sleeper :: Type());
        cout << "Erroneous booking created\n";                  // flow doesnt come here
    } catch(exception& e) {
        cout << "***Exception caught!***\n";
        cout << e.what() << '\n';
    }
    cout << "***TESTING FOR TATKAL CATEGORY IS DONE****\n";
}

const string& TatkalCategory :: getName() const { 
    return name_;
}

PremiumTatkalCategory :: PremiumTatkalCategory(const string& name): name_(name) { 

}

PremiumTatkalCategory :: ~PremiumTatkalCategory() { 

}

PremiumTatkalCategory :: PremiumTatkalCategory(const PremiumTatkalCategory& other) { 
    // cctor with no implementation
}

const PremiumTatkalCategory& PremiumTatkalCategory :: Type() {
    static const PremiumTatkalCategory ptCat("Premium Tatkal Category");
    return ptCat;
}

bool PremiumTatkalCategory :: IsEligible(const Date& dateOfBooking, const Date& dateOfReservation) {
    const Date& check = Date :: addOne(dateOfBooking);
    return !(check != dateOfReservation);
}

const Booking* PremiumTatkalCategory :: createBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, 
                        const Date& dateOfReservation, const Passenger& p, const BookingClass& bClass) const {
    if(IsEligible(dateOfBooking, dateOfReservation)) {
        const Booking* b = new PremiumTatkalBooking(fromStation, toStation, dateOfBooking, dateOfReservation, p, bClass);
        #ifdef __DEBUG
            cout << "Successfully verified and created Premium Tatkal Booking\n";
        #endif
        return b;
    }
    else
        throw Inconsistent_Booking_Category();
}

void PremiumTatkalCategory :: UnitTest() {
    const PremiumTatkalCategory& b = PremiumTatkalCategory :: Type();

    cout << b;                  // testing the operator <<

    if(b.getName() != "Premium Tatkal Category")            // the getName test
        cout << "Error in GetName\n";

    const Date d1 = Date :: createDate(16, 3, 2001);
    const Date d2 = Date :: createDate(16, 3, 1950);

    const Passenger p1 = Passenger :: createPassenger("Abhinandan", "", "De", "134236789345", d1, Gender :: Male :: Type(), "8279728914");
    const Passenger p2 = Passenger :: createPassenger("Prabhat", "Kumar", "Hajra", "134236789345", d2, Gender :: Male :: Type(), "9412056328");

    try {
        Station s1 = Station :: createStation("Bangalore");           
        Station s2 = Station :: createStation("Delhi");
        const Date& d2 = Date :: createDate(8, 4, 2021);
        const Date& d3 = Date :: createDate(9, 4, 2021);
        const Booking* b4 = b.createBooking(s1, s2, d2, d3, p1, BookingClass :: ACFirstClass :: Type());            // for p1
        cout << "Booking successfully done!\n";
    } catch(exception& e) {
        cout << "Error in booking\n";
        cout << e.what() << '\n';
    }

    if(!TatkalCategory :: IsEligible(Date :: createDate(11, 3, 2010), Date :: createDate(12, 3, 2010)))         // Should be eligible // 1 day!!
        cout << "Error in eligibility criteria\n";

    try {
        Station s1 = Station :: createStation("Kolkata");           
        Station s2 = Station :: createStation("Delhi");
        const Date& d2 = Date :: createDate(8, 4, 2021);
        const Date& d3 = Date :: createDate(9, 8, 2021);            // not within 1 day!!
        const Booking* b3 = b.createBooking(s1, s2, d2, d3, p2, BookingClass :: Sleeper :: Type());
        cout << "Erroneous booking created\n";                  // flow doesnt come here
    } catch(exception& e) {
        cout << "***Exception caught!***\n";
        cout << e.what() << '\n';
    }
    cout << "***TESTING FOR PREMIUM TATKAL CATEGORY IS DONE****\n";
}

const string& PremiumTatkalCategory :: getName() const { 
    return name_;
}