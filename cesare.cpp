/// \file Cesare.cpp
///    \brief class Cesare: encryption/decryption of a string message by shifting each charcter by a specified amount
///
///               Derivate of class ciphertext
///


#include <iostream>

#include <cstring>

#include "cesare.h"




using namespace std;




/// @brief default constructor
Cesare::Cesare() : Ciphertext()

{

	cout << "Cesare - Default constructor" << endl;

	shift = 0;

}




/// @brief Constructor with shift value
/// @param text The input text
/// @param shiftVal The shift value for the Caesar cipher
Cesare::Cesare(char* text, int shiftVal) : Ciphertext(text)

{

	cout << "Cesare - Constructor" << endl;

	shift = shiftVal;

}




/// @brief Copy constructor
/// @param o Reference to the object to be copied
Cesare::Cesare(const Cesare& o) : Ciphertext(o)

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

Cesare& Cesare::operator=(const Cesare& o)

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




/// @brief Override the base class's Cipher function
/// @param text The input clean text
/// @return The ciphered text
char* Cesare::Cipher(char* text)

{

	int length = strlen(text);

	char* cipherText = new char[length + 1];




	do

	{

		cout << "Enter shift value for ciphering (positive number): ";

		cin >> shift;




		if (shift <= 0)

		{

			cout << "Invalid shift value. Please enter a positive number." << endl;

		}

	} while (shift <= 0);




	// Clean the input string

	int j = 0;

	for (int i = 0; i < length; i++)

	{

		if (isalpha(text[i]))

		{

			if (isupper(text[i]))

				cipherText[j] = tolower(text[i]);

			else

				cipherText[j] = text[i];

			j++;

		}

	}

	cipherText[j] = '\0';




	// Apply the Caesar cipher

	for (int i = 0; i < j; i++)

	{

		if (islower(cipherText[i]))

			cipherText[i] = (cipherText[i] - 'a' + shift) % 26 + 'a';

	}




	return cipherText;

}




/// @brief Override the base class's Decipher function
/// @param text The ciphered text
/// @return The deciphered text
char* Cesare::Decipher(char* text)

{

	int length = strlen(text);

	char* decipherText = new char[length + 1];




	do

	{

		cout << "Enter shift value for deciphering (positive number): ";

		cin >> shift;




		if (shift <= 0)

		{

			cout << "Invalid shift value. Please enter a positive number." << endl;

		}

	} while (shift <= 0);




	// Clean the input string

	int j = 0;

	for (int i = 0; i < length; i++)

	{

		if (isalpha(text[i]))

		{

			if (isupper(text[i]))

				decipherText[j] = tolower(text[i]);

			else

				decipherText[j] = text[i];

			j++;

		}

	}

	decipherText[j] = '\0';




	// Apply the Caesar cipher (reverse shift)

	for (int i = 0; i < j; i++)

	{

		if (islower(decipherText[i]))

			decipherText[i] = (decipherText[i] - 'a' - shift + 26) % 26 + 'a';

	}




	return decipherText;

}





