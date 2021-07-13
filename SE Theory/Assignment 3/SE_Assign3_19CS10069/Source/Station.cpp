/*
Name : Abhinandan De
Roll No: 19CS10069
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;
#include "Station.h"
#include "Railways.h"

Station::Station(const string& name): name_(name){ }         // constructor

Station::Station(const Station& s): name_(s.name_) { }          // cctor

string Station:: GetName() const {         
    return name_; 
}

double Station::GetDistance(const Station& s) const {       
    return (Railways :: Type()).GetDistance(*this, s);
}

Station::~Station(){                // destructor
    
}

ostream& operator<< (ostream& os, const Station& s) {        // stream operator
    os << s.name_ << '\n';
    return os;
}