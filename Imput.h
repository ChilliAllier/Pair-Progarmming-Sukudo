#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class InputHandler {
public:
	void check(int argc, char** argv);

private:
	int isNum(const string& s);
};