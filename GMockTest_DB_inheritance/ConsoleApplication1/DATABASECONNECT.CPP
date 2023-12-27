#include <iostream>
#include "DataBaseConnect.h"

DataBaseConnect::DataBaseConnect()
{
    index = 0;
}

DataBaseConnect::~DataBaseConnect()
{
    index = 0;
}

bool DataBaseConnect::login(std::string username, std::string password)
{
    index++;
    //do some stuff and login and return true
    cout << "LOGIN" << index << endl;
    //cout << this << endl;
    return true;
}

bool DataBaseConnect::login2(std::string username, std::string password)
{
    cout << "LOGIN2" << index << endl;
    //cout << this << endl;
    return true;
}

bool DataBaseConnect::logout(std::string username)
{
    //do some stuff and succesfully logout
    cout << "logout" << endl;
    return true;
}

int DataBaseConnect::fetchRecord()
{
    cout << "fetch record" << endl;
    return -1;
}

