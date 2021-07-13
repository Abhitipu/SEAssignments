/*
Name : Abhinandan De
Roll No: 19CS10069
*/
#ifndef RAILWAYS_H
#define RAILWAYS_H

#include<string>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

#include "Station.h"

class Railways {

    static vector<Station> sStations;                           // the required private attributes
    static map<pair<string, string>, double> sDistStations; 

    Railways();

    ~Railways();

    Railways(Railways& r);          // declared in private to avoid copy construction/ copy assignment

    Railways& operator=(Railways& r);
    
public:

    static const Railways& Type();

    static void UnitTest();

    double GetDistance(const Station& s1, const Station& s2) const;
    
    friend ostream& operator<< (ostream& os, const Railways& r);
};

#endif 