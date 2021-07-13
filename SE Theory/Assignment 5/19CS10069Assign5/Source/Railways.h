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
    static bool validated;

    Railways();

    ~Railways();

    Railways(Railways& r);          // declared in private to avoid copy construction/ copy assignment

    Railways& operator=(Railways& r);           // since it is a singleton
    
public:

    static const Railways& Type();                  // for Meyers singleton!

    static void createRailways();                   // initializing function

    static void Validate();                         /// for validation

    static void UnitTest();

    static double GetDistance(const Station& s1, const Station& s2);            // gives distance between two stations

    static bool validStation(const string& s);                              // validates a particular station
    
    friend ostream& operator<< (ostream& os, const Railways& r);                // the stream operator
};

#endif 