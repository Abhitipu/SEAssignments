/*
Name : Abhinandan De
Roll No: 19CS10069
*/

#include "Date.h"
#include<vector>
#include<string>

// #define __DEBUG


const vector<string> Date :: smonthNames = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};      // for better readability
const vector<int> Date :: sDays = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};                                         // declared consts naturally! 

Date :: Date(int d, int m, int y) : date_(d), month_(m), year_(y) { 
    // ctor
}

Date :: Date(const Date& d) : date_(d.date_), month_(d.month_), year_(d.year_) {
    // cctor
}

Date :: ~Date() {
    // dtor
}

Date Date :: createDate(int date, int month, int year) {
    if(Date :: checkValid(date, month, year)) {             // first validity is checked
        Date myDate = Date(date, month, year);              // creation only if valid
        #ifdef __DEBUG
            cout << "Created Date after successful validation\n";
        #endif
        return myDate;
    } else {
        throw Bad_Date();               // else exception is thrown
    }
}

bool Date :: checkValid(int day, int month, int year) {
    if(year > 2099 || year < 1900)              // according to the requirement
        return false;
    else if(month < 1 || month > 12)            // only 12 months in a year!
        return false;
    else if(day > 0 && day <= Date :: sDays[month-1]) {         // constraing on the day
        if(!(Date :: leapYear(year)) && (month == 2) && (day == 29)) {      // again the special case for leap year
            return false;
        } else
            return true;
    }
}

bool Date :: leapYear(int year) {               // the leapYear logic...
    if(year%4 != 0)
        return false;
    else if(year%100 == 0) {
        return (year%400 == 0);
    } else {
        return true;
    }
}

bool Date :: operator!=(const Date& d) const {                              // checking for equality (testing)
    return  date_ != d.date_ || month_ != d.month_ || year_ != d.year_;
}

int Date :: computeAge(const Date& d1, const Date& d2) {                // calculation of age
    // d1 <= d2 is checked...
    int age = d2.year_ - d1.year_;
    
    if(d1.month_ != d2.month_)
        age -= (d1.month_ > d2.month_);
    else
        age -= (d1.date_ > d2.date_);
    return age;
}

Date Date :: addOne(const Date& d) {            // premium tatkal and tatkal checker
    if(d.month_ == 2) {
        if(!leapYear(d.year_)) {                // only for non leap years and Feb 28th
            if(d.date_ == 28)
                return Date(1, 3, d.year_);
        }
    }

    if(d.date_ != sDays[d.month_-1]) {                  
        return Date(d.date_ + 1, d.month_, d.year_);        // just add 1
    } else {
        if(d.month_ != 12)                                  // not the last month
            return Date(1, d.month_+1, d.year_);            
        else
            return Date(1, 1, d.year_+1);                   // next year
    }
}

void Date :: UnitTest() {

    Date d1 = createDate(01, 01, 2001);         // it could have been directly created although
    Date d2 = createDate(2, 03, 2002);          // since it is in the scope of the class
    Date d3 = createDate(02, 3, 2002);          // but we are testing via the createPassenger method
    Date d4(d1);

    if(d4 != d1)
        cout << "Error in copy constructor or operator !=\n";       // it is a copy
    if(d3 != d2)
        cout << "Error in operator != \n";
    
    if(d1 > d2)
        cout << "Error in operator >\n";
    if(d4 > d1)
        cout << "Error in operator >\n";

    try {
        Date d4e = createDate(01, 01, 1890);
        cout << "Program reached an inconsistent state!\n";             // this will never be reached as exception will be thrown a priori!
    } catch(exception& e) {
        cout << "**Exception caught***: ";
        cout << e.what() << '\n';
    }

    try {
        Date d4e = createDate(01, 01, 2190);
        cout << "Program reached an inconsistent state!\n";             // this will never be reached as exception will be thrown a priori!
    } catch(exception& e) {
        cout << "**Exception caught***: ";
        cout << e.what() << '\n';
    }

    try {
        Date d4e = createDate(29, 02, 2003);
        cout << "Program reached an inconsistent state!\n";             // this will never be reached as exception will be thrown a priori!
    } catch(exception& e) {
        cout << "**Exception caught***: ";
        cout << e.what() << '\n';
    }

    try {
        Date d4e = createDate(31, 4, 2005);
        cout << "Program reached an inconsistent state!\n";             // this will never be reached as exception will be thrown a priori!
    } catch(exception& e) {
        cout << "**Exception caught***: ";
        cout << e.what() << '\n';
    }

    Date d5 = createDate(28, 2, 2004);
    Date d6 = createDate(29, 2, 2004);              // note that this is valid!
    Date d7 = createDate(1, 3, 2004);
    Date d8 = createDate(31, 12, 2013);
    Date d9 = createDate(1, 1, 2014);

    if(addOne(d5) != d6) {                              // testing the addOne function!
        cout << "Error in addOne";
    }
    if(addOne(d6) != d7) {
        cout << "Error in addOne";
    }
    if(!(addOne(d5) != d7)) {                           // This Should NOT be true!!
        cout << "Error in addOne";
    }
    if(addOne(d8) != d9) {
        cout << "Error in addOne";
    }

    if(computeAge(d5, d8) != 9)                         // checking the computeAge funciton!
        cout << "Error in compute age\n";
    if(computeAge(d7, d9) != 9)
        cout << "Error in computeAge\n";
    if(computeAge(d5, d5) != 0)
        cout << "Error in computeAge\n";
    
    cout << "****TESTING FOR DATE IS COMPLETE****\n";
}

bool Date :: operator> (const Date& other) const {
    bool ok = false;

    #ifdef __DEBUG
        cout << "Trying to compare:\n";
        cout << *this;
        cout << other;
    #endif

    if(other.year_ != year_)
        ok = year_ > other.year_;
    else if(other.month_ != month_)
        ok = month_ > other.month_;
    else
        ok = date_ > other.date_;

    #ifdef __DEBUG
        cout << "Compared dates successfully\n\n";
    #endif

    return ok;
}

ostream& operator<<(ostream& os, const Date& d) { 
    cout << d.date_ << " " << Date :: smonthNames[d.month_ - 1] << " " << d.year_ << '\n';
    return os; 
}