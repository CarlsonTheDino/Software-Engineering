// p2a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <list>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
#include <numeric>
#include <functional>
#include <iostream>
#include <stdio.h>
#include <string>
#include <list>
#include <fstream>
#include <sstream>
#include <utility>
int loop_Count = 0;
using namespace std;
std::string stringArray[19];
char checksum = 0;
string sentence = "$GPGLL,5425.31,N,107.09,W,82446*62";
int commLoc; // Stores locations of each comma within the string
int commLoc_Two;
int commLoc_Three;
int commLoc_Four;
int commLoc_Five;
int checkSumLoc;
string sentenceTypeLoc;
string sentenceType;
string str2(",");
using std::hex;
int loopCounter = 0;
using namespace std;
std::string sentence = "$GPGLL,5425.31,N,107.09,W,82446*62";
bool valid;
bool p2a(const std::string & sentence)
{



	valid = true;
	if (sentence[0] != '$');
	{
		valid = false;
	}

	{

		int i = 1;
		int checkSum = 0;
		string hexFirst;
		string hexLast;
		while (i < sentence.size())
		{
			if (sentence[i] == '*')
			{
				hexFirst = sentence[i + 1];
				hexLast = sentence[i + 2];
			}
			else
			{
				checkSum ^= sentence[i];
			}
			hexFirst = sentence[i + 1];
			hexLast = sentence[i + 2];
			++i;


			int firstVal = (atoi(hexFirst.c_str())) * 16;
			int lastVal = (atoi(hexLast.c_str()));
			int value = firstVal + lastVal;
			if (checkSum == value)
			{
				valid = true;
			}
			return valid;
		}
	}

	bool p2b(const std::string & sentence)

	{

		if valid = true;
		{
			for (int i = 7; i < sentence.size(); ++i)
			{
				std::string str3("*");
				std::size_t commLoc = sentence.find(str2);
				std::size_t checkSumLoc = sentence.find(str3);
				sentenceType = sentence.substr(0, commLoc);
			}

			string substr_1 = sentence.substr(0, 5);
			string substr_2 = sentence.substr(7, 7);
			string substr_3 = sentence.substr(15, 1);
			string substr_4 = sentence.substr(17, 6);
			string substr_5 = sentence.substr(24, 1);
			string substr_6 = sentence.substr(26, 5);

			list <string> list1;

			list1.push_back(substr_1);
			list1.push_back(substr_2);
			list1.push_back(substr_3);
			list1.push_back(substr_4);
			list1.push_back(substr_5);
			list1.push_back(substr_6);


			std::pair<std::string, std::list<std::string>> P2Pair;
			P2Pair = std::make_pair(sentenceType, list1);
			return P2Pair;


		}

	}
