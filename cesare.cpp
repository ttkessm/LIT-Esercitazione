/// \file Cesare.cpp
///    \brief class Cesare: encryption/decryption of a string message by shifting each charcter by a specified amount
///
///               Derivate of class ciphertext
///

#include <iostream>
#include <cstring>
#include <string.h>
#include "cesare.h"

using namespace std;

///@brief Default constructor
Cesare::Cesare() : Ciphertext()
{
    cout << "Cesare - Default constructor" << endl;
    shift = 0;
}

/// @brief Constructor with shift value
/// @param text The input text
/// @param shiftVal The shift value for the Caesar cipher
Cesare::Cesare(char *text, int shiftVal) : Ciphertext(text)
{
    cout << "Cesare - Constructor" << endl;
    shift = shiftVal;
}

/// @brief Copy constructor
/// @param o Reference to the object to be copied
Cesare::Cesare(const Cesare &o) : Ciphertext(o)
{
    cout << "Cesare - Copy constructor" << endl;
    shift = o.shift;
}

///@brief Destructor
Cesare::~Cesare()
{
    cout << "Cesare - Destructor" << endl;
}

/// @brief Overloaded assignment operator
/// @param o Reference to the object on the right of the operator
/// @return Reference to the object on the left of the operator
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

/// @brief Set the shift value
/// @param shiftVal The new shift value for the Caesar cipher
void Cesare::SetShift(int shiftVal)
{
    shift = shiftVal;
}

/// @brief Get the shift value
int Cesare::GetShift()
{
    int shiftInput;
    cout << "Enter shift value: ";
    cin >> shiftInput;

    return shiftInput;
}

/// @brief Removes special characters and makes uppercase characters lowercase
/// @param text The input text
/// @return The text ready to be ciphered
char *Cesare::CleanText(char *text)
{
    int i = 0; ///@param i counter variable
    int k = 0; ///@param k indesired characters variable
    unsigned int ascii;
    char *cleanedText;

    cleanedText = new char[strlen(text) + 1];      // create an array with the same lenght as the text array
    strcpy_s(cleanedText, strlen(text) + 1, text); // copy the text on that array

    while (cleanedText[i] != '\0' && (i < strlen(cleanedText) + 1 - k)) // funciton that detects ASCII simbols which are not alfabetic charcaters,
    {                                                                   // and makes uppercase characters shift by 32 on the ASCII table, making them lowercase
        ascii = (unsigned int)cleanedText[i];

        if (ascii >= 97 && ascii <= 122)
            cleanedText[i] = (char)ascii;

        else if (ascii >= 65 && ascii <= 90)
            cleanedText[i] = (char)(ascii + 32);

        else
            k++;

        i++;
    }

    return cleanedText;
}

/// @brief Override the base class's Cipher function
/// @param text The input clean text
/// @return The ciphered text
char *Cesare::Cipher(char *text)
{
    char *cleanedText = CleanText(text);
    int i = 0;
    unsigned int shift;
    unsigned int ascii;

    char *cipherText = new char[strlen(cleanedText) + 1];
    strcpy_s(cipherText, strlen(cleanedText) + 1, cleanedText);

    shift = GetShift();

    while (cipherText[i] != '\0' && (i < strlen(cipherText) + 1))
    {
        ascii = (unsigned int)cipherText[i];
        cipherText[i] = (char)(97 + (ascii + shift - 97) % 26);

        i++;
    }

    return cipherText;
}

/// @brief Override the base class's Decipher function
/// @param text The ciphered text
/// @return The deciphered text
char *Cesare::Decipher(char *text)
{
    int i = 0;
    unsigned int shift;
    unsigned int ascii;
    char *decipherText;

    int length = strlen(text);
    decipherText = new char[length + 1];

    shift = GetShift();

    while (text[i] != '\0' && (i < strlen(text) + 1))
    {
        ascii = (unsigned int)decipherText[i];
        decipherText[i] = (char)(97 + (ascii - 97 - shift + 26) % 26);

        i++;
    }

    return decipherText;
}
