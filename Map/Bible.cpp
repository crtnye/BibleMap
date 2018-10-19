#include "Bible.h"
#include <fstream>
#include <sstream>

using std::ifstream;
using std::stringstream;

Bible::Bible()
{
	string lineString;
	
	ifstream inputFile;

	inputFile.open("test.txt");

	if (inputFile.is_open())
	{
		string bookName = "";
		while (getline(inputFile, lineString))
		{
			stringstream line(lineString);
			VerseKey key;
			Verse verse;
			char* bookNameArray = NULL;

			if (isalpha(line.peek()))
			{
				string temp;
				line >> temp >> temp; //"Book ##"
				line.ignore(1); //ignores the tab after "Book ##"
				getline(line, bookName);
			}
			else
			{
				string test;
				key.book = bookName;
				line >> key.chapter >> key.verseNumber;
				line.ignore(1); //ignores the space after the verse number
				verse.verseKey = key;
				getline(line, verse.verseText);
				(*this)[key] = verse;
			}
		}
	}
}


Bible::~Bible()
{
}
