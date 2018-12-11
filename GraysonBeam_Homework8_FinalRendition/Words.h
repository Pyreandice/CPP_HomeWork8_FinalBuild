#ifndef WORDS_
#define WORDS_

#include <cstdlib>
#include <fstream>
#include <functional>
#include <iostream>
#include <locale>
#include <set>
#include <sstream>
#include <string>
#include <strstream>
#include <vector>

using namespace std;

class Words
{

public:
	Words();
	Words(int appeared, string wordItself, string NumberLines);
	~Words();

	// Setters
	void SetTimesAppeared(int x);
	void SetWordLines(string u);
	void SetWordObject(string b);

	// Getters
	int GetTimesAppeared()const;
	string GetWordLines()const;
	string GetWordObject()const;

	// Overload comparison operators.
	bool operator<(const Words&)const;
	bool operator>(const Words&)const;
	bool operator<=(const Words&)const;
	bool operator>=(const Words&)const;
	bool operator==(const Words&)const;
	bool operator!=(const Words&)const;

	// Overload the cout opeator.
	friend ostream & operator << (ostream & out, Words & temp);

private:
	int compare_to(const Words&)const;

	// Objects
	int TimesAppeared;
	string WordLines;
	string WordObject;

};
#endif // !WORDS_
