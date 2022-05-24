/*
* FILE:          PatternCallsData.cpp
*  TITLE:         tuple data modeling
*  SUBMITTED BY:  Mostafa Jabaroutimoghaddam
*  HOMEWORK    CS 2020
*  DUE DATE:      July 29, 2020
*  PURPOSE
*  the data modeling for considering the pattern calls into a tuple consisting of
*  id, username, pattern file, flag
*
* OVERALL METHOD:
*  1- define data types: int id, string username, string pattern_file, bool flag
*  2- provide the copy constructor and copy assignement and equal assigment for comparing the two objects.
*/




#include "PatternCallsData.h"
#include <iostream>
/*
 default constructor, copy constructor, == operator , = operator
*/
PatternCallsData::PatternCallsData()
{
}

PatternCallsData::PatternCallsData(const PatternCallsData & other)
	: m_id(other.m_id), m_username(other.m_username), m_pattern_file(other.m_pattern_file), m_convenience_flag(other.m_convenience_flag)
{
	//std::cout << "copy constructor is calling" << std::endl;
}
bool PatternCallsData::operator==(const PatternCallsData& lh)
{
	return (m_id == lh.m_id 
		&& m_username == lh.m_username 
		&& m_pattern_file == lh.m_pattern_file 
		&& m_convenience_flag == lh.m_convenience_flag);
}

PatternCallsData & PatternCallsData::operator=(const PatternCallsData & other)
{
	//std::cout << "copy assignment is calling" << std::endl;

	if (this != &other) {
		m_id = other.m_id;
		m_username = other.m_username;
		m_pattern_file = other.m_pattern_file;
		m_convenience_flag = other.m_convenience_flag;
	}

	return *this;
}


PatternCallsData::PatternCallsData(int id, std::string username, std::string pattern_file, bool convenience_flag) 
	: m_id(id), m_username(username), m_pattern_file(pattern_file) , m_convenience_flag(convenience_flag)
{
}


PatternCallsData::~PatternCallsData()
{
	//std::cout << "decostructor is calling..." << std::endl;
}

/*
* set and get functions of private variables
*/
int PatternCallsData::GetID()
{
	return m_id;
}

std::string PatternCallsData::GetUsername()
{
	return m_username;
}

std::string PatternCallsData::GetPatternFile()
{
	return m_pattern_file;
}

bool PatternCallsData::GetConvenienceFlag()
{
	return m_convenience_flag;
}

void PatternCallsData::SetID(int id)
{
	m_id = id;
}

void PatternCallsData::SetUsername(std::string username)
{
	m_username = username;
}

void PatternCallsData::SetPatternFile(std::string patternfile)
{
	m_pattern_file = patternfile;
}

void PatternCallsData::SetConvenienceFlag(bool flag)
{
	m_convenience_flag = flag;
}
