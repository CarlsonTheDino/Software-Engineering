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
string sentenceTypeArr[19];
int commLoc;


bool main()
	{
			

			ifstream file("cw4_20_cs.log");
			if (file.is_open())
			{

				for (int i = 0; i < 19; ++i)
				{
					file >> sentenceTypeArr[i];
					cout << sentenceTypeArr[i] << '\n';


					std::string value(",");
					std::size_t found = sentenceTypeArr[i].find(value);
					if (found != std::string::npos)
						//std::cout << "First ',' found at: " << found << '\n';
						 int commLocation = found;

				}
				}
				else cout << "Unable to open file" << '\n';
			
				
				std::pair <std::string, double> product1;

				product1 = std::make_pair(std::string("lightbulbs"), 0.99);

				
				commLoc = sentenceTypeArr[5].find_first_of(',');
				cout << commLoc << '\n';

				sentenceTypeArr[5].substr;
				cout << sentenceTypeArr[5];
				
			}
			