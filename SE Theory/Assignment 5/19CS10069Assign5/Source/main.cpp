// To compile : g++ main.cpp Booking.cpp BookingClass.cpp BookingCategory.cpp Concessions.cpp Date.cpp Divyaang.cpp Exceptions.cpp Gender.cpp Passenger.cpp Railways.cpp Station.cpp

/*
Name : Abhinandan De
Roll No: 19CS10069
*/

#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<cmath>

#include "Booking.h"
#include "BookingCategory.h"
#include "BookingClass.h"
#include "Concessions.h"
#include "Date.h"
#include "Divyaang.h"
#include "Exceptions.h"
#include "Gender.h"
#include "Passenger.h"
#include "Railways.h"
#include "Station.h"


using namespace std;

void Test() {
    
    // Creating random bookings of all types     

    try {
        Station s1 = Station :: createStation("Kolkata");
        Station s2 = Station :: createStation("Delhi");
        Station s3 = Station :: createStation("Mumbai");
        Station s4 = Station :: createStation("Chennai");
        Station s5 = Station :: createStation("Kolkata");
        Station s6 = Station :: createStation("Kanpur");
    } catch(exception& e) {
        cout << "\n***Exception caught!** : ";
        cout << e.what() << '\n';
    }

    try {
        Station s1 = Station :: createStation("Kolkata");
        Station s2 = Station :: createStation("Delhi");
        const Date& d1 = Date :: createDate(16, 3, 2001);
        const Passenger p1 = Passenger :: createPassenger("Abhinandan", "", "De", "134236789345", d1, Gender :: Male :: Type(), "8279728914");
        const Date& d2 = Date :: createDate(8, 4, 2021);
        const Date& d3 = Date :: createDate(9, 8, 2021);
        cout << "\n\n";
        const Booking* b1 = Booking :: ReserveBooking(s1, s2, d2, BookingClass :: ACFirstClass :: Type(), GeneralCategory :: Type(), p1, d3);       // correct!
    } catch(exception& e) {
        cout << "\n***Exception caught!** : ";
        cout << e.what() << '\n';
    }

    try {
        Station s1 = Station :: createStation("Delhi");
        Station s2 = Station :: createStation("Mumbai");
        const Date& d1 = Date :: createDate(16, 3, 2001);
        const Passenger p1 = Passenger :: createPassenger("Abhinandan", "", "De", "134236789345", d1, Gender :: Male :: Type(), "8279728914");      // correct
        const Date& d2 = Date :: createDate(8, 4, 2021);
        const Date& d3 = Date :: createDate(9, 8, 2021);
        cout << "\n\n";
        const Booking* b1 = Booking :: ReserveBooking(s1, s2, d2, BookingClass :: AC3Tier :: Type(), GeneralCategory :: Type(), p1, d3);
    } catch(exception& e) {
        cout << "Exception caught!\n";
        cout << e.what() << '\n';
    }

    try {
        Station s1 = Station :: createStation("Delhi");
        Station s2 = Station :: createStation("Mumbai");
        const Date& d1 = Date :: createDate(16, 3, 1950);
        const Passenger p1 = Passenger :: createPassenger("Prabhat", "Kumar", "Hajra", "134236789345", d1, Gender :: Male :: Type(), "9412056328");     // correct
        const Date& d2 = Date :: createDate(8, 4, 2021);
        const Date& d3 = Date :: createDate(9, 8, 2021);
        cout << "\n\n";
        const Booking* b1 = Booking :: ReserveBooking(s1, s2, d2, BookingClass :: AC3Tier :: Type(), SeniorCitizenCategory :: Type(), p1, d3);
    } catch(exception& e) {
        cout << "Exception caught!\n";
        cout << e.what() << '\n';
    }

    try {
        Station s1 = Station :: createStation("Delhi");
        Station s2 = Station :: createStation("Mumbai");
        const Date& d1 = Date :: createDate(16, 3, 1956);
        const Passenger p1 = Passenger :: createPassenger("Mamata", "", "Hajra", "134236789345", d1, Gender :: Female :: Type(), "9921133112");
        const Date& d2 = Date :: createDate(8, 4, 2021);
        const Date& d3 = Date :: createDate(9, 8, 2021);
        cout << "\n\n";
        const Booking* b1 = Booking :: ReserveBooking(s1, s2, d2, BookingClass :: Sleeper :: Type(), SeniorCitizenCategory :: Type(), p1, d3);     // correct
    } catch(exception& e) {
        cout << "Exception caught!\n";
        cout << e.what() << '\n';
    }

    try {
        Station s1 = Station :: createStation("Delhi");
        Station s2 = Station :: createStation("Mumbai");
        const Date& d1 = Date :: createDate(16, 3, 1980);
        const Passenger p1 = Passenger :: createPassenger("Suryam", "Arnav", "Kalra", "134236789345", d1, Gender :: Male :: Type(), "9921133112", "d12233", 1);
        const Date& d2 = Date :: createDate(8, 4, 2021);
        const Date& d3 = Date :: createDate(9, 8, 2021);
        cout << "\n\n";
        const Booking* b1 = Booking :: ReserveBooking(s1, s2, d2, BookingClass :: AC3Tier :: Type(), SeniorCitizenCategory :: Type(), p1, d3);      // correct
    } catch(exception& e) {
        cout << "Exception caught!\n";
        cout << e.what() << '\n';
    }

    try {
        Station s1 = Station :: createStation("Delhi");
        Station s2 = Station :: createStation("Mumbai");
        const Date& d1 = Date :: createDate(16, 3, 1980);
        const Passenger p1 = Passenger :: createPassenger("Suryam", "Arnav", "Kalra", "134236789345", d1, Gender :: Male :: Type(), "9921133112", "d12233", 3);
        const Date& d2 = Date :: createDate(8, 4, 2021);
        const Date& d3 = Date :: createDate(9, 4, 2021);
        cout << "\n\n";
        const Booking* b1 = Booking :: ReserveBooking(s1, s2, d2, BookingClass :: FirstClass :: Type(), PremiumTatkalCategory :: Type(), p1, d3);      // correct!
    } catch(exception& e) {
        cout << "****Exception caught!****\n";
        cout << e.what() << '\n';
    }

    try {
        Station s1 = Station :: createStation("Delhi");
        Station s2 = Station :: createStation("Mumbai");
        const Date& d1 = Date :: createDate(16, 3, 1980);
        const Passenger p1 = Passenger :: createPassenger("Shashank", "", "Singh", "134236789345", d1, Gender :: Male :: Type(), "9921133112", "d12233", 3);
        const Date& d2 = Date :: createDate(8, 4, 2021);
        const Date& d3 = Date :: createDate(9, 4, 2021);
        cout << "\n\n";
        const Booking* b1 = Booking :: ReserveBooking(s1, s2, d2, BookingClass :: SecondSitting :: Type(), SeniorCitizenCategory :: Type(), p1, d3);      // incorrect!
    } catch(exception& e) {
        cout << "Exception caught!\n";
        cout << e.what() << '\n';
    }

    try {
        Station s1 = Station :: createStation("Delhi");
        Station s2 = Station :: createStation("Mumbai");
        const Date& d1 = Date :: createDate(16, 3, 1980);
        const Passenger p1 = Passenger :: createPassenger("Abhinandan", "", "", "134236789345", d1, Gender :: Male :: Type(), "9921133112", "d12233", 3);
        const Date& d2 = Date :: createDate(8, 4, 2021);
        const Date& d3 = Date :: createDate(9, 8, 2021);
        cout << "\n\n";
        const Booking* b1 = Booking :: ReserveBooking(s1, s2, d2, BookingClass :: ExecutiveChairCar :: Type(), TatkalCategory :: Type(), p1, d3);         // incorrect!
    } catch(exception& e) {
        cout << "Exception caught!\n";
        cout << e.what() << '\n';
    }

    try {
        Station s1 = Station :: createStation("Chennai");
        Station s2 = Station :: createStation("Bangalore");
        const Date& d1 = Date :: createDate(16, 3, 1980);
        const Passenger p1 = Passenger :: createPassenger("Simran", "Sharma", "", "134236789345", d1, Gender :: Female :: Type(), "9921133112", "d12233", 3);
        const Date& d2 = Date :: createDate(8, 4, 2021);
        const Date& d3 = Date :: createDate(9, 4, 2021);
        cout << "\n\n";
        const Booking* b1 = Booking :: ReserveBooking(s1, s2, d2, BookingClass :: AC2Tier :: Type(), PremiumTatkalCategory :: Type(), p1, d3); // correct!
    } catch(exception& e) {
        cout << "Exception caught!\n";
        cout << e.what() << '\n';
    }

    vector<Booking*>::iterator it;          // traversing through the list!
    
    for (it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it) {
        cout << *(*it);
    }
}

void UnitTests() {
    try {
        Railways :: createRailways();
    } catch(exception& e) {
        cout << "\n***Exception caught!** : ";
        cout << e.what() << '\n';
    }  

    Booking :: UnitTest();
    GeneralBooking :: UnitTest();
    LadiesBooking :: UnitTest();
    SeniorCitizensBooking :: UnitTest();
    TatkalBooking :: UnitTest();
    PremiumTatkalBooking :: UnitTest();

    BookingClass :: UnitTest();                     
    BookingClass :: ACFirstClass :: UnitTest();
    BookingClass :: ExecutiveChairCar :: UnitTest();
    BookingClass :: AC2Tier :: UnitTest();
    BookingClass :: AC3Tier :: UnitTest();
    BookingClass :: FirstClass :: UnitTest();
    BookingClass :: ACChairCar :: UnitTest();
    BookingClass :: Sleeper :: UnitTest();
    BookingClass :: SecondSitting :: UnitTest();

    BookingCategory :: UnitTest();          
    GeneralCategory :: UnitTest();
    LadiesCategory :: UnitTest();
    SeniorCitizenCategory :: UnitTest();
    DivyaangCategory :: UnitTest();
    TatkalCategory :: UnitTest();
    PremiumTatkalCategory :: UnitTest();
    
    Concession :: UnitTest();           
    LadiesConcession :: UnitTest();
    SeniorCitizenConcession :: UnitTest();
    DivyaangConcession :: UnitTest();

    Date :: UnitTest();              

    Divyaang :: UnitTest();                                                    
    Divyaang :: BlindDivyaang :: UnitTest();
    Divyaang :: OrthopaedicallyHandicappedDivyaang :: UnitTest();
    Divyaang :: CancerPatientDivyaang :: UnitTest();
    Divyaang :: TBPatientDivyaang :: UnitTest();
    
    Gender :: UnitTest();                
    Gender :: Male :: UnitTest();
    Gender :: Female :: UnitTest();
    
    Passenger :: UnitTest();        

    Railways :: UnitTest();      

    Station :: UnitTest();
}

int main() {
    UnitTests();
    // Test();
    return 0;
}