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
    Station(const string&);
public:
    static Station createStation(const string& name, bool verified = false);            // a static function for creating stations after validation
    Station(const Station&);                                            // cctor (no need to check for validity here!)
    const string GetName() const;                                       // for getting the name
    double GetDistance(const Station&) const;                           // checking the distances between stations!
    ~Station();         
    static void UnitTest();         
    friend ostream& operator<< (ostream&,const Station&);
};

#endif  // STATION_H