/*
Name : Abhinandan De
Roll No: 19CS10069
*/
#include "Date.h"
#include<vector>
#include<string>


vector<string> Date :: monthNames = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

Date :: Date(int d, int m, int y) : date_(d), month_(m), year_(y) {

}

Date :: Date(const Date& d) : date_(d.date_), month_(d.month_), year_(d.year_) {

}

bool Date :: operator!=(const Date& d) const{                               // this is required in testing
    return  date_ != d.date_ || month_ != d.month_ || year_ != d.year_;
}

Date :: ~Date() {

}

void Date :: UnitTest() {

    Date d1(01, 01, 2001);
    Date d2(2, 03, 2002);
    Date d3(02, 3, 2002);
    Date d4(d1);

    if(d4 != d1)
        cout << "Error in copy constructor or operator !=\n";
    if(d3 != d2)
        cout << "Error in operator != \n";
    
    cout << d1;         // stream operator
    cout << d2;
}

ostream& operator<<(ostream& os, const Date& d) { 
    cout << d.date_ << "/" << Date :: monthNames[d.month_ - 1] << "/" << d.year_ << '\n';
    return os; 
}