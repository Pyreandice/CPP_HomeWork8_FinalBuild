// Author : Grayson Beam
// This file contains the 'main' function. Program execution begins and ends there.

#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <locale>
#include <set>
#include <sstream>
#include <string>
#include <strstream>
#include <vector>

#include "Words.h"

using namespace std;

const int ResouceSize = 4;
const string Resouce[ResouceSize] = { "Apology_W.txt", "ModestProposal_W.txt", "ShortHistory_W.txt", "WizardOfOz_W.txt" };
const string PrintFile[ResouceSize] = { "Apology_W_Concordance.txt", "ModestProposal_W_Concordance.txt",
										"ShortHistory_W_Concordance.txt", "WizardOfOz_W_Concordance.txt" };

//bool invalidChar(char m)
//{
//	return !(m >= 0 && m < 128);
//}
//
//void stripUnicode(string &temp)
//{
//	temp.erase(remove_if(temp.begin(), temp.end(), invalidChar), temp.end());
//}

//// Create the set with ALL ASCII and UNICODE removed.
//set<Words> NoUniPunct(set<Words> WordsSet, string d)
//{
//	char temp = ' ';
//	set<Words> RemovedSet = WordsSet;
//	for (auto x : RemovedSet)
//	{
//		// Iterate over the current word to serch for non ascii characters.
//		for (int t = 0; t <= d.length(); t++)
//		{
//			// Temp is equal to the current character at w[t].
//			temp = d[t];
//			// If the current character is on the ascii table.
//			if (temp >= 0 && temp < 128)
//			{
//				// Set temp to equal an empty character again.
//				temp = ' ';
//				//tolower(w[t]);
//
//			}
//			else
//			{
//				// Erase the character from the word.
//				//w.erase(temp);
//				d[t] = '-**';
//				// Set temp to equal an empty character again.
//				temp = ' ';
//			}
//			cout << d[t] << endl;
//		}
//	}
//	return RemovedSet;
//}

string RemovePunctuationLoop(string w)
{
	char temp = ' ';
	bool isErased = true;
	for (unsigned int x = 0; x < w.length(); x++)
	{
		// If isErased equals true.
		if (isErased)
		{
			// Iterate over the current word to serch for non ascii characters.
			for (int t = 0; t <= w.length(); t++)
			{
				// Temp is equal to the current character at w[t].
				temp = w[t];
				// If the current character is on the ascii table.
				if (temp >= 0 && temp < 128)
				{
					// Set temp to equal an empty character again.
					temp = ' ';
					//tolower(w[t]);
					
				}
				else 
				{
					// Erase the character from the word.
					//w.erase(temp);
					w[t] = '-**';
					// Set temp to equal an empty character again.
					temp = ' ';
				}
				cout << w[t] << endl;
			}
			// If the current word contains punctuation.
			if (ispunct(w[x]))
			{
				// Erase the punctuation.
				w.erase(x);
				isErased = true;
			}
			else
			{
				// Else the current word has no punctuation.
				isErased = false;
			}
		}
		else
		{
			// Else leave the word be. Has no punctuation.
			x = w.length();
		}
		isErased = true;
		for (int y = w.length() - 1; y >= 0; y--)
		{
			// If isErased equals true.
			if (isErased)
			{
				// If the current word contains punctuation.
				if (ispunct(w[y]))
				{
					// Erase the punctuation at the end of the word.
					w.erase(y);
					y = w.length() - 1;
					isErased = true;
				}
				else
				{
					// Else the current word has no punctuation at the end of the word.
					isErased = false;
				}
			}
			else
			{
				// Else, basically doNothing();
				y = -1;
			}
		}
	}
	// Return the word with no punctuation.
	return w;
}

// Make vector for lewis way of doing things.
//vector<string> VecWords(int userChoice)
//{
//	vector<string> tempVector;
//	string buff = "";
//	string buff1 = "";
//	string tempString = "";
//	char delem = ' ';
//	int lineNumber = 0;
//	ifstream fin;
//
//	fin.open(Resouce[userChoice]);
//	while (getline(fin, buff))
//	{
//		istringstream s(buff);
//		while (getline(s, buff1, delem))
//		{
//			buff1 = RemovePunctuationLoop(buff1);
//			tempString += buff1 + " ";
//		}
//		tempVector.push_back(buff1);
//		cout << buff1 << endl;
//		lineNumber += 1;
//		tempString = "";
//	}
//	fin.close();
//	return tempVector;
//}

set<Words> Counter(set<Words> WordsSet, int userOption)
{
	set<Words> TempSet;
	string buff1 = "";
	string buff2 = "";
	string buff3 = "";
	// Total number of times a word has appeared.
	int totalCounter = 0;
	// Which line we are currently on in the file.
	int currentLineNum = 0;
	// A list of all the line numbers a word has appeared on.
	string lineCounter = "";
	string tempString = "";
	char delem = ' ';
	string printHere = PrintFile[ResouceSize];
	//vector<string> textBook = VecWords(userOption);
	ifstream fin;
	ofstream fout (printHere);
	fin.open(Resouce[userOption]);

	//// Lewis way of doing things
	//for (auto x : WordsSet)
	//{
	//	for (int line = 0; line < textBook.size(); line++)
	//	{
	//		istringstream texting(textBook[line]);
	//		getline(texting, buff1);
	//		istringstream s(buff3);
	//		while (getline(s, buff3, delem))
	//		{
	//			if (buff3 == x.GetWordObject())
	//			{
	//				totalCounter += 1;
	//				if (lineCounter == "")
	//				{
	//					lineCounter += to_string(line);
	//				}
	//				else
	//				{
	//					lineCounter += "," + to_string(line);
	//				}
	//			}
	//		}
	//	}
	//	TempSet.insert(Words(totalCounter, x.GetWordObject(), lineCounter));
	//	lineCounter = "";
	//	totalCounter = 0;
	//}
	//for (auto x : TempSet)
	//{
	//	cout << x << endl;
	//}
	//fin.close();
	//return TempSet;

	// Iterate over the words in the WordsSet set.
	for (auto x : WordsSet)
	{
		// While there is still a line to get.
		while (getline(fin, buff1))
		{
			// Put the current line into a string stream.
			istringstream s(buff1);
			// While there is still an object to iterate over.
			while (getline(s, buff2, delem))
			{
				// Call the remove Punctuation function.
				buff2 = RemovePunctuationLoop(buff2);
				// If the word with removed punctuation is equal to the word at x.
				if (buff2 == x.GetWordObject())
				{
					cout << x.GetWordObject();
					// Add 1 to the total count of the word.
					totalCounter += 1;
					// If lineCounter is equal to an empty string.
					if (lineCounter == "")
					{
						// Add the current line number to the list in string format.
						lineCounter += to_string(currentLineNum);
					}
					else
					{
						// Add the current line number to the list in string format with a comma for separation.
						lineCounter += "," + to_string(currentLineNum);
					}
				}
			}
			// Add 1 to the current line count.
			currentLineNum += 1;
		}
		// Insert the totalCounter, Current word at x, and the list of line counts to the TempSet.
		TempSet.insert(Words(totalCounter, x.GetWordObject(), lineCounter));
		// Set lineCounter = to an empty string again.
		lineCounter = "";
		// Set totalCounter = to 0.
		totalCounter = 0;
	}
	fin.close();
	// Iterate over the new set.
	for (auto x : TempSet)
	{
		// Print the new set to the console for visual conformation of method execution.
		//cout << x << endl;
		fout << x << endl;
	}
	// Return the set with totalCounter, all the words int the file, and the list of line counts.
	return TempSet;
}

set<Words> ReadFile()
{
	set<Words> WordsSet;
	const int kLineLength = 1024;
	const char kNewLineChar = '\n';
	string tempString = "";
	int userChoice;
	Words buff;
	string buff1 = "";
	string buff2 = "";
	char delem = ' ';
	ifstream fin;

	cout << "Please enter the number for the items you would like to analyze..." << endl;
	cout << "0. Apology | 1. ModestProposal | 2. ShortHistory | 3. WizardOfOz" << endl; // ShortHistory.txt throws out of range error for some reason.
	cin >> userChoice;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(kLineLength, kNewLineChar);
		cout << "Error: Selection not valid. Please Try again entering a value between 0 and 3..." << endl;
		cin >> userChoice;
	}
	fin.open(Resouce[userChoice]);
	cout << "Now opening " << Resouce[userChoice] << "...." << endl;
	// Make vector for lewis way of doing things
	//VecWords(userChoice);
	// While there is still a line to get in the file.
	while (getline(fin, buff1))
	{
		// Put the current line into a string stream.
		istringstream s(buff1);
		// While there is still an object to iterate over.
		while (getline(s, buff2, delem))
		{
			// Run the current object throught the remove punctuation loop.
			buff2 = RemovePunctuationLoop(buff2);
			// Set buff equal to the new object without punctuation.
			buff.SetWordObject(buff2);
			// Insert the word into the set.
			WordsSet.insert(buff);
		}
		// Print the word to the console for visual conformation of program execution.
		//cout << buff << endl;
	}
	fin.close();
	
	// Call the counter function for line and word counts.
	return Counter(WordsSet, userChoice);
}

int main()
{
	// Call the readFile method for intake of the users choice on a file name.
	// Parsing of the data within the file.
	// Removing of non ascii characters
	// Removing of the punctuation.
	// And counts of the word appearence and line numbers.
	ReadFile();

	return 0;
}