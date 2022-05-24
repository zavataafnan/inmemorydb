#pragma once
#include <map> 
#include <vector>
#include "PatternCallsData.h"

class InMemoryIndexDb
{
public:
	
	static InMemoryIndexDb *getInstance() {
		if (!instance)
			instance = new InMemoryIndexDb;
		return instance;
	}

	~InMemoryIndexDb();

	int AddRecord(PatternCallsData & patterndata);
	PatternCallsData & GetRecord(int id);
	std::vector<PatternCallsData> GetUsername(std::string username);
	std::vector<PatternCallsData> GetPatternfiles(std::string patternname);
	std::vector<PatternCallsData> GetConvenientflag(bool convflag);

private:
	static InMemoryIndexDb *instance;
	std::map<int, PatternCallsData> m_PatternClassContainer;
	std::multimap<std::string, int> m_UserNameIndex;
	std::multimap<std::string, int> m_PatternFileIndex;
	std::multimap<bool, int> m_ConvFlagIndex;

	InMemoryIndexDb();
};

