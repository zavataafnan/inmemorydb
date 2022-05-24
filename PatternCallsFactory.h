#pragma once
#include <memory>

#include "PatternCallsData.h"

class PatternCallsFactory
{
public:
	PatternCallsFactory();
	~PatternCallsFactory();
	virtual std::shared_ptr<PatternCallsData> CreatePatternCallsData(const std::string& _linestring) const = 0;
};

