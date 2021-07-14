# File Organization

- Booking.cpp : Source file for class Booking.
- Booking.h : Header file for class Booking.
- BookingCategory.cpp : Source file for all Booking categories.
- BookingCategory.h : Header file for Booking categories.
- BookingClass.cpp : Source file for class BookingClass.
- BookingClass.h : Header file for class 
- Concessions.cpp : Source file for class Concessions.
- Concessions.h : Header file for class Concessions.
- Date.cpp : Source file for class Date.
- Date.h : Header file for class Date.
- Divyaang.cpp: Source file for class Divyaang.
- Divyaang.h : Header file for class Divyaang.
- Exceptions.cpp : Source file for class Exceptions.
- Exceptions.h : Header file for class Exceptions.
- Gender.cpp : Source file for class Gender.
- Gender.h : Header file for class Gender.
- Passenger.cpp : Source file for class Passenger.
- Passenger.h : Header file for class Passenger.
- Railways.cpp : Source file for class Railways.
- Railways.h : Header file for class Railways.
- Station.cpp : Source file for class Station.
- Station.h : Header file for class Station.

## Test application : 
- main.cpp : Contains all application tests along with unit tests for all classes.

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
g++ main.cpp Booking.cpp BookingClass.cpp BookingCategory.cpp Concessions.cpp Date.cpp Divyaang.cpp Exceptions.cpp Gender.cpp Passenger.cpp Railways.cpp Station.cpp
```
