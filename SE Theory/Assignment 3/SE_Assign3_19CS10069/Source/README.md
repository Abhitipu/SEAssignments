# File Organization
- Booking.cpp : Source file for class Booking.
- Booking.h : Header file for class Booking.
- BookingClass.cpp : Source file for class BookingClass.
- BookingClass.h : Header file for class 
- Date.cpp : Source file for class Date.
- Date.h : Header file for class Date.
- Passenger.cpp : Source file for class Passenger.
- Passenger.h : Header file for class Passenger.
- Railways.cpp : Source file for class Railways.
- Railways.h : Header file for class Railways.

## There are 3 Test applications : 
1. GivenTest.cpp : Containing the test case in section C.
2. UnitTests.cpp : Containing all the created unit tests for all classes.
3. main.cpp : Contains more application tests.

## Compiler details:
g++ (MinGW.org GCC-6.3.0-1) 6.3.0
Copyright (C) 2016 Free Software Foundation, Inc.

*******Instructions to compile*******

Move to directory containing the "Source folder"<br>
Use Command: 
```
g++ <File_Name_of_test_file_with_extension> Booking.cpp Station.cpp BookingClass.cpp Date.cpp Passenger.cpp Railways.cpp
```
Eg : For "GivenTest.cpp" we use:
```
g++ GivenTest.cpp Booking.cpp Station.cpp BookingClass.cpp Date.cpp Passenger.cpp Railways.cpp
```
