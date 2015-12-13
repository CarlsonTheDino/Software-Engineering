#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <list>
#include <fstream>
#include <sstream>
#include <algorithm>
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



// useful for part D:


// for part d, go through each string and find position of commas, use sub strings to exclude those locations and then concatenate the substrings


//{
//
//
//	ifstream file("cw4_20_cs.log");
//	if (file.is_open())
//	{
//		string sentenceTypeArr[19];
//
//		for (int i = 0; i < 19; ++i)
//		{
//			file >> sentenceTypeArr[i];
//			//cout << sentenceTypeArr[i] << '\n';
//
//
//			std::string str2("*");
//			std::size_t found = sentence.find(str2);
//			checksum = sentence.substr(found + 1, found + 2); // need to convert sentence to int
//			cout << checksum;
//			if (found != std::string::npos)
//				std::cout << "First * found at: " << found << '\n';
//
//
///*char check = 0;
	/*for (int i = 1; i < sentence.rfind('*'); i++)
	{
		std::cout << sentence[i];
		check = check ^ sentence[i] << '\n';

	}
	*/

		/*std::string str2("*");
		std::size_t found = sentence.find(str2);
		if (found != std::string::npos)
		std::cout << "First '*' found at: " << found + 1 << '\n';

		char checksum = 0;
		for (int i = 1; i > loopCounter; i++)
		{
		checksum = char(checksum ^ sentence[i]);
		cout << sentence[i];
		cout << checksum;
		}*/

		// ifstream file("cw4_20_cs.log");
		// if (file.is_open())
		// {

		//for (int i = 0; i < 19; ++i)
		//{
		//	file >> sentence;
		//	cout << sentenceTypeArr[i] << '\n';

//
//
//		}