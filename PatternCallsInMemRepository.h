#pragma once

#include "PatternCallsRepository.h"
#include "InMemoryIndexDb.h"
#include "PatternCallsFactory.h"

class PatternCallsInMemRepository :
	public PatternCallsRepository
{
public:
	PatternCallsInMemRepository(PatternCallsFactory& patterncallsdbfactory);
	~PatternCallsInMemRepository();

	InMemoryIndexDb *m_inMem = m_inMem->getInstance();

	int ParseFromFile(std::string filepath) override;
	bool Insert(PatternCallsData & patterndata) override;
	PatternCallsData FindByID(int id) override;
	std::vector<PatternCallsData> FindByUsername(std::string username) override;
	std::vector<PatternCallsData> FindByPatternFile(std::string patternfile) override;
	std::vector<PatternCallsData> FindByFlag(bool flag) override;


private:
	const InMemoryIndexDb * m_inMemoryDB; 
	const PatternCallsFactory& m_PatternCallsFactory;
};

