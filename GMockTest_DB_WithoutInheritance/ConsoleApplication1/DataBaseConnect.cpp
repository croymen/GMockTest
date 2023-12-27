#pragma once
#include "gmock/gmock.h"

class DataBaseConnect //: public DataBaseConnect
{

public:
	MOCK_METHOD0(fetchRecord, int());
	MOCK_METHOD1(logout, bool(std::string));	
	MOCK_METHOD2(login, bool(std::string, std::string));
	MOCK_METHOD2(login2, bool(std::string, std::string));
};
