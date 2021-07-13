/*
Name : Abhinandan De
Roll No: 19CS10069
*/
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <vector>
using namespace std;

class Date {
    const int date_, month_, year_;         // these are constants
    static vector<string> monthNames;
    
public:
    Date(int d, int m, int y);

    Date(const Date& d);
    
    bool operator!= (const Date& d) const;     // crucial for testing

    static void UnitTest();

    ~Date();
    
    friend ostream& operator<<(ostream& os, const Date& d);
};
#endif // DATE_H