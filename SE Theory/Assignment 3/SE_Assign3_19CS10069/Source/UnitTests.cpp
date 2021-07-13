// To compile : g++ UnitTests.cpp Booking.cpp Station.cpp BookingClass.cpp Date.cpp Passenger.cpp Railways.cpp

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

void UnitTest() {
    Booking :: UnitTest();              // NOTE : Some bookings are created in unit tests as well!
    Railways :: UnitTest();

    Date :: UnitTest();
    Passenger :: UnitTest();
    
    BookingClass :: UnitTest();
    Sitting :: UnitTest();
    ACChairCar :: UnitTest();
    SecondSitting :: UnitTest();
    Sleeping :: UnitTest();
    TwoTier :: UnitTest();
    FirstClass :: UnitTest();
    ACFirstClass :: UnitTest();
    AC2Tier :: UnitTest();
    ThreeTier :: UnitTest();
    AC3Tier :: UnitTest();
    Sleeper :: UnitTest();
}

int main() {
    UnitTest();
    return 0;
}