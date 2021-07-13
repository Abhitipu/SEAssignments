/*
Name : Abhinandan De
Roll No: 19CS10069
*/

#include "Exceptions.h"

Bad_Date :: Bad_Date() noexcept {

}

Bad_Date :: Bad_Date(const Bad_Date&) noexcept {

}

Bad_Date ::  ~Bad_Date() noexcept {

}

const char* Bad_Date :: what() const noexcept {
    return ("Invalid Date!");
}

Bad_Railways :: Bad_Railways() noexcept {

}

Bad_Railways :: Bad_Railways(const Bad_Railways&) noexcept {

}

Bad_Railways :: ~Bad_Railways() noexcept {

}

const char* Bad_Railways ::  what() const noexcept {
    return ("Bad description of Railways!");
}

Bad_Station :: Bad_Station() noexcept {

}

Bad_Station :: Bad_Station(const Bad_Station&) noexcept {

}

Bad_Station :: ~Bad_Station() noexcept {

}

const char* Bad_Station ::  what() const noexcept {
    return ("Station not found!");
}

Station_Duplication :: Station_Duplication() noexcept {

}

Station_Duplication :: Station_Duplication(const Station_Duplication&) noexcept {

}

Station_Duplication :: ~Station_Duplication() noexcept {

}

const char* Station_Duplication ::  what() const noexcept {
    return ("Duplicate Stations in the input list!");
}

Distance_Duplication :: Distance_Duplication() noexcept {

}

Distance_Duplication :: Distance_Duplication(const Distance_Duplication&) noexcept {

}

Distance_Duplication :: ~Distance_Duplication() noexcept {

}

const char* Distance_Duplication ::  what() const noexcept {
    return ("Duplicate distances between 2 stations in the input list!");
}

Bad_Distance :: Bad_Distance() noexcept {

}

Bad_Distance :: Bad_Distance(const Bad_Distance&) noexcept {

}

Bad_Distance :: ~Bad_Distance() noexcept {

}

const char* Bad_Distance ::  what() const noexcept {
    return ("Non positive distance between 2 stations in the input list!");
}

Bad_Passenger :: Bad_Passenger() noexcept {

}

Bad_Passenger :: Bad_Passenger(const Bad_Passenger&) noexcept {

}

Bad_Passenger :: ~Bad_Passenger() noexcept {

}

const char* Bad_Passenger ::  what() const noexcept {
    return ("Invalid details for passenger!");
}

Bad_Name :: Bad_Name() noexcept {

}

Bad_Name :: Bad_Name(const Bad_Name&) noexcept {

}

Bad_Name :: ~Bad_Name() noexcept {

}

const char* Bad_Name ::  what() const noexcept {
    return ("Invalid format for name!");
}


Bad_Age :: Bad_Age() noexcept {

}

Bad_Age :: Bad_Age(const Bad_Age&) noexcept {

}

Bad_Age :: ~Bad_Age() noexcept {

}

const char* Bad_Age ::  what() const noexcept {
    return ("Invalid age!");
}

Bad_Aadhar :: Bad_Aadhar() noexcept {

}

Bad_Aadhar :: Bad_Aadhar(const Bad_Aadhar&) noexcept {

}

Bad_Aadhar :: ~Bad_Aadhar() noexcept {

}

const char* Bad_Aadhar ::  what() const noexcept {
    return ("Invalid aadhar number!");
}

Bad_Mobile_Number :: Bad_Mobile_Number() noexcept {

}

Bad_Mobile_Number :: Bad_Mobile_Number(const Bad_Mobile_Number&) noexcept {

}

Bad_Mobile_Number :: ~Bad_Mobile_Number() noexcept {

}

const char* Bad_Mobile_Number ::  what() const noexcept {
    return ("Invalid mobile number!");
}

Bad_Booking :: Bad_Booking() noexcept {

}

Bad_Booking :: Bad_Booking(const Bad_Booking&) noexcept {

}

Bad_Booking :: ~Bad_Booking() noexcept {

}

const char* Bad_Booking ::  what() const noexcept {
    return ("Invalid booking details!");
}

Bad_Date_Of_Booking :: Bad_Date_Of_Booking() noexcept {

}

Bad_Date_Of_Booking :: Bad_Date_Of_Booking(const Bad_Date_Of_Booking&) noexcept {

}

Bad_Date_Of_Booking :: ~Bad_Date_Of_Booking() noexcept {

}

const char* Bad_Date_Of_Booking ::  what() const noexcept {
    return ("Invalid date of booking!");
}

Bad_Age_Of_Passenger :: Bad_Age_Of_Passenger() noexcept {

}

Bad_Age_Of_Passenger :: Bad_Age_Of_Passenger(const Bad_Age_Of_Passenger&) noexcept {

}

Bad_Age_Of_Passenger :: ~Bad_Age_Of_Passenger() noexcept {

}

const char* Bad_Age_Of_Passenger ::  what() const noexcept {
    return("Passenger is born after reservation date!");
}

Inconsistent_Booking_Category :: Inconsistent_Booking_Category() noexcept {

}

Inconsistent_Booking_Category :: Inconsistent_Booking_Category(const Inconsistent_Booking_Category&) noexcept {

}

Inconsistent_Booking_Category :: ~Inconsistent_Booking_Category() noexcept {

}

const char* Inconsistent_Booking_Category ::  what() const noexcept {
    return("Inconsistent booking category of passenger!");
}