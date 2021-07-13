// To compile : g++ GivenTest.cpp Booking.cpp Station.cpp BookingClass.cpp Date.cpp Passenger.cpp Railways.cpp

/*
Name : Abhinandan De
Roll No: 19CS10069
*/

#include<iostream>
#include<vector>
using namespace std;

#include "Railways.h"
#include "Booking.h"
#include "BookingClass.h"
#include "Station.h"
#include "Date.h"
#include "Passenger.h"

void BookingApplication() {
    
    // Bookings by different booking classes
    // <BookingClasses>::Type() returns the constant object of the respective type
    Booking b1(Station("Mumbai"), Station("Delhi"), Date(15, 2, 2021), ACFirstClass::Type());
    Booking b2(Station("Kolkata"), Station("Delhi"), Date(5, 3, 2021), AC2Tier::Type());
    Booking b3(Station("Mumbai"), Station("Kolkata"), Date(17, 3, 2021), FirstClass::Type());
    Booking b4(Station("Mumbai"), Station("Delhi"), Date(23, 3, 2021), AC3Tier::Type());
    Booking b5(Station("Chennai"), Station("Delhi"), Date(25, 4, 2021), ACChairCar::Type());
    Booking b6(Station("Chennai"), Station("Kolkata"), Date(7, 5, 2021), Sleeper::Type());
    Booking b7(Station("Mumbai"), Station("Delhi"), Date(19, 5, 2021), SecondSitting::Type());
    Booking b8(Station("Delhi"), Station("Mumbai"), Date(22, 5, 2021), SecondSitting::Type());


    // Output the bookings done where sBookings is the collection of bookings done
    vector<Booking*>::iterator it;
    
    for (it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it) {
        cout << *(*it);
    }

    return;
}

int main() {
    BookingApplication();
    return 0;
}