#include <iostream>
#include <cstring>
#include "cesare.h"

using namespace std;

///brief Default constructor
Cesare::Cesare() : Ciphertext()
{
    cout << "Cesare - Default constructor" << endl;
    shift = 0;
}

///brief Constructor with shift value
Cesare::Cesare(char *text, int shiftVal) : Ciphertext(text)
{
    cout << "Cesare - Constructor" << endl;
    shift = shiftVal;
}

///brief Copy constructor
Cesare::Cesare(const Cesare &o) : Ciphertext(o)
{
    cout << "Cesare - Copy constructor" << endl;
    shift = o.shift;
}

///brief Destructor
Cesare::~Cesare()
{
    cout << "Cesare - Destructor" << endl;
}

///brief Overloaded assignment operator
Cesare &Cesare::operator=(const Cesare &o)
{
    cout << "Cesare - Assignment operator" << endl;
    if (this != &o)
    {
        Ciphertext::operator=(o);
        shift = o.shift;
    }
    return *this;
}

///brief Set the shift value
void Cesare::SetShift(int shiftVal)
{
    shift = shiftVal;
}

///brief Override the base class's Cipher function
char *Cesare::Cipher(char *text)
{
    int length = strlen(text);
    char *cipherText = new char[length + 1];

    cout << "Enter shift value: ";
    cin >> shift;

    //Da completare

    return cipherText;
}

///brief Override the base class's Decipher function
char *Cesare::Decipher(char *text)
{
    int length = strlen(text);
    char *decipherText = new char[length + 1];

    cout << "Enter shift value: ";
    cin >> shift;

    //Da completare

    return decipherText;
}
