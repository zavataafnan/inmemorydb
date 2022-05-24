#pragma once
#include <string>

class PatternCallsData
{
private:
	int m_id;
	std::string m_username;
	std::string m_pattern_file;
	bool m_convenience_flag;

public:
	PatternCallsData();
	PatternCallsData(const PatternCallsData& other);
	PatternCallsData& operator=(const PatternCallsData& other);
	bool operator==(const PatternCallsData& lh);


	PatternCallsData(int id, std::string username, std::string pattern_file, bool convenience_flag);
	~PatternCallsData();

	int GetID();
	std::string GetUsername();
	std::string GetPatternFile();
	bool GetConvenienceFlag();


	void SetID(int id);
	void SetUsername(std::string username);
	void SetPatternFile(std::string patternfile);
	void SetConvenienceFlag(bool flag);
};

