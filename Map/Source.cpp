#include <iostream>
#include <string>
#include <stdexcept>
#include "Map.hpp"
#include "Bible.h"
#include "Verse.h"
#include "VerseKey.h"

using util::Map;
using std::cout;
using std::endl;

void main()
{
	//Map <std::string, int> QandA;
	//QandA["What year were you born?"] = 1997;
	//cout << QandA["What year were you born?"] << endl;
	//QandA["What day were you born on?"] = 30;
	//cout << QandA["What day were you born on?"] << endl;
	////you realize you had your birthday wrong your whole life oops
	//QandA["What day were you born on?"] = 20;
	//cout << QandA["What day were you born on?"] << endl;

	//try
	//{
	//	cout << QandA[" "];
	//}
	//catch (std::range_error e)
	//{
	//	cout << e.what() << endl;
	//}
	VerseKey myVerse;

	cin >> myVerse;
}
