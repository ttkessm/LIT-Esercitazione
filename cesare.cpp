#include <iostream>
#include <cstring>
#include "cesare.h"

using namespace std;

// Default constructor
Cesare::Cesare() : Ciphertext()
{
    cout << "Cesare - Default constructor" << endl;
    shift = 0;
}

// Constructor with shift value
Cesare::Cesare(char *text, int shiftVal) : Ciphertext(text)
{
    cout << "Cesare - Constructor" << endl;
    shift = shiftVal;
}

// Copy constructor
Cesare::Cesare(const Cesare &o) : Ciphertext(o)
{
    cout << "Cesare - Copy constructor" << endl;
    shift = o.shift;
}

// Destructor
Cesare::~Cesare()
{
    cout << "Cesare - Destructor" << endl;
}

// Overloaded assignment operator
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

// Set the shift value
void Cesare::SetShift(int shiftVal)
{
    shift = shiftVal;
}

// Override the base class's Cipher function
char *Cesare::Cipher(char *text)
{
    int length = strlen(text);
    char *cipherText = new char[length + 1];

    cout << "Enter shift value: ";
    cin >> shift;

    //Da completare

    return cipherText;
}

// Override the base class's Decipher function
char *Cesare::Decipher(char *text)
{
    int length = strlen(text);
    char *decipherText = new char[length + 1];

    cout << "Enter shift value: ";
    cin >> shift;

    //Da completare

    return decipherText;
}
