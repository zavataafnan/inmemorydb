/*
* FILE:          InMemoryIndexDb.cpp
* TITLE:         In memory DB implementation and adaptor
* SUBMITTED BY:  Mostafa Jabaroutimoghaddam
* HOMEWORK    CS 2020
* DUE DATE:      July 29, 2020
* PURPOSE
* handling the tuples of PatternCallsData in map and indexing to gain complexity of O(1)
* 
* OVERALL METHOD:
* 1- handing and storing the objects to the map.
* 2- perform adding record to the map by considering the index.
* 3- query to in momery data storage by filtering as Id, username, pattern file, and flag.
* the modification of the tuples was not implementation that is not mentioned in the requirements of the project.
*/
 


#include "InMemoryIndexDb.h"
#include <vector>
#include <iostream>

InMemoryIndexDb::InMemoryIndexDb()
{
}


InMemoryIndexDb::~InMemoryIndexDb()
{
}


/*
* adding PatternCallsData with unique Id to the map. 
* index the inserted to the username, pattern file, and flag map.
*/

int InMemoryIndexDb::AddRecord(PatternCallsData & patterndata)
{
	try
	{
		size_t temp_size = m_PatternClassContainer.size();
		m_PatternClassContainer.insert({ patterndata.GetID(), patterndata });

		//now index the items
		if (temp_size < m_PatternClassContainer.size())
		{
			m_UserNameIndex.insert({ patterndata.GetUsername(), patterndata.GetID() });
			m_PatternFileIndex.insert({ patterndata.GetPatternFile(), patterndata.GetID() });
			m_ConvFlagIndex.insert({ patterndata.GetConvenienceFlag(), patterndata.GetID() });
		}

		if ((m_PatternClassContainer.size() != m_UserNameIndex.size()) ||
			(m_PatternClassContainer.size() != m_PatternFileIndex.size()) ||
			(m_PatternClassContainer.size() != m_ConvFlagIndex.size()))
		{
			throw std::exception("internal RAM error in indexing");
		}
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return 0;
}

PatternCallsData & InMemoryIndexDb::GetRecord(int id)
{
	return m_PatternClassContainer[id];
	// TODO: insert return statement here
}

/*
* query the in-memory database to retieve the Pattern Calls with the specific username
  at the first find, the available user name indexes and return vector of PatternCallsData  
*/
std::vector<PatternCallsData> InMemoryIndexDb::GetUsername(std::string username)
{
	std::vector <PatternCallsData> result;
	try
	{
		auto itr = m_UserNameIndex.equal_range(username);
		while (itr.first != itr.second)
		{
			PatternCallsData temp = m_PatternClassContainer[itr.first->second];
			itr.first++;
			result.push_back(temp);
		}
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return result;
}

/*
* query the in-memory database to retieve the Pattern Calls with the specific patternfile path
  at the first find, the available pattern pathes indexes and return vector of PatternCallsData
*/

std::vector<PatternCallsData> InMemoryIndexDb::GetPatternfiles(std::string patternfile)
{
	std::vector <PatternCallsData> result;
	try
	{
		auto itr = m_PatternFileIndex.equal_range(patternfile);
		while (itr.first != itr.second)
		{
			PatternCallsData temp = m_PatternClassContainer[itr.first->second];
			itr.first++;
			result.push_back(temp);
		}
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return result;
}

/*
* query the in-memory database to retieve the Pattern Calls with the specific convenient flag
  at the first find, the available convenient flag indexes and return vector of PatternCallsData
*/
std::vector<PatternCallsData> InMemoryIndexDb::GetConvenientflag(bool convflag)
{
	std::vector <PatternCallsData> result;
	try
	{
		auto itr = m_ConvFlagIndex.equal_range(convflag);
		while (itr.first != itr.second)
		{
			PatternCallsData temp = m_PatternClassContainer[itr.first->second];
			itr.first++;
			result.push_back(temp);

		}
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return result;
}
