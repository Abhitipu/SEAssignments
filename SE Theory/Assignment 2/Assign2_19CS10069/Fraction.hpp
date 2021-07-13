#include<iostream>

using namespace std;

class Fraction {
private:       // The implementation
    int p, q;  // int has been used for q to prevent assignment errors
    // later, we ensure q > 0

    // the static functions, declared inline as these will reduce overhead
    inline static int precision();

    static int gcd(int x, int y) {
        return (x == 0) ? y : gcd(y%x, x);
    }

    inline static int lcm(int x, int y);

public:     // The interface
    Fraction(int, int);

    Fraction(double d);

    ~Fraction();    // destructor

    // copy constructor
    Fraction(const Fraction& f);

    void normalize() ;

    // the unary operators
    // see Fraction.cpp for detailed explainations of syntax and semantics
    void operator= (const Fraction& f);

    Fraction operator- ();

    Fraction operator+ ();

    // the increment and decrement operators
    // see Fraction.cpp for detailed explainations of syntax and semantics
    Fraction& operator++ ();

    Fraction operator++ (int);

    Fraction& operator-- ();

    Fraction operator-- (int);

    // the required friend functions involving mathematical operations
    // see Fraction.cpp for detailed explainations of syntax and semantics
    friend Fraction operator+ (const Fraction& f1, const Fraction& f2);

    friend Fraction operator- (const Fraction& f1, const Fraction& f2);

    friend Fraction operator* (const Fraction& f1, const Fraction& f2);

    friend Fraction operator/ (const Fraction& f1, const Fraction& f2);

    friend Fraction operator% (const Fraction& f1, const Fraction& f2);

    friend Fraction operator% (const Fraction& f1, const Fraction& f2);

    // these are declared inline as they are one line functions
    // and do not involve loops/recursion
    // this reduces overhead and optimizes the program
    inline bool operator== (const Fraction& f1);
    inline bool operator!= (const Fraction& f1);
    inline bool operator< (const Fraction& f1);
    inline bool operator> (const Fraction& f1);
    inline bool operator<= (const Fraction& f1);
    inline bool operator>= (const Fraction& f1);

    // the special operator
    Fraction operator! ();

    // the streaming operators declared as friends
    friend ostream& operator<< (ostream& os, const Fraction& f);
    friend istream& operator>> (istream& ip, Fraction& f);

    // the static constants which have been initialised later
    const static Fraction sc_fUnity;
    const static Fraction sc_fZero;
};

// expansion of the inline functions
inline int Fraction :: lcm(int x, int y) {
    return x*y/(Fraction :: gcd(x, y));
}

inline int Fraction :: precision() {
    return 100000;
}

// Binary relational operators
// the operators returning boolean values
// these are declared inline as they are one line functions
// and do not involve loops/recursion
// this reduces overhead and optimizes the program
inline bool Fraction :: operator== (const Fraction& f1) {
    return (p == f1.p) && (q == f1.q);
}

inline bool Fraction :: operator!= (const Fraction& f1) {
    return !(*this == f1);          // re use of code to avoid bugs

}
inline bool Fraction :: operator< (const Fraction& f1) {
    int den = lcm(q, f1.q);
    return (p*den/q) < (f1.p*den/f1.q);
}

inline bool Fraction :: operator> (const Fraction& f1) {
    int den = lcm(q, f1.q);
    return (p*den/q) > (f1.p*den/f1.q);
}

inline bool Fraction :: operator<= (const Fraction& f1) {
    return !(*this > f1);       // re use of code to avoid bugs
}

inline bool Fraction :: operator>= (const Fraction& f1) {
    return !(*this < f1);       // re use of code to avoid bugs
}
