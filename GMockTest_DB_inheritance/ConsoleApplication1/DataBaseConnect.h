#pragma once
#include <string>
using namespace std;

class DataBaseConnect
{
private:
	int index;
public:
	DataBaseConnect();
	~DataBaseConnect();
	virtual bool login(std::string username, std::string password);
	virtual bool login2(std::string username, std::string password);
	virtual bool logout(std::string username);
	virtual int fetchRecord();
};

