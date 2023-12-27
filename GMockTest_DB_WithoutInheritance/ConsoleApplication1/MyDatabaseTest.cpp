#include "gmock/gmock.h"
#include "DataBaseConnect.cpp"
#include "MyDatabase.h"
//cannot include .h will get linker error.

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

TEST(MyDatabaseTest, Login) {
	//Arrange	
	DataBaseConnect dbc;
	MyDatabase db(dbc);	
	
	//_ - any value can be used
	EXPECT_CALL(dbc, login(_, _))
		.Times(AtLeast(1))
		.WillOnce(Return(true));

	//Act	
	int retval = db.Init("Terminator", "I' am back");	

	//Assert
	EXPECT_EQ(retval, 1);
}

TEST(MyDatabaseTest, LoginOnCall_False) {
	//Arrange
	DataBaseConnect dbc;
	MyDatabase db(dbc);

	//Is passed even if login is not called.
	ON_CALL(dbc, login(_, _)).WillByDefault(Return(false));

	//Act
	cout << "Login done without usage of Init method";
	int retval = 1;
	//Assert
	EXPECT_EQ(retval, 1);
}

TEST(MyDatabaseTest, LoginOnCall_random) {
	//Arrange
	DataBaseConnect dbc;
	MyDatabase db(dbc);

	// If it is called, then it is checked.
	// on_call if we do not know whether the function A or B will be called.
	ON_CALL(dbc, login(_, _)).WillByDefault(Return(true));
	ON_CALL(dbc, login2(_, _)).WillByDefault(Return(true));

	//Act
	int retval = db.Init3("Terminator", "I' am back");
	
	//Assert
	EXPECT_EQ(retval, 1);
}

TEST(MyDatabaseTest, LoginFailure) {
	//Arrange

	DataBaseConnect dbc;
	MyDatabase db(dbc);	
	
	//_ - any value can be used
	EXPECT_CALL(dbc, login(_, _))
		.Times(AtLeast(1))
		.WillOnce(Return(false));
		
	//Act
	int retval = db.Init("Terminator", "I' am back");

	//Assert
	EXPECT_EQ(retval, -1);
}

TEST(MyDatabaseTest, LoginFailure2) {
	//Arrange
	DataBaseConnect dbc;
	MyDatabase db(dbc);

	//_  any value can be used
	// say how login method should behave - will return false
	EXPECT_CALL(dbc, login(_, _))
		.Times(2)
		.WillRepeatedly(Return(false));

	//Act
	int retval = db.Init2("Terminator", "I' am back");

	//Assert
	EXPECT_EQ(retval, -1);
}


