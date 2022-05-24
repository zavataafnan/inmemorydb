/*
 * FILE:          PatternCallsDbFactory.cpp
 * TITLE:         creating an object
 * SUBMITTED BY:  Mostafa Jabaroutimoghaddam
 * HOMEWORK    CS 2020
 * DUE DATE:      July 29, 2020
 * PURPOSE
 * creating PattternCallsData from a string reading from the input file.
 *
 *
 * OVERALL METHOD:
 * 1- it was inherited from PatternCallsFactory.cpp
 * 2- create the object from string
 * 3- it was implemented for further modification of projects to add more capabilities.
*/

#include <memory>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

#include "PatternCallsDbFactory.h"


PatternCallsDbFactory::PatternCallsDbFactory()
{
}


PatternCallsDbFactory::~PatternCallsDbFactory()
{
}

/*
create the pattern calls class from a line that is available in the input text file.
*/
std::shared_ptr<PatternCallsData> PatternCallsDbFactory::CreatePatternCallsData(const std::string& _linestring) const
{
	auto result = std::make_shared<PatternCallsData>();
	try
	{
		
		std::vector <std::string> tokens_with_delimeter;
		std::string intermediate;
		char demilater{ ',' };
		std::istringstream tokenStream(_linestring);
		while (std::getline(tokenStream, intermediate, demilater))
		{
			tokens_with_delimeter.push_back(intermediate);
		}

		if (tokens_with_delimeter.size() < 4)
		{
			throw std::runtime_error("Invalid Line in the input files");
		}
		result->SetID(std::stoi(tokens_with_delimeter[0], nullptr, 10));
		result->SetUsername(tokens_with_delimeter[1]);
		result->SetPatternFile(tokens_with_delimeter[2]);
		result->SetConvenienceFlag(tokens_with_delimeter[3] == "true" ? true : false);
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return result;
	//parse line
}
