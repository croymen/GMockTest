#pragma once
#include "DataBaseConnect.h"

class MyDatabase
{
public:
	DataBaseConnect& _dbc;
public:
	MyDatabase(DataBaseConnect& dbc);
	//MyDatabase(DataBaseConnect & dbc) : _dbc(dbc) {};
	~MyDatabase();
	int Init(string username, string password);
	int Init2(string username, string password);	
	int Init3(string username, string password);
};

