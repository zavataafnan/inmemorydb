#pragma once
#include "PatternCallsFactory.h"
class PatternCallsDbFactory :
	public PatternCallsFactory
{
public:
	PatternCallsDbFactory();
	~PatternCallsDbFactory();

	std::shared_ptr<PatternCallsData> CreatePatternCallsData(const std::string& _linestring) const;
};

