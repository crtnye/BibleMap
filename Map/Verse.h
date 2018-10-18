#pragma once
#include "VerseKey.h"

class Verse
{
public:
	Verse();
	~Verse();

private:
	VerseKey verseKey;
	string verseText;
};

