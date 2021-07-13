/*
Name : Abhinandan De
Roll No: 19CS10069
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<exception>

using namespace std;

#include "Railways.h"
#include "Station.h"
#include "Exceptions.h"
#define __DEBUG

// ititializing the static members!
// bool validate is to be used 

bool Railways :: validated = false; 

vector<Station> Railways :: sStations = {};

map<pair<string, string>, double> Railways :: sDistStations = {};

Railways :: Railways() {

}

Railways :: ~Railways() {}


const Railways& Railways ::Type() {         // static function that ensures that only one instance of the class is created
    if(!validated)
        Validate();     // checks for the input data!

    static const Railways r; 
    return r; 
}

double Railways :: GetDistance(const Station& s1, const Station& s2){ 
    const string x = s1.GetName();
    const string y = s2.GetName();
    if(sDistStations.count({x, y}))
        return sDistStations[{x, y}];
    else
        throw Bad_Booking();      // because there is no available direct route!
}

void Railways :: Validate() {

    vector<string> inputStations = {"Mumbai", "Delhi", "Bangalore", "Kolkata", "Chennai"};

    map<string, bool> checker;
    for(const string& s : inputStations) {
        if(s == "")
            throw Bad_Station();
        if(checker.count(s))
            throw Station_Duplication();
        else {
            sStations.push_back(Station :: createStation(s, true));
        }    
    }

    #ifdef __DEBUG
        cout << "Added all stations\n";
    #endif

    vector<pair<pair<string, string>, double>> inputData = {
        {{"Mumbai", "Delhi"}, 1447},
        {{"Mumbai", "Bangalore"}, 981},
        {{"Mumbai", "Kolkata"}, 2014},
        {{"Mumbai", "Chennai"}, 1338},
        {{"Delhi", "Bangalore"}, 2150},
        {{"Delhi", "Kolkata"}, 1472},
        {{"Delhi", "Chennai"}, 2180},
        {{"Bangalore", "Kolkata"}, 1871},
        {{"Bangalore", "Chennai"}, 350},
        {{"Kolkata", "Chennai"}, 1659}
    };

    for(pair<pair<string, string>, double> p : inputData) {
        if(p.second <= 0.0) {
            throw Bad_Distance();
        }
        if(validStation(p.first.first) && validStation(p.first.second) && p.first.first.length() && p.first.second.length()) {
            if((Railways :: sDistStations).count(p.first)) {
                throw Station_Duplication();
            } else {
                Railways :: sDistStations[p.first] = p.second;
                Railways :: sDistStations[{p.first.second, p.first.first}] = p.second; 
            }
        } else {
            throw Bad_Station();
        }
    }

    #ifdef __DEBUG
        cout << "Updated Distances\n";
    #endif

    Railways :: validated = true;
}

bool Railways :: validStation(const string& s) {
    if(s == "") 
        return false;       // empty station name cant be valid!
    
    for(const Station& s1 : sStations) {
        if(s == s1.GetName())
            return true;
    }
    return false;
}

void Railways :: createRailways() {
    try {
        Railways :: Validate();
    } 
    catch(exception& e){
        throw;
    }

    #ifdef __DEBUG
        cout << "Created Railways!\n";
    #endif
}

void Railways :: UnitTest() {
    cout << Type();     // checking the Type() function and the ostream operator

    const double error = 1e-3;

    if(abs(Type().GetDistance(sStations[1], sStations[2]) - 2150.00) >= error)              // checking the GetDistance Function
        cout << "Error in getting the distances from GetDistance\n";
    if(abs(Type().GetDistance(sStations[1], sStations[4]) - 2180.00) >= error)
        cout << "Error in getting the distances from GetDistance\n";

    if(abs(sDistStations[{sStations[1].GetName(), sStations[2].GetName()}] - 2150.00) >= error)         // cheking if inputs were taken correctly
        cout << "Error in storing the distances in sDistStations\n";
    if(abs(sDistStations[{sStations[1].GetName(), sStations[4].GetName()}] - 2180.00) >= error)
        cout << "Error in storing the distances in sDistStations\n";

    if(!validStation("Delhi")) {                                        // checking the validStation function
        cout << "Error in validStation function\n";
    } 
    if(validStation("Kochi")) {
        cout << "Error in validStation function\n";
    }
    cout << "****TESTING FOR RAILWAYS IS COMPLETE****\n";
}

ostream& operator<< (ostream& os, const Railways& r) { 
    os << "List of stations:\n";

    for(const Station& s: Railways :: sStations)
        os << s;
    
    os << "\nDistances between stations:\n";

    int n = Railways::sStations.size();
    for(int i = 0; i < n; ++i) {
        for(int j = i+1; j < n; ++j) {
            string x = Railways::sStations[i].GetName();
            string y = Railways::sStations[j].GetName();
            os << x << " " << y << ": " << Railways::sDistStations[{x, y}] << '\n';
        }
    }

    os << '\n';

    return os;
}