#include "VerseKey.h"


VerseKey::VerseKey()
{
}


VerseKey::~VerseKey()
{
}

bool operator==(const VerseKey &rValue, const VerseKey &lValue)
{
	bool result = false;

	if (rValue.book == lValue.book && rValue.chapter == lValue.chapter && rValue.verseNumber == lValue.verseNumber)
	{
		result = true;
	}

	return result;
}

istream& operator>>(istream& in, VerseKey &input)
{
	cout << "Please enter a book of the Bible: ";
	cin >> input.book;
	cout << endl << "Chapter: ";
	cin >> input.chapter;
	cout << endl << "Verse: ";
	cin >> input.verseNumber;
	cout << endl; 

	return in;
}