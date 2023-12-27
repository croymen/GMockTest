#pragma once
#include "gmock/gmock.h"
#include "DataBaseConnect.h"

class DataBaseConnectMock : public DataBaseConnect
{

public:
	MOCK_METHOD0(fetchRecord, int());
	MOCK_METHOD1(logout, bool(std::string));
	MOCK_METHOD2(login, bool(std::string, string));	
	MOCK_METHOD2(login2, bool(std::string, string));
};
