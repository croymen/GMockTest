#include "DataBaseConnect.cpp"
#include <iostream>
#include "MyDatabase.h"

MyDatabase::MyDatabase(DataBaseConnect& dbc)  : _dbc(dbc)
{
	//_dbc = dbc; //not needed because it is done in definition - no other way
}

MyDatabase::~MyDatabase()
{
}

int MyDatabase::Init(string username, string password)
{
	int ret = -1;
	if (_dbc.login(username, password)) {		
		cout << "DB SUCCESS" << endl;
		ret = 1;
	}
	else {
		cout << "DB FAILURE" << endl;
	}
	return ret;
}

int MyDatabase::Init2(string username, string password)
{	
	if (!_dbc.login(username, password)) {
		//try something else a try again.
		if (!_dbc.login(username, password)) {
			cout << "DB FAILURE 2nd Time" << endl;			
			return -1;
		}		
	}
	else {
		cout << "DB SUCCESS" << endl;
		return 1;
	}	
}

int MyDatabase::Init3(string username, string password)
{
	int rVal = rand() % 2;
	if (rVal == 0) { // IF EVEN - sude
		if (!_dbc.login(username, password)) {
			//try something else a try again.
			if (!_dbc.login(username, password)) {
				cout << "DB FAILURE 2nd Time" << endl;
				return -1;
			}
			else {
				cout << "DB SUCCESS" << endl;
				return 1;
			}
		}
	}
	else {
		_dbc.login2(username, password);
		return 1;
	}	
}

