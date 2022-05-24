#pragma once
#include <vector>

#include "PatternCallsData.h"

enum search_type {ID, USERNAME, FILENAME, CONVSTATUS};

class PatternCallsRepository
{
public:
	PatternCallsRepository();
	~PatternCallsRepository();

	virtual bool Insert(PatternCallsData & patterndata) = 0;
	virtual int ParseFromFile(std::string filepath) = 0;
	virtual PatternCallsData FindByID(int id) = 0;
	virtual std::vector<PatternCallsData> FindByUsername(std::string username) = 0;
	virtual std::vector<PatternCallsData> FindByPatternFile(std::string patternfile) = 0;
	virtual std::vector<PatternCallsData> FindByFlag(bool flag) = 0;
};

