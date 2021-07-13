/*
Name : Abhinandan De
Roll No: 19CS10069
*/
#ifndef PASSENGER_H
#define PASSENGER_H
#include<iostream>
using namespace std;

#include "Date.h"

// Passenger which is a fully built class for extending design.
// It is not used in this project

class Passenger {
    const string name_, category_;       // strings are used for storing special characters
    string mobileNumber_;           
    const long long  aadharNumber_;
    const Date dob_;
    const bool isMale_;
public:
    Passenger(const string, const long long, const string, const string, Date, bool);
    static void UnitTest();
    virtual ~Passenger();
    friend ostream& operator<<(ostream&, const Passenger&);
};

#endif // PASSENGER_H