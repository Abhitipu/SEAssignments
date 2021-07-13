/*
Name : Abhinandan De
Roll No: 19CS10069
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;
#include "Station.h"
#include "Railways.h"
#include "Exceptions.h"

Station::Station(const string& name): name_(name){ 
    
}         // constructor

Station::Station(const Station& s): name_(s.name_) { 

}

Station Station :: createStation(const string& name, bool verified) {           // verified is set to true initially while creating railways!
    if(verified) {              // during creation of railways
        Station s(name);
        return s;
    }
    else if(Railways :: validStation(name)) {       // does the station exist?
        Station s(name);
        return s;
    }
    else
        throw Bad_Station();                // exception is thrown if it doesnt!
}

const string Station:: GetName() const {         
    return name_; 
}

double Station::GetDistance(const Station& s) const {       
    return (Railways :: Type()).GetDistance(*this, s);
}

Station::~Station(){                // destructor
    
}

void Station :: UnitTest() {
    const Station s1 = createStation("Delhi");              // if createStation works or not
    const Station s2 = createStation("Mumbai");
    const Station s3 = createStation("Kolkata");
    
    double checker1 = s1.GetDistance(s2);
    double checker2 = s1.GetDistance(s3);
    double checker3 = s2.GetDistance(s3);

    double val1 = Railways :: GetDistance(s1, s2);
    double val2 = Railways :: GetDistance(s1, s3);
    double val3 = Railways :: GetDistance(s2, s3);

    if(abs(checker1-val1) >= 1e-3) {                        // checking if distances are stores correctly
        cout << "Error in storing distances\n"; 
    }

    if(abs(checker2-val2) >= 1e-3) {
        cout << "Error in storing distances\n";
    }

    if(abs(checker3-val3) >= 1e-3) {
        cout << "Error in storing distances\n";
    }

    try {
        const Station s3e = createStation("Kanpur");            // Station which does not exist!
        cout << "Program is in an inconsistent state\n";
    } catch(exception& e) {
        cout << "***Exception caught***\n";
        cout << e.what() << '\n';
    }

    try {
        const Station s3e = createStation("");                  // Station with blank name!
        cout << "Program is in an inconsistent state\n";
    } catch(exception& e) {
        cout << "***Exception caught***\n";
        cout << e.what() << '\n';
    }

    cout << "****TESTING FOR STATION IS COMPLETE****\n";

}

ostream& operator<< (ostream& os, const Station& s) {        // stream operator
    os << s.name_ << '\n';
    return os;
}