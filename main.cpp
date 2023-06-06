/// \file main.cpp
///     \brief Main function of the program
///     \return 0 if the program executed successfully
///
///     Details.
///

#include <iostream>
#include <fstream>
#include "cesare.h"

using namespace std;

int main()
{
    char inputText[1000]; /// Input text shift by the user
    int shiftVal = 0;         /// \shiftVal Shift value for the Caesar cipher

    cout << "Enter the text to encrypt: ";
    cin.getline(inputText, 1000); /// Read the input text from the user

    Cesare cipher(inputText, shiftVal); /// Create a Cesare object using the input text and shift value

    char *encryptedText = cipher.Cipher(inputText);       /// Encrypt the input text using the Cipher() method
    char *decryptedText = cipher.Decipher(encryptedText); /// Decrypt the encrypted text using the Decipher() method

    cout << "Encrypted text: " << encryptedText << endl; /// Print the encrypted text
    cout << "Decrypted text: " << decryptedText << endl; /// Print the decrypted text

    delete[] encryptedText; /// Deallocate the memory for the encrypted text
    delete[] decryptedText; /// Deallocate the memory for the decrypted text

    return 0; /// Return 0 to indicate successful program execution
}
