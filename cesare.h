#ifndef CESARE_H
#define CESARE_H

#include "ciphertext.h"

/// @class Cesare
/// @brief A derived class for the Caesar cipher encryption and decryption
class Cesare : public Ciphertext
{
private:
    int shift; // the shift value for the Caesar cipher

public:
    /// @brief Default constructor
    Cesare();

    /// @brief Constructor with shift value
    /// @param text The input text
    /// @param shiftVal The shift value for the Caesar cipher
    Cesare(char *text, int shiftVal);

    /// @brief Copy constructor
    /// @param o Reference to the object to be copied
    Cesare(const Cesare &o);

    /// @brief Destructor
    ~Cesare();

    /// @brief Overloaded assignment operator
    /// @param o Reference to the object on the right of the operator
    /// @return Reference to the object on the left of the operator
    Cesare &operator=(const Cesare &o);

    /// @brief Set the shift value
    /// @param shiftVal The new shift value for the Caesar cipher
    void SetShift(int shiftVal);

    /// @brief Override the base class's Cipher function
    /// @param text The input text
    /// @return The ciphered text
    char *Cipher(char *text) override;

    /// @brief Override the base class's Decipher function
    /// @param text The input text
    /// @return The deciphered text
    char *Decipher(char *text) override;
};

#endif
