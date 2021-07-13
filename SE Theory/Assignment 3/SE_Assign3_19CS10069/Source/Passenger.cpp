/*
Name : Abhinandan De
Roll No: 19CS10069
*/
#include<iostream>
#include "Passenger.h"
// Passenger which is a fully built class for extending design.
// It is not used in this project

Passenger :: Passenger(const string name, const long long aadharNumber, const string mobileNumber, const string category, Date dob, bool isMale): 
    name_(name), aadharNumber_(aadharNumber), mobileNumber_(mobileNumber), category_(category), dob_(dob), isMale_(isMale)  {

}

Passenger :: ~Passenger() {

}

void Passenger :: UnitTest() {
    Passenger p("Abhinandan", 12332312123123123, "+91229439024", "General", Date(16, 03, 2001), true);
    Passenger p1("Asmita", 12413546356457457, "+911398498173", "General", Date(24, 11, 2000), false);

    if(p.aadharNumber_ != 12332312123123123 || p.mobileNumber_ != "+91229439024" || p.dob_ != Date(16, 03, 2001) || !p.isMale_)
        cout << "Error in constructor\n";
    
    cout << p << '\n';
    cout << p1 << '\n';
}

ostream& operator<<(ostream&os, const Passenger& p) {
    os << "Name: " << p.name_ << '\n';
    os << "Aadhar number: " << p.aadharNumber_ << '\n';
    os << "Mobile number: " << p.mobileNumber_ << '\n';
    os << "Date of birth: " << p.dob_;
    os << "Gender: " << ((p.isMale_) ? "Male" : "Female") << '\n'; 
    return os;
}