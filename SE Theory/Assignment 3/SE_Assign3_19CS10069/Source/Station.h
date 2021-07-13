/*
Name : Abhinandan De
Roll No: 19CS10069
*/
#ifndef STATION_H
#define STATION_H

#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Station {   
    const string name_;         // as it cant change
public:
    Station(const string&);
    Station(const Station&);
    string GetName() const;
    double GetDistance(const Station&) const;
    ~Station();
    friend ostream& operator<< (ostream&,const Station&);
};

#endif  // STATION_H