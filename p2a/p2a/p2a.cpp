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
int loop_Count = 0;
using namespace std;
string sentenceTypeArr[49];
string sentence = "$GPLA,432432,34234,324234,324*89";
bool main()
{

	{


		ifstream file("cw4_20_cs.log");
		if (file.is_open())
		{
			string sentenceTypeArr[19];

			//for (int i = 0; i < 19; ++i)
			//{
			//	file >> sentence;
			//	cout << sentenceTypeArr[i] << '\n';


			std::string str2("*");

			std::size_t found = sentence.find(str2);
			if (found != std::string::npos)
				std::cout << "First '*' found at: " << found + 1 << '\n';


			char checksum = 0;
			for (int i = 1; i > found; i++)
			{
				checksum = char(checksum ^ sentence[i]);
			}
			
			std::string newChecksum = (hex)checksum;

			//}
		}
		else cout << "Unable to open file" << '\n';

		

	}
}
