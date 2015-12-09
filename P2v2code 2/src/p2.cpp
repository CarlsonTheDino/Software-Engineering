//
//  p2.cpp
//  
//
//  Created by Ashley Thompson 2014 (N0569351) on 30/11/2015.
//
//

#include <stdio.h>
#include <string>
#include <list>
#include <pair>
#include <fstream>
#include "posn.h"
#include "p2.h"
#include <sstream>




main()
{
	std::ifstream infile("cw4_cs.log")
	std::string line;
		while (std::getline(infile, line))
		{
			std::istringstream iss(line);
			int a, b;
			if (!(iss >> a >> b)) { break; }

		}
}

//namespace P2
//{
//    bool P2:p2a(const std::string & sentence);
//    {
//		ofstream myfile;
//		myfile.open("cw4_cs.log")
//    }
//    
//    
//    
//    
//    
//    P2:p2b(const std::string & sentence);
//    {
//        
//
//
//    }
//    
//
//    P2:P2c(P2Pair);
//    {
//        
//    }
//    
//    
//    
//    
//    std:vector<P2::Posn> p2d(const std::string & logFileName);
//    {
//        
//    }
//    
//}
//    
//    
//    
//    
//    
//    
//    namespace routeFromNMEALog()
//    {
//        
//    }
//    
//    
//    
//    
//}

