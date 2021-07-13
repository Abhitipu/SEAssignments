/*
Name : Abhinandan De
Roll No: 19CS10069
*/
#ifndef PASSENGER_H
#define PASSENGER_H
#include<iostream>
using namespace std;

#include "Date.h"
#include "Gender.h"
#include "Exceptions.h"

// Convention for disability index:
// 0: No disability (DEFAULT VALUE).
// 1: Blind
// 2: Orthopaedically Handicaped
// 3: Cancer Patient
// 4: TB Patient

// Maybe include the type() ??

class Passenger {
    const string firstname_, middlename_, lastname_;       // strings are used for storing special characters
    const string aadharNumber_;                             // notice the use of consts in the appropriate places!
    const Date dateOfBirth_;
    const Gender& gender_;
    string mobileNumber_;
    const string divyaangId_;
    const int disabilityIndex_;
    Passenger(const string& firstname, const string& middlename, const string& lastname, const string& aadharnumber, const Date dob, const Gender& gender, string mobileNumber, const string& divyaangId, const int disabilityIndex);

public:
    Passenger(const Passenger& p);
    ~Passenger();
    static void Validate(const string& firstname, const string& middlename,const string& lastname,const string& aadharNumber,const Date& dob, const Gender& gender, const string mobileNumber,const string& divyaangId,const int disabilityIndex);
    static Passenger createPassenger(const string& firstname, const string& middlename, const string& lastname, const string& aadharNumber, const Date& dob, const Gender& gender, string mobileNumber = "NA", string divyaangId = "NA", int disabilityIndex = 0);
    const string getDivyaangId () const;
    const int getDisabilityIndex () const;                      // some get methods have been added here!
    const Date& getDateOfBirth () const;
    const Gender& getGender() const;
    static void UnitTest();
    friend ostream& operator<<(ostream&, const Passenger&);
};

#endif // PASSENGER_H