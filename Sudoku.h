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
using namespace std;
class sudoku
{
public:
    bool active = false;
    sudoku(vector<vector<char>>& board)
    {
        // printBoard(board);
        active = dfs(board, 0);

    }
    void printBoard(vector<vector<char>>& board)
    {
        cout << " |---|---|---|---|---|---|---|---|---| " << endl;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
            {
                cout << " | " << board[i][j];
            }
            cout << endl;
            cout << "  ---|---|---|---|---|---|---|---|---| " << endl;
        }
    }
    bool isValid(int row, int col, int num, vector<vector<char>>& board)
    {
        //检查行有没有重复的，如果有返回faulse
        for (int i = 0; i < board.size(); i++)
        {
            if (num == board[row][i] - '0')
            {
                return false;
            }
        }
        //检查列有没有重复的，如果有返回faulse
        for (int i = 0; i < board.size(); i++)
        {
            if (num == board[i][col] - '0')return false;
        }
        //检查数字所在的方块有没有重复的，如果有返回faulse
        int startrow = row / 3 * 3;
        int startcol = col / 3 * 3;
        int endrow = startrow + 3;
        int endcol = startcol + 3;
        for (int i = startrow; i < endrow; i++)
        {
            for (int j = startcol; j < endcol; j++)
            {
                if (num == board[i][j] - '0')return false;
            }
        }
        return true;

    }
    void swapCol(int m, int n, vector<vector<char>>& board)
    {
        vector<char>temp(board.size(), ' ');
        for (int i = 0; i < board.size(); i++)
        {
            temp[i] = board[i][m];
            board[i][m] = board[i][n];
            board[i][n] = temp[i];
        }
    }

    void selectBlank(int nums, vector<vector<char>>& board)
    {
        while (nums)
        {
            int row = rand() % 9;
            int col = rand() % 9;
            if (board[row][col] != '$')
            {
                board[row][col] = '$';
                nums--;
            }
        }
    }

    void create(int blank, vector<vector<char>>& board)
    {
        //小九宫格中的行和列交换，有以下９种交换方式
        int choice[9][2] = { {0,1},{0,2},{1,2},{3,4},{3,5},{4,5},{6,7},{6,8},{7,8} };
        for (int j = rand() % 20; j < 30; j++)//Ｊ代表交换次数，也可以不用这个循环，就交换一次
        {
            int i = rand() % 9;//取0－8之间的随机值
            cout << i << " ";
            board[choice[i][0]].swap(board[choice[i][1]]);//随机交换两行
            swapCol(choice[i][0], choice[i][1], board);//随机交换两列
        }
        selectBlank(blank, board);//根据难度可以选择不同数量的空格

    }


    bool dfs(vector<vector<char>>& board, int start)//从０开始依次遍历81个格子，计算此数独
    {
        if (start == 81)//start=81，说明已经成功解出数独
        {
            return true;
        }
        else
        {
            bool ok = false;
            int row = start / 9;//根据此时方格的序号，计算出此方格的行和列
            int col = start % 9;
            if (board[row][col] == '$')
            {
                for (int i = 1; i <= 9; i++)
                {
                    if (isValid(row, col, i, board))//从１－９依次放入空格，并判断是否合法
                    {
                        board[row][col] = i + '0';//如果有数字合法，就写入该数字的字符
                        ok = dfs(board, start + 1);//判断此方格的下一个方格是否成功写入
                        if (!ok)//如果它的下一个方格是不合法的，说明它现在填入的数，不是正确的解，需回溯
                        {
                            board[row][col] = '$';//回溯
                        }
                    }
                }
            }
            else
            {
                ok = dfs(board, start + 1);
            }
            return ok;
        }


    }
};
void createSukudoFinals(int n);
void outputSudokus(vector<vector<char>>& board);
void createSukudoGames(int blanks, int n);
void createSukudoGamesByDiff(int Diff, int n);