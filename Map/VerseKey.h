#pragma once
#include<string>
#include<istream>
#include<iostream>

using std::string;
using std::istream;
using std::cin;
using std::cout;
using std::endl;

class VerseKey
{
public:
	VerseKey();
	~VerseKey();

	string book;
	int chapter;
	int verseNumber;
};

bool operator==(const VerseKey &rValue, const VerseKey &lValue);
istream& operator>>(istream& in, VerseKey &input);
