/*
Name : Abhinandan De
Roll No: 19CS10069
*/

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <vector>
#include "Exceptions.h"

using namespace std;

// The "Date" class

class Date {
    const int date_, month_, year_;         // these are constants
    static const vector<string> smonthNames;      // for diplaying in mmm format...
    static const vector<int> sDays;               // the days of different months are stored
    Date(int d, int m, int y);              // private ctor

public:
    Date(const Date& d);            // cc tor is placed in public because a valid date has already been constructed!

    ~Date();

    static Date createDate(int date_, int month_, int year_);   // static method for creation of date

    bool operator!= (const Date& d) const;     // crucial for testing

    bool operator> (const Date& d) const;       // imp for booking validation

    static bool leapYear(int);          // feb 29 is a pain to handle

    static bool checkValid(int date, int month, int year);      // if a date is valid or not

    static int computeAge(const Date&, const Date&);           // used for computing age of a passenger on date of reservation

    static Date addOne(const Date& d);                          // for premium tatkal booking verification

    static void UnitTest();

    friend ostream& operator<<(ostream& os, const Date& d);     // stream operator
};
#endif // DATE_H