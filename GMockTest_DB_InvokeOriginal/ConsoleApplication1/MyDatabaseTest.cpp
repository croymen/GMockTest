#include "gmock/gmock.h"
#include "DataBaseConnectMock.cpp"
#include "MyDatabase.h"
#include "DataBaseConnect.h"
#include "TestABC.cpp";

//cannot include .h will get linker error.

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;
using ::testing::Invoke;
using ::testing::DoDefault;
using testing::DoAll;
//using ::testing::InvokeWithoutArgs;

TEST(MyDatabaseTest, InvokeOriginalMethod) {
	//Arrange	
	DataBaseConnectMock dbc;
	MyDatabase db(dbc);	
	DataBaseConnect dbcTest;
	TestABC abc;
	
	//Invoke vola pres Mock objekt originalni implementaci
	EXPECT_CALL(dbc, login(_, _))
		.Times(AtLeast(1))				
		.WillOnce(Invoke(&dbcTest, &DataBaseConnect::login));		

	//Act	
	int retval = db.Init("Terminator", "I' am back");		

	//Assert
	EXPECT_EQ(retval, 1);
}

TEST(MyDatabaseTest, InvokeAnotherOriginalMethod) {
	//Arrange	
	DataBaseConnectMock dbc;
	MyDatabase db(dbc);
	DataBaseConnect dbcTest;
	TestABC abc;

	// call dummy login method via Mock dbc
	EXPECT_CALL(dbc, login(_, _))
		.Times(AtLeast(1))
		.WillOnce(Invoke(&abc, &TestABC::dummyLogin));

	//Act	
	int retval = db.Init("Terminator", "I' am back");	

	//Assert
	EXPECT_EQ(retval, 1);
}

TEST(MyDatabaseTest, DefaultInvokeOnCall) {
	//Arrange	
	DataBaseConnectMock dbc;
	MyDatabase db(dbc);
	DataBaseConnect dbcTest;
	TestABC abc;

	//Call dummyLogin instead of every login call
	ON_CALL(dbc, login(_, _)).WillByDefault(Invoke(&abc, &TestABC::dummyLogin));
	
	// check whether the default method was called	
	EXPECT_CALL(dbc, login(_, _))
		.Times(AtLeast(1))
		.WillOnce(DoDefault());			

	//Act	
	int retval = db.Init("Terminator", "I' am back");

	//Assert
	EXPECT_EQ(retval, 1);
}

TEST(MyDatabaseTest, InvokeMultipleActions) {
	//Arrange	
	DataBaseConnectMock dbc;
	MyDatabase db(dbc);
	DataBaseConnect dbcTest;
	TestABC abc;

	//All actions should return void, only the last called function should return value( Return(true) or e.g. original method returning value,...)
	EXPECT_CALL(dbc, login(_, _))
		.Times(AtLeast(1))
		.WillOnce(DoAll(Invoke(&abc, &TestABC::dummyLogin), Invoke(&abc, &TestABC::dummyLogin), Return(true)));

	//Act	
	int retval = db.Init("Terminator", "I' am back");

	//Assert
	EXPECT_EQ(retval, 1);
}



