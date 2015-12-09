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


bool main()
	{
			

			ifstream file("cw4_20_cs.log");
			if (file.is_open())
			{
				string sentenceTypeArr[19];

				for (int i = 0; i < 19; ++i)
				{
					file >> sentenceTypeArr[i];
					cout << sentenceTypeArr[i] << '\n';


					std::string str2(",");

					std::size_t found = sentenceTypeArr[i].find(str2);
					if (found != std::string::npos)
						std::cout << "First ',' found at: " << found << '\n';


				}
			}
			else cout << "Unable to open file" << '\n';

		}