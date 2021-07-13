/*
Name : Abhinandan De
Roll No: 19CS10069
*/
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include<exception>
#include<iostream>

using namespace std;

class Bad_Date : public exception {
public:
    Bad_Date() noexcept;
    Bad_Date(const Bad_Date&) noexcept;
    virtual ~Bad_Date() noexcept;
    virtual const char* what() const noexcept;
};


class Bad_Railways : public exception {
public:
    Bad_Railways() noexcept;
    Bad_Railways(const Bad_Railways&) noexcept;
    virtual ~Bad_Railways() noexcept;
    virtual const char* what() const noexcept;
};

class Bad_Station : public exception {
public:
    Bad_Station() noexcept;
    Bad_Station(const Bad_Station&) noexcept;
    virtual ~Bad_Station() noexcept;
    virtual const char* what() const noexcept;
};

class Station_Duplication : public Bad_Railways {
public:
    Station_Duplication() noexcept;
    Station_Duplication(const Station_Duplication&) noexcept;
    virtual ~Station_Duplication() noexcept;
    virtual const char* what() const noexcept;
    // repeated stations in sstations
};

class Distance_Duplication : public Bad_Railways {
public:
    Distance_Duplication() noexcept;
    Distance_Duplication(const Distance_Duplication&) noexcept;
    virtual ~Distance_Duplication() noexcept;
    virtual const char* what() const noexcept;
    // repeated pairs of stations in sDistStations
};

class Bad_Distance : public Bad_Railways {
public:
    Bad_Distance() noexcept;
    Bad_Distance(const Bad_Distance&) noexcept;
    virtual ~Bad_Distance() noexcept;
    virtual const char* what() const noexcept;
};

class Bad_Passenger : public exception {
public:
    Bad_Passenger() noexcept;
    Bad_Passenger(const Bad_Passenger&) noexcept;
    virtual ~Bad_Passenger() noexcept;
    virtual const char* what() const noexcept;
};

class Bad_Name : public Bad_Passenger {
public:
    Bad_Name() noexcept;
    Bad_Name(const Bad_Name&) noexcept;
    virtual ~Bad_Name() noexcept;
    virtual const char* what() const noexcept;
};

class Bad_Age : public Bad_Passenger {
public:
    Bad_Age() noexcept;
    Bad_Age(const Bad_Age&) noexcept;
    virtual ~Bad_Age() noexcept;
    virtual const char* what() const noexcept;
};

class Bad_Aadhar : public Bad_Passenger {
public:
    Bad_Aadhar() noexcept;
    Bad_Aadhar(const Bad_Aadhar&) noexcept;
    virtual ~Bad_Aadhar() noexcept;
    virtual const char* what() const noexcept;
};

class Bad_Mobile_Number : public Bad_Passenger {
public:
    Bad_Mobile_Number() noexcept;
    Bad_Mobile_Number(const Bad_Mobile_Number&) noexcept;
    virtual ~Bad_Mobile_Number() noexcept;
    virtual const char* what() const noexcept;
};

class Bad_Booking : public exception {
public:
    Bad_Booking() noexcept;
    Bad_Booking(const Bad_Booking&) noexcept;
    virtual ~Bad_Booking() noexcept;
    virtual const char* what() const noexcept;
};


class Bad_Date_Of_Booking : public Bad_Booking {
public:
    Bad_Date_Of_Booking() noexcept;
    Bad_Date_Of_Booking(const Bad_Date_Of_Booking&) noexcept;
    virtual ~Bad_Date_Of_Booking() noexcept;
    virtual const char* what() const noexcept;
};


class Bad_Age_Of_Passenger : public Bad_Booking {
public:
    Bad_Age_Of_Passenger() noexcept;
    Bad_Age_Of_Passenger(const Bad_Age_Of_Passenger&) noexcept;
    virtual ~Bad_Age_Of_Passenger() noexcept;
    virtual const char* what() const noexcept;
};

class Inconsistent_Booking_Category : public Bad_Booking {
public: 
    Inconsistent_Booking_Category() noexcept;
    Inconsistent_Booking_Category(const Inconsistent_Booking_Category&) noexcept;
    virtual ~Inconsistent_Booking_Category() noexcept;
    virtual const char* what() const noexcept;
};

#endif  //  EXCEPTIONS_H