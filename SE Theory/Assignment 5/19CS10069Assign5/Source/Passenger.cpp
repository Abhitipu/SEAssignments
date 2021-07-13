/*
Name : Abhinandan De
Roll No: 19CS10069
*/
#include<iostream>
#include "Passenger.h"
#include "Date.h"

using namespace std;

// #define __DEBUG

Passenger :: Passenger(const string& firstname, const string& middlename, const string& lastname, const string& aadharnumber,       // ctor
    const Date dob, const Gender& gender, string mobileNumber, const string& divyaangId, const int disabilityIndex):
    firstname_(firstname), middlename_(middlename), lastname_(lastname), aadharNumber_(aadharnumber), dateOfBirth_(dob),
    gender_(gender), disabilityIndex_(disabilityIndex), divyaangId_(divyaangId), mobileNumber_(mobileNumber) {

}

Passenger :: Passenger(const Passenger& p): firstname_(p.firstname_), middlename_(p.middlename_), lastname_(p.lastname_),           // cctor
    aadharNumber_(p.aadharNumber_), dateOfBirth_(p.dateOfBirth_), gender_(p.gender_), mobileNumber_(p.mobileNumber_), 
    divyaangId_(p.divyaangId_), disabilityIndex_(p.disabilityIndex_){
    
    #ifdef __DEBUG
        cout << "Successfully copied passenger\n";
        cout << p.divyaangId_ << '\n';
        cout << *this;
    #endif
}

Passenger :: ~Passenger() {         // dtor

}

void Passenger :: Validate(const string& firstname, const string& middlename,const string& lastname,const string& aadharNumber,         // validation
                        const Date& dob, const Gender& gender, const string mobileNumber,const string& divyaangId,
                        const int disabilityIndex) {
    
    if(firstname == "" && lastname == "")           // validation of the name
        throw Bad_Name();

    if(aadharNumber.length() != 12) {               // validation of the aadhar number
        throw Bad_Aadhar();
    }
    for(char c: aadharNumber)                       // ""  ""  ""   ""  ""
        if(!isdigit(c))
            throw Bad_Aadhar();
    
    if(mobileNumber != "NA") {
        if(mobileNumber.length() != 10)                 // mobile number validation
        throw Bad_Mobile_Number();

        for(char c : mobileNumber)                      
            if(!isdigit(c))
                throw Bad_Mobile_Number();    
    }
    
    #ifdef __DEBUG
        cout << "Validated Passenger\n";
    #endif 
}

Passenger Passenger :: createPassenger(const string& firstname, const string& middlename, const string& lastname, const string& aadharNumber, const Date& dob, const Gender& gender, string mobileNumber, string divyaangId, int disabilityIndex) {
        
    try {
        Validate(firstname, middlename, lastname, aadharNumber, dob, gender, mobileNumber, divyaangId, disabilityIndex);
    } catch(exception& e){
        throw;
    }

    Passenger myPassenger(firstname, middlename, lastname, aadharNumber, dob, gender, mobileNumber, divyaangId, disabilityIndex);

    #ifdef __DEBUG
        cout << "Successfully Created passenger\n";
    #endif 

    return myPassenger;
}

const string Passenger :: getDivyaangId () const { 
    return divyaangId_;
}

const int Passenger :: getDisabilityIndex () const { 
    return disabilityIndex_;
}

const Date& Passenger :: getDateOfBirth () const { 
    return dateOfBirth_;
}

const Gender& Passenger :: getGender() const { 
    return gender_;
}

void Passenger :: UnitTest() {
    
    try {
        const Date d1 = Date :: createDate(12, 3, 2010);
        const Date d2 = Date :: createDate(15, 6, 2019);
        const Date d3 = Date :: createDate(12, 7, 1984);

        const Passenger p1 = createPassenger("Abhinandan", "", "De", "124568345678", d1, Gender :: Male :: Type(), "8272288222");  // details are upto mobile no.
        const Passenger p2 = createPassenger("Suryam", "Arnav", "Kalra", "156359247342", d2, Gender :: Male :: Type(), "7654890654", "DJNCKKCC", 2);    // all details
        const Passenger p3 = createPassenger("Megha", "", "", "176245389456", d3, Gender :: Female :: Type());      // no mobile number also
        
        cout << "Successfully created all passengers\n";

        if(p1.getDateOfBirth() != d1)
            cout << "Error in getDateOfBirth\n";
        
        if(p2.getDisabilityIndex() != 2 || p2.getDivyaangId() != "DJNCKKCC")
            cout << "Error in getting the divyaang info!\n";
        
        if(Gender::IsMale(p3.getGender()))
            cout << "Error in getGender function!\n";

    } catch(exception& e) {
        throw;      // rethrow!
    }

    const Date d1 = Date :: createDate(12, 3, 2010);
    
    try {
        const Passenger p4e = createPassenger("", "", "", "124568345678", d1, Gender :: Male :: Type(), "8272288222");      // wrong name format
        cout << "Erroneous passenger created!\n";                       // flow wont reach this point!
    } catch(exception& e) {
        cout << "***Exception caught***\n";
        cout << e.what() << '\n';
    }

    try {
        const Passenger p4e = createPassenger("", "Kumar", "", "124568345678", d1, Gender :: Male :: Type(), "8272288222");      // wrong name format
        cout << "Erroneous passenger created!\n";                       // flow wont reach this point!
    } catch(exception& e) {
        cout << "***Exception caught***\n";
        cout << e.what() << '\n';
    }

    try {
        const Passenger p4e = createPassenger("Abhinandan", "", "De", "12456A5678", d1, Gender :: Male :: Type(), "8272288222");      // wrong aadhar format
        cout << "Erroneous passenger created!\n";                       // flow wont reach this point!
    } catch(exception& e) {
        cout << "***Exception caught***\n";
        cout << e.what() << '\n';
    }

    try {
        const Passenger p4e = createPassenger("Abhinandan", "", "", "124568345678", d1, Gender :: Male :: Type(), "8+7882++22");      // wrong phone number format
        cout << "Erroneous passenger created!\n";                       // flow wont reach this point!
    } catch(exception& e) {
        cout << "***Exception caught***\n";
        cout << e.what() << '\n';
    }

    try {
        const Passenger p4e = createPassenger("Abhinandan", "", "", "124568345678", d1, Gender :: Male :: Type(), "827222");      // wrong phone number format
        cout << "Erroneous passenger created!\n";                       // flow wont reach this point!
    } catch(exception& e) {
        cout << "***Exception caught***\n";
        cout << e.what() << '\n';
    }
    cout << "****TESTING FOR PASSENGER IS COMPLETE****\n";
}

ostream& operator<<(ostream& os, const Passenger& p) {                          // stream!
    os << "Name             : " << p.gender_.GetTitle() << " ";
    if(p.firstname_.length())
        os << p.firstname_ << " ";
    if(p.middlename_.length())
        os << p.middlename_ << " ";
    if(p.lastname_.length())
        os << p.lastname_ << " ";
    os << '\n';
    
    os << "Aadhar number    : " << p.aadharNumber_ << '\n';
    
    os << "Mobile number    : "<< p.mobileNumber_ << '\n';   
    os << "Date of birth    : " << p.dateOfBirth_;
    os << "Gender           : " << p.gender_.GetName() << "\n"; 

    
    os << "Divyaang Id      : "<< p.divyaangId_ << '\n';
    os << "Disability Index : ";
    if(p.disabilityIndex_)
        os << p.disabilityIndex_ << '\n';   
    else
        os << "NA\n";

    os << '\n';
    return os;
}