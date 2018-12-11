#include "Words.h"

Words::Words()
{
}

Words::Words(int appeared = 0, string wordItself = "", string NumberLines = "")
{
	TimesAppeared = appeared;
	WordObject = wordItself;
	WordLines= NumberLines;
}

int Words::compare_to(const Words &other)const
{
	if (this->GetWordObject() < other.GetWordObject())
	{
		return -1;
	}
	else if (this->GetWordObject() > other.GetWordObject())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Words::GetTimesAppeared()const
{
	return TimesAppeared;
}

string Words::GetWordLines()const
{
	return WordLines;
}

string Words::GetWordObject()const
{
	return WordObject;
}

void Words::SetTimesAppeared(int x)
{
	TimesAppeared = x;
}

void Words::SetWordLines(string u)
{
	WordLines = u;
}

void Words::SetWordObject(string b)
{
	WordObject = b;
}

bool Words::operator<(const Words & rh) const
{
	return compare_to(rh) < 0;
}

bool Words::operator>(const Words & rh) const
{
	return compare_to(rh) > 0;
}

bool Words::operator<=(const Words & rh) const
{
	return compare_to(rh) <= 0;
}

bool Words::operator>=(const Words & rh) const
{
	return compare_to(rh) >= 0;
}

bool Words::operator==(const Words & rh) const
{
	return compare_to(rh) == 0;
}

bool Words::operator!=(const Words & rh) const
{
	return compare_to(rh) != 0;
}

ostream & operator << (ostream & out, Words & temp)
{
	out << temp.GetWordObject() << "[" << temp.GetTimesAppeared() << "]";
	return out;
}

Words::~Words()
{
}