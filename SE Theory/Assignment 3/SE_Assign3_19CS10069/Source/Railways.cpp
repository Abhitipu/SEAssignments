/*
Name : Abhinandan De
Roll No: 19CS10069
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

#include "Railways.h"
#include "Station.h"

// ititializing the static members!

vector<Station> Railways :: sStations = {Station("Mumbai"), Station("Delhi"), Station("Bangalore"), Station("Kolkata"), Station("Chennai")};

map<pair<string, string>, double> Railways :: sDistStations = {
    {{"Mumbai", "Delhi"}, 1447}, {{"Delhi", "Mumbai"}, 1447},
    {{"Mumbai", "Bangalore"}, 981}, {{"Bangalore", "Mumbai"}, 981},
    {{"Mumbai", "Kolkata"}, 2014}, {{"Kolkata", "Mumbai"}, 2014},
    {{"Mumbai", "Chennai"}, 1338}, {{"Chennai", "Mumbai"}, 1338},
    {{"Delhi", "Bangalore"}, 2150}, {{"Bangalore", "Delhi"}, 2150},
    {{"Delhi", "Kolkata"}, 1472}, {{"Kolkata", "Delhi"}, 1472},
    {{"Delhi", "Chennai"}, 2180}, {{"Chennai", "Delhi"}, 2180},
    {{"Bangalore", "Kolkata"}, 1871}, {{"Kolkata", "Bangalore"}, 1871},
    {{"Bangalore", "Chennai"}, 350}, {{"Chennai", "Bangalore"}, 350},
    {{"Kolkata", "Chennai"}, 1659}, {{"Chennai", "Kolkata"}, 1659}
};

Railways :: Railways() {

}

Railways :: ~Railways() {}


const Railways& Railways ::Type() {         // static function that ensures that only one instance of the class is created
    static const Railways r; 
    return r; 
}

double Railways :: GetDistance(const Station& s1, const Station& s2) const{ 
    const string x = s1.GetName();
    const string y = s2.GetName();
    return Railways :: sDistStations[{x, y}];
}


void Railways :: UnitTest() {
    cout << Type();     // checking the Type() function and the ostream operator

    const double error = 1e-6;

    if(abs(Type().GetDistance(sStations[1], sStations[2]) - 2150.00) >= error)
        cout << "Error in getting the distances from GetDistance\n";
    if(abs(Type().GetDistance(sStations[1], sStations[4]) - 2180.00) >= error)
        cout << "Error in getting the distances from GetDistance\n";

    if(abs(sDistStations[{sStations[1].GetName(), sStations[2].GetName()}] - 2150.00) >= error)
        cout << "Error in storing the distances in sDistStations\n";
    if(abs(sDistStations[{sStations[1].GetName(), sStations[4].GetName()}] - 2180.00) >= error)
        cout << "Error in storing the distances in sDistStations\n";

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