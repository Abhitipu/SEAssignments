#include<iostream>

using namespace std;

#include "Fraction.hpp"

// Constructor 1
// The constructor with default parameters,
// it sets values and calls normalize() to reduce to lowest terms
Fraction :: Fraction(int _p = 1, int _q = 1): p(_p), q(_q) {
    if(q < 0) {
        p *= -1;
        q *= -1;
    }
    else if(q == 0) {
        exit(1);   // error without throwing an exception!
    }

    normalize();   // since constructors only create normalized fractions
}

// Constructor 2
// construct fraction by multiplying with precision as directed
// normalizes the fraction
Fraction :: Fraction(double d) {
    p = (int)(d*precision());  // explicit conversion
    q = precision();
    normalize();
}

// Constructor 3
// Copy Constructor
Fraction :: Fraction(const Fraction& f): p(f.p), q(f.q) {    // copy constructor
    normalize();
}

// destructor
Fraction :: ~Fraction() { }

// utility function to convert fraction to lowest terms
void Fraction :: normalize() {     // converts into lowest terms
    if(p == 0)      // as directed
        q = 1;

    int g = gcd(abs(p), q);
    p /= g;
    q /= g;
}

// the unary operators

// the copy assignment operator
// doesnt return anything as assignment is already done here
void Fraction :: operator= (const Fraction& f) {
    p = f.p;
    q = f.q;
}

// unary minus : just makes the numerator negative as denominator is non negative
// returns by value as it returns the value of a local variable
Fraction Fraction :: operator- () {
    Fraction f(-p, q);
    return f;
}

// Returns the fraction as it is
// returns by value as it returns the value of a local variable
Fraction Fraction :: operator+ () {
    Fraction f(p, q);
    return f;
}

// the increment and decrement operators

// returns a reference as it is pre incrementing the fraction.
// it increments and then returns the value by reference
Fraction& Fraction :: operator++ () {
    p += q;
    return *this;
}

// stores a copy, increments and returns the copy
// returns by value as it returns the value of a local variable
// which is a copy of the original fraction
Fraction Fraction :: operator++ (int) {
    Fraction f1(p, q);
    p += q;
    return f1;
}

// returns a reference as it is pre decrementing the fraction.
// it decrements and then returns the value by reference
Fraction& Fraction :: operator-- () {
    p -= q;
    return *this;
}

// stores a copy, decrements and returns the copy
// returns by value as it returns the value of a local variable
// which is a copy of the original fraction
Fraction Fraction :: operator-- (int) {
    Fraction f1(p, q);
    p -= q;
    return f1;
}

// Binary Arithmetic operators
// the required friend functions involving mathematical operations
// All these are creating new fractions since the original fractions must not be modified
// to prevent any modification by chance, the Fractions have been qualified as CONSTANTS
// Thus all of these are returning by value

// addition
// returns by value as it returns the value of a local variable
Fraction operator+ (const Fraction& f1, const Fraction& f2) {
    int den = Fraction :: lcm(f1.q, f2.q);
    // Fraction :: is used because we arent in the scope of Fraction :: anymore
    int num = (f2.p)*(den/f2.q) + (f1.p)*(den/f1.q);
    Fraction f(num, den);
    return f;
}

// subtraction
// returns by value as it returns the value of a local variable
Fraction operator- (const Fraction& f1, const Fraction& f2) {
    int den = Fraction :: lcm(f1.q, f2.q);
    // Fraction :: is used because we arent in the scope of Fraction :: anymore
    int num = (f1.p)*(den/f1.q) - (f2.p)*(den/f2.q);
    Fraction f(num, den);
    return f;
}

// multiplication
// returns by value as it returns the value of a local variable
Fraction operator* (const Fraction& f1, const Fraction& f2) {
    int num = f1.p*f2.p;
    int den = f1.q*f2.q;
    Fraction f(num, den);
    return f;
}

// division
// returns by value as it returns the value of a local variable
Fraction operator/ (const Fraction& f1, const Fraction& f2) {
    // using try-catch to prevent termination of program while it throws an exception
    try {
        if(f2.p == 0) {
            throw runtime_error("Attempt to divide by 0!");
            exit(-1);
        } else {
            int num = f1.p*f2.q;
            int den = f1.q*f2.p;
            Fraction f(num, den);
            return f;
        }
    } catch(exception& e) {
        cout << "Exception: " << e.what() << '\n';
        return Fraction::sc_fZero;   // returns 0 for exception
    }
}

// residue
// returns by value as it returns the value of a local variable
// implementation : https://en.cppreference.com/w/cpp/numeric/math/fmod
Fraction operator% (const Fraction& f1, const Fraction& f2) {
    // using try-catch to prevent termination of program while it throws an exception
    try {
        if(f2.p == 0) {
            throw runtime_error("Attempt to take a modulo by 0!");
            exit(-1);
        }
        else {
            Fraction f = f1/f2;
            Fraction rem = f1 - ((int)(f.p/f.q))*f2;
            return rem;
        }
    } catch(exception& e) {
        cout << "Exception: " << e.what() << '\n';
        return Fraction::sc_fZero;   // returns 0 for exceptions
    }
}

// special operator
// returns by value as it returns the value of a local variable
Fraction Fraction :: operator! () {
    // using try-catch to prevent termination of program while it throws an exception
    try {
        if(p == 0) {
            throw runtime_error("Can't take inverse. Fraction is 0");
        } else {
            Fraction f(q, p);
            return f;
        }
    } catch(exception& e) {
        cout << "Exception: " << e.what() << '\n';
        return Fraction::sc_fZero;  // returns 0 for exceptions!
    }
}

// streaming operators
// returns the i/o operators by reference after modification
ostream& operator<< (ostream& os, const Fraction& f) {
    os << f.p;
    if(f.q != 1)
        os << " / " << f.q;
    return os;
}

istream& operator>> (istream& ip, Fraction& f) {
    ip >> f.p >> f.q;
    return ip;
}

// the static constants, which have to be initialised outside the class
const Fraction Fraction :: sc_fUnity = Fraction();
const Fraction Fraction :: sc_fZero = Fraction(0);
