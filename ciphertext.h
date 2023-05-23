/*! \file ciphertext.h
	\brief Declaration of the base class Ciphertext

	Details.
*/

#ifndef CIPHERTEXT_H
#define CIPHERTEXT_H

#include <iostream>


using namespace std;

/// @class Ciphertext
/// @brief an abstract base class for encription performed on plain text
class Ciphertext
{
protected:
	char *inText;

	// I've changed virtual into virtual pure
	virtual char *Cipher(char *text) = 0;
	virtual char *Decipher(char *text) = 0;

public:
	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	Ciphertext();
	Ciphertext(char *text);
	Ciphertext(const Ciphertext &o);
	virtual ~Ciphertext();
	/// @}

	/// @name OPERATORS
	/// @{
	Ciphertext &operator=(const Ciphertext &o);
	bool operator==(const Ciphertext &o);
	/// @}

	/// @name BASIC HANDLING
	/// @{
	void Init();
	void Init(const Ciphertext &o);
	void Reset();
	/// @}

	/// @name GETTERS
	/// @{
	char *GetText();
	char *GetEncryption();
	char *GetDecryption();

	void SetText(char *text);
	/// @}

	/// @name DEBUG and SERIALIZATION
	/// @{
	void ErrorMessage(const char *string){};
	void WarningMessage(const char *string){};
	void Dump() { cout << endl
					   << inText << endl; };
	/// @}
};

#endif