/// \file ciphertext.cpp
///	\brief class Ciphertext: implementation of the functions
///
///	Details.
///

#include "ciphertext.h"
#include <string.h>

/// @brief default constructor
Ciphertext::Ciphertext()
{

	cout << "Ciphertext - constructor - default" << endl;

	Init();
}

/// @brief constructor
/// @param text the input text
Ciphertext::Ciphertext(char *text)
{

	cout << "Ciphertext - constructor" << endl;

	SetText(text);
}

/// @brief copy constructor
/// @param r reference to object to be copied
Ciphertext::Ciphertext(const Ciphertext &o)
{

	cout << "Ciphertext - copy constructor" << endl;

	Init(o);
}

/// @brief destructor
Ciphertext::~Ciphertext()
{

	cout << "Ciphertext - distructor" << endl;
	Reset();
}

/// @brief default initialization
void Ciphertext::Init()
{

	inText = NULL;
}

/// @brief initialization with object
/// @param o reference to the object
void Ciphertext::Init(const Ciphertext &o)
{

	if (o.inText != NULL)
		SetText(o.inText);
}

/// @brief default reset
void Ciphertext::Reset()
{

	if (inText != NULL)
		delete inText;

	inText = NULL;
}

/// @brief overload operator =
/// @param r reference to object on the right of the operator
/// @return refence to object on the left of the operator
Ciphertext &Ciphertext::operator=(const Ciphertext &o)
{

	Reset();
	Init(o);

	return *this;
}

/// @brief  overload operator ==
/// @param r reference to object on the right of the operator
/// @return always false
bool Ciphertext::operator==(const Ciphertext &o)
{

	return false;
}

/// @brief set the text
/// @param text the new text
void Ciphertext::SetText(char *text)
{

	Reset();

	if (text != NULL)
	{

		inText = new char[strlen(text) + 1];
		strcpy_s(inText, strlen(text) + 1, text);
	}
}

char *Ciphertext::GetText()
{

	char *outText;

	outText = new char[strlen(inText) + 1];
	strcpy_s(outText, strlen(inText) + 1, inText);

	return outText;
}

char *Ciphertext::GetEncryption()
{
	return Cipher(inText);
}

char *Ciphertext::GetDecryption()
{
	return Decipher(inText);
}

char *Ciphertext::Cipher(char *text)
{

	int i;
	unsigned int shift;
	unsigned int ascii;
	char *outText;

	outText = new char[strlen(text) + 1];
	strcpy_s(outText, strlen(text) + 1, text);

	i = 0;
	shift = 6;
	while (outText[i] != '\0' && (i < strlen(outText) + 1))
	{
		ascii = (unsigned int)outText[i];
		outText[i] = (char)(97 + (ascii + shift - 97) % 26);

		i++;
	}

	return outText;
}

char *Ciphertext::Decipher(char *text)
{

	int i;
	unsigned int shift;
	unsigned int ascii;
	char *outText;

	outText = new char[strlen(text) + 1];
	strcpy_s(outText, strlen(text) + 1, text);

	i = 0;
	shift = 6;
	while (outText[i] != '\0' && (i < strlen(outText) + 1))
	{
		ascii = (unsigned int)outText[i];
		outText[i] = (char)(97 + (ascii - 97 - shift + 26) % 26);

		i++;
	}

	return outText;
}

