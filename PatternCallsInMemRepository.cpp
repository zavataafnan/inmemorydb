/*
* FILE:          PatternCallsRepository.cpp
*  TITLE:         creating an object
*  SUBMITTED BY:  Mostafa Jabaroutimoghaddam
*  HOMEWORK    CS 2020
*  DUE DATE:      July 29, 2020
*  PURPOSE
*  the reposity base class for connection to different module of the program
*
*
* OVERALL METHOD:
*  1- It is inherited from PatternCallsRepository to commuicate to the DB.
*/


#include <fstream>
#include <iostream>
#include <sstream>

#include "PatternCallsInMemRepository.h"

PatternCallsInMemRepository::PatternCallsInMemRepository(PatternCallsFactory & patterncallsdbfactory)
	:m_PatternCallsFactory(patterncallsdbfactory)
{
}

PatternCallsInMemRepository::~PatternCallsInMemRepository()
{

}

/*
parse a text file and send to the factory to create the objects and add it to in memory database.
*/
int PatternCallsInMemRepository::ParseFromFile(std::string filepath)
{
	std::ifstream infile(filepath);
	std::string line;

	try
	{
		while (std::getline(infile, line))
		{
			std::istringstream iss(line);
			std::shared_ptr<PatternCallsData> temp = m_PatternCallsFactory.CreatePatternCallsData(line);
			m_inMem->AddRecord(*temp);
		}
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}

	infile.close();
	return 0;
}

/*
Implementing adaptor design pattern to excecute the in-memory objects.
*/

PatternCallsData  PatternCallsInMemRepository::FindByID(int id)
{
	return m_inMem->GetRecord(id);
}

std::vector<PatternCallsData> PatternCallsInMemRepository::FindByUsername(std::string username)
{
	return m_inMem->GetUsername(username);
}

std::vector<PatternCallsData> PatternCallsInMemRepository::FindByPatternFile(std::string patternfile)
{
	return m_inMem->GetPatternfiles(patternfile);
}

std::vector<PatternCallsData> PatternCallsInMemRepository::FindByFlag(bool flag)
{
	return m_inMem->GetConvenientflag(flag);
}

bool PatternCallsInMemRepository::Insert(PatternCallsData & patterndata)
{
	m_inMem->AddRecord(patterndata);
	return true;
}


