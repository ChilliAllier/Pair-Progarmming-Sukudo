
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <algorithm>
#include<Windows.h>
#include <time.h>
#include <random>
#include "Sudoku.h"

using namespace std;




void outputSudokus(vector<vector<char>>& board) { //把数独写入文件
    FILE* out = fopen("sudoku.txt", "a+");
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            fputc('|', out);
            fputc(board[i][j], out);

        }
        fputc('|', out);
        fputc('\n', out);
    }
    fputc('\n', out);
}

void createSukudoFinals(int n) { //生成指定数量的数独终盘
    //sudoku** sudokuList = new sudoku*[n];
    for (int i = 0; i < n; i++) {
        vector<vector<char>>blank(9, vector<char>(9, '$'));
        sudoku s(blank);
        s.create(0, blank);
        outputSudokus(blank);
    }
}

void createSukudoGames(int blanks,int n) { //按挖空数生成数独游戏
    //sudoku** sudokuList = new sudoku*[n];
    for (int i = 0; i < n; i++) {
        vector<vector<char>>blank(9, vector<char>(9, '$'));
        sudoku s(blank);
        s.create(blanks, blank);
        outputSudokus(blank);
    }
}

void createSukudoGamesByDiff(int Diff, int n) { //按难度生成数独游戏
    if (Diff == 1)
        createSukudoGames(20, n);
    else if (Diff == 2)
        createSukudoGames(35, n);
    else if (Diff == 3)
        createSukudoGames(50, n);
}

//int main()
//{
//    /*vector<vector<char>>board = { vector<char>{'5','3','.','.','7','.','.','.','.'},
//                                  vector<char>{'6','.','.','1','9','5','.','.','.'},
//                                  vector<char>{'.','9','8','.','.','.','.','6','.'},
//                                  vector<char>{'8','.','.','.','6','.','.','.','3'},
//                                  vector<char>{'4','.','.','8','.','3','.','.','1'},
//                                  vector<char>{'7','.','.','.','2','.','.','.','6'},
//                                  vector<char>{'.','6','.','.','.','.','2','8','.'},
//                                  vector<char>{'.','.','.','4','1','9','.','.','5'},
//                                  vector<char>{'.','.','.','.','8','.','.','7','9'}, };*/
//
//    vector<vector<char>>blank(9, vector<char>(9, '$'));//创建一个9*9的空二维数组
//    srand(time(NULL));//设置动态种子
//    sudoku s(blank);
//    s.create(50, blank);//创建50个空格的数独
//    if (s.active)
//    {
//        cout << "创建的数独为：" << endl;
//        s.printBoard(blank);
//    }
//    else
//        cout << "数独表不合法，没有解！" << endl;
//    s.dfs(blank, 0);//解数独函数
//    if (s.active)
//    {
//        cout << "此数独的解是：" << endl;
//        s.printBoard(blank);
//        outputSudokus(blank);
//    }
// 
//    else
//        cout << "解题失败！" << endl;
// 
//    createSukudoGamesByDiff(3, 10);
//    return 0;
//}
//
