#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Sudoku.h"

using namespace std;

class InputHandler {
public:
	void check(int argc, char** argv);

private:
	int isNum(const string& s);
};