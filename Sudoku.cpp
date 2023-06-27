
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




void outputSudokus(vector<vector<char>>& board) { //������д���ļ�
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

void createSukudoFinals(int n) { //����ָ����������������
    //sudoku** sudokuList = new sudoku*[n];
    for (int i = 0; i < n; i++) {
        vector<vector<char>>blank(9, vector<char>(9, '$'));
        sudoku s(blank);
        s.create(0, blank);
        outputSudokus(blank);
    }
}

void createSukudoGames(int blanks,int n) { //���ڿ�������������Ϸ
    //sudoku** sudokuList = new sudoku*[n];
    for (int i = 0; i < n; i++) {
        vector<vector<char>>blank(9, vector<char>(9, '$'));
        sudoku s(blank);
        s.create(blanks, blank);
        outputSudokus(blank);
    }
}

void createSukudoGamesByDiff(int Diff, int n) { //���Ѷ�����������Ϸ
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
//    vector<vector<char>>blank(9, vector<char>(9, '$'));//����һ��9*9�Ŀն�ά����
//    srand(time(NULL));//���ö�̬����
//    sudoku s(blank);
//    s.create(50, blank);//����50���ո������
//    if (s.active)
//    {
//        cout << "����������Ϊ��" << endl;
//        s.printBoard(blank);
//    }
//    else
//        cout << "�������Ϸ���û�н⣡" << endl;
//    s.dfs(blank, 0);//����������
//    if (s.active)
//    {
//        cout << "�������Ľ��ǣ�" << endl;
//        s.printBoard(blank);
//        outputSudokus(blank);
//    }
// 
//    else
//        cout << "����ʧ�ܣ�" << endl;
// 
//    createSukudoGamesByDiff(3, 10);
//    return 0;
//}
//
