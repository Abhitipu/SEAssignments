// To compile : g++ main.cpp Booking.cpp Station.cpp BookingClass.cpp Date.cpp Passenger.cpp Railways.cpp

/*
Name : Abhinandan De
Roll No: 19CS10069
*/

#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<cmath>

#include "Railways.h"
#include "Booking.h"
#include "BookingClass.h"
#include "Station.h"
#include "Date.h"
#include "Passenger.h"

using namespace std;

void Test() {
    
    // Creating random bookings of all types

    Booking b1(Station("Kolkata"), Station("Delhi"), Date(26, 3, 2021), ACFirstClass::Type());
    Booking b2(Station("Bangalore"), Station("Delhi"), Date(15, 3, 2022), ACChairCar::Type());
    Booking b3(Station("Bangalore"), Station("Kolkata"), Date(17, 3, 2021), FirstClass::Type());
    Booking b4(Station("Delhi"), Station("Mumbai"), Date(22, 7, 2021), SecondSitting::Type());
    Booking b5(Station("Chennai"), Station("Delhi"), Date(23, 4, 2021), FirstClass::Type());
    Booking b6(Station("Chennai"), Station("Kolkata"), Date(17, 8, 2021), Sleeper::Type());
    Booking b7(Station("Mumbai"), Station("Delhi"), Date(14, 7, 2021), AC2Tier::Type());
    Booking b8(Station("Mumbai"), Station("Bangalore"), Date(23, 3, 2021), AC3Tier::Type());

    // Changing some static parameters 

    AC2Tier :: ChangeLuxury(true);
    FirstClass :: ChangeLoadFactor(2.5);
    AC3Tier :: ChangeLoadFactor(2.00);
    ACChairCar :: ChangeLuxury(true);

    Booking :: ChangeAcSurcharge(45);
    Booking :: ChangeBaseFare(0.6);
    Booking :: ChangeLuxuryTaxPercent(30); 

    // and testing for the same bookings !

    Booking b1_(Station("Kolkata"), Station("Delhi"), Date(26, 3, 2021), ACFirstClass::Type());
    Booking b2_(Station("Bangalore"), Station("Delhi"), Date(15, 3, 2022), ACChairCar::Type());
    Booking b3_(Station("Bangalore"), Station("Kolkata"), Date(17, 3, 2021), FirstClass::Type());
    Booking b4_(Station("Delhi"), Station("Mumbai"), Date(22, 7, 2021), SecondSitting::Type());
    Booking b5_(Station("Chennai"), Station("Delhi"), Date(23, 4, 2021), FirstClass::Type());
    Booking b6_(Station("Chennai"), Station("Kolkata"), Date(17, 8, 2021), Sleeper::Type());
    Booking b7_(Station("Mumbai"), Station("Delhi"), Date(14, 7, 2021), AC2Tier::Type());
    Booking b8_(Station("Mumbai"), Station("Bangalore"), Date(23, 3, 2021), AC3Tier::Type());

    vector<Booking*>::iterator it;          // traversing through the list!
    
    for (it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it) {
        cout << *(*it);
    }

}

int main() {
    Test();
    return 0;
}