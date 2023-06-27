#include "Imput.h"


void InputHandler::check(int argc, char** argv) {
	if (argc == 3) {
		string parameter1 = argv[1];
		string parameter2 = argv[2];
		if (parameter1 == "-c") { // -c
			int n = isNum(parameter2);
			if (n <= 0 || n > 1000000)
				cout << "不满足0<n<=1000000！" << endl;
			else {
				createSukudoFinals(n);
			}
		}
		else if (parameter1 == "-s") {
			ifstream in(parameter2);
			if (!in.is_open()) {
				cout << parameter2 + "无法打开！" << endl;
				return;
			}
			char c;
			int count = 0;
			FILE* out = fopen("sudoku.txt", "wt");
			while (in.get(c)) {	//in >> c 会忽略空白回车符
				vector<vector<char>>blank(9, vector<char>(9, '$'));
				if (isdigit(c)|| c == '$') {
					blank[count / 9][count % 9] = c;
				}
				if (count == 81) {
					count = 0;
					sudoku s(blank);
					s.dfs(blank, 0);//解数独函数
					if (s.active)
					{
						outputSudokus(blank);
					}
				}
			}
		}
		else if (parameter1 == "-n") { //-n 默认挖空30个
			int n = isNum(parameter2);
			if (n <= 0 || n > 10000)
				cout << "不满足0<n<=10000！" << endl;
			else {
				createSukudoGames(30, n);
			}
		}

		
	}
	else if (argc == 5) {
		string parameter1 = argv[1];
		string parameter2 = argv[2];
		string parameter3 = argv[3];
		string parameter4 = argv[4];
		if (parameter1 == "-n") {
			if (parameter3 == "-m") {
				int n = isNum(parameter2);
				int diff = isNum(parameter4);
				if (n <= 0 || n > 10000)
					cout << "不满足0<n<=10000！" << endl;
				else if (diff < 1 || diff > 3)
					cout << "不满足1<diff<3！" << endl;
				else {
					createSukudoGamesByDiff(diff, n);
				}
			}
			else if (parameter3 == "-r") {
				int n = isNum(parameter2);
				int blanks = isNum(parameter4);
				if (n <= 0 || n > 10000)
					cout << "不满足0<n<=10000！" << endl;
				else if(blanks < 20 || blanks > 55)
					cout << "不满足20<blanks<55！" << endl;
				else {
					createSukudoGames(blanks, n);
				}
			}
		}
	}
}

int InputHandler::isNum(const string& s) { //将输入的数字转换为int类型
	size_t size = s.size();
	if (size > 7)
		return 0;
	for (size_t i = 0; i < size; i++) {
		int ascii = int(s[i]);
		if (ascii >= 48 && ascii <= 57)
			continue;
		else
			return 0;
	}
	return stoi(s);
}