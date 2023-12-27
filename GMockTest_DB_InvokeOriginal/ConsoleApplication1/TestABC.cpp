#include <iostream>;

using namespace std;

struct TestABC {
	bool dummyLogin(string a, string b) {
		cout << "Dummy login gets called." << endl;
		return true;
	}
};