#include "pch.h"
#include "../ConsoleApplication1/DataBaseConnectMock.cpp"
#include "../ConsoleApplication1/MyDatabase.cpp"
#include "../ConsoleApplication1/DataBaseConnect.cpp"
//cannot include .h will get linker error.

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

TEST(MyDatabaseTest, Login2) {
	//Arrange
	
	DataBaseConnectMock dbc;
	MyDatabase db(dbc);
	
	//MyDatabase db(new DataBaseConnectMock());
	
	//_ - any value can be used
	EXPECT_CALL(dbc, login(_, _))
		.Times(AtLeast(1))
		.WillOnce(Return(true));
	
	//Act
	int retval = db.Init("Terminator", "I' am back");	

		//dbc.login("a","b")

	//Assert
	//EXPECT_EQ(retval, 1);
}



