#ifndef GENDER_H
#define GENDER_H

#include <string>
using namespace std;

// Implementation of Gender hierarchy using parametric-inclusion polymorphism

template <typename T>       // forward declaration
class GenderTypes;

class Gender {
    const string name_;         // note that it is const
    struct MaleType {};         // defining the types as structs
    struct FemaleType {};       // without scattering the global namespace

protected:
    Gender(const string& name);         // in protected since the base classes need to acces these
    virtual ~Gender();

public:
    const string& GetName() const;                  // virtual functions to be overriden
    virtual const string& GetTitle() const = 0;
    static bool IsMale(const Gender&);              // test for Gender...assuming there are two genders only
    static void UnitTest();

    typedef GenderTypes<MaleType> Male;             // typedefs to make the code cleaner
    typedef GenderTypes<FemaleType> Female;
    friend ostream& operator<<(ostream&, const Gender&);      
};

template <typename T>                               // implementation using parametric polymorphism
class GenderTypes : public Gender {
    static const string sName;                      // storing as static attributes
    static const string sSalutation;

    GenderTypes(const string& name = GenderTypes<T>::sName);       
    ~GenderTypes();

public:
    static const GenderTypes<T>& Type();            // Meyer's singleton
    const string& GetTitle() const;                 // dynamc dispatch
    static void UnitTest();
    friend ostream& operator<<(ostream&, const Gender&);
};

#endif  // GENDER_H