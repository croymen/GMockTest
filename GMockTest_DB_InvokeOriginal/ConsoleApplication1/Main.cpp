// GTest_ConsoleApp.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <gmock/gmock.h>

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

int main(int argc, char** argv) {
	// The following line must be executed to initialize Google Mock
	// (and Google Test) before running the tests.
	//testing::InitGoogleTest(&argc, argv);
	testing::InitGoogleMock(&argc, argv);	
	return RUN_ALL_TESTS();
}

