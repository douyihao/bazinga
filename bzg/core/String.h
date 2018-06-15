#pragma once
#include <string>
#include <vector>

class String:public std::wstring
{
public:
	String(const std::string&);
	virtual ~String();
public:
	std::string to_utf8();
	std::string to_string();
	bool operator == (const std::string&);
	String operator = (const std::string&);
	bool equal(const String&,bool);
	std::vector<String> split(const String& older, const String& newer);
};

