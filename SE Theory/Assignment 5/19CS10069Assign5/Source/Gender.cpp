#include "Gender.h"
#include<iostream>

using namespace std;

// forward declaration of the templates to avoid linker error (eg : undefined reference)

template class GenderTypes<Gender :: MaleType>;
template class GenderTypes<Gender :: FemaleType>;

// assigning values to the static data members
template <> const string Gender::Male::sName = "Male";
template <> const string Gender::Female::sName = "Female";
template <> const string Gender::Male::sSalutation = "Mr.";
template <> const string Gender::Female::sSalutation = "Ms.";

Gender :: Gender(const string& name) : name_(name){
    // ctor
}

Gender :: ~Gender(){
    // dtor
}

const string& Gender :: GetName() const { 
    return name_; 
}

bool Gender::IsMale(const Gender& g) {
    return &g == &Male::Type();             // comparing address is enough as we have used Meyer's singleton
}

void Gender :: UnitTest() {                 
    const Gender& g = Male :: Type();       // creating a child class with the help of a const reference (avoiding pointers!)
    
    if(g.GetName() != "Male") {                         // a check on all the members
        cout << "Error in name for male gender\n";
    }
    if(g.GetTitle() != "Mr.") {
        cout << "Error in salutation for male gender\n";
    }
    if(!IsMale(g)) {                                    // because if not male then female
        cout << "Error in IsMale function\n";
    }
    cout << g << '\n';          // Testing the ostream operator!
    cout << "****TESTING FOR GENDER IS COMPLETE****\n";

}
template<typename T>
GenderTypes<T> :: GenderTypes(const string& name) : Gender(name){
    // ctor
}

template<typename T>
GenderTypes<T> :: ~GenderTypes(){
    // dtor
}

template<typename T>
const GenderTypes<T>& GenderTypes<T> :: Type(){             // they Meyers singleton implementation
    static const GenderTypes<T> myObj;
    return myObj;
}

template<typename T>
const string& GenderTypes<T> :: GetTitle() const {          // overriden GetTitle
    return GenderTypes<T>::sSalutation;
}

template<typename T>
void GenderTypes<T> :: UnitTest() {
    const Gender& g = Type();
    if(g.GetName() != sName){                       // testing the GetName function
        cout << "Error in GetName\n";
    }
    if(g.GetTitle() != sSalutation) {               // the salutation test!
        cout << "Error in GetSalutation\n";
    }
    cout << g << '\n';
    cout << "****TESTING FOR " << sName << " IS COMPLETE****\n";
}

ostream& operator<<(ostream& os, const Gender& g){           // only one stream operator suffices! (credits : polymorphism)
    os << g.GetName();
    return os;
}