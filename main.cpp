/*
* FILE:          PatternCallsData.cpp
*  TITLE:         tuple data modeling
*  SUBMITTED BY:  Mostafa Jabaroutimoghaddam
*  HOMEWORK    CS 2020
*  DUE DATE:      July 29, 2020
* PURPOSE
*  main routine of the program. That is not needed in this stage.
*  there is another test program.
*/


#include <iostream>
#include <fstream>
#include "PatternCallsInMemRepository.h"
#include "PatternCallsFactory.h"
#include "PatternCallsData.h"
#include "PatternCallsDbFactory.h"

#include <random>
#include <functional> 
#include <algorithm>

InMemoryIndexDb *InMemoryIndexDb::instance = 0;

int main()
{
	/*
	PatternCallsDbFactory patternCallsFactory;
	PatternCallsInMemRepository patternCalls(patternCallsFactory);

	patternCalls.ParseFromFile(R"(d:\example.txt)");


	std::cout << "FIND BY USERNAME" << std::endl << std::endl;
	std::vector<PatternCallsData> temp = patternCalls.FindByUsername("my test3");
	for (auto itr = temp.begin(); itr != temp.end(); itr++)
	{
		PatternCallsData tr = *itr;

		std::cout << "ID: " << tr.GetID() << "  USERNAME: " << tr.GetUsername() << "  PATTERNFILE: " << tr.GetPatternFile()
			<< "  FLAG: " << tr.GetConvenienceFlag() << std::endl;
	}
	*/

	return 0;
}


