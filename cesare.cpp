/// \file Cesare.cpp
///    \brief class Cesare: encryption/decryption of a string message by shifting each charcter by a specified amount
///
///               Derivate of class ciphertext
///


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

Cesare::Cesare(char* text, int shiftVal) : Ciphertext(text)

{

	cout << "Cesare - Constructor" << endl;

	shift = shiftVal;

}




// Copy constructor

Cesare::Cesare(const Cesare& o) : Ciphertext(o)

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




// Set the shift value

void Cesare::SetShift(int shiftVal)

{

	shift = shiftVal;

}




// Override the base class's Cipher function

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




// Override the base class's Decipher function

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





