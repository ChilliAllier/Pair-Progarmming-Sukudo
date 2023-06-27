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
        //�������û���ظ��ģ�����з���faulse
        for (int i = 0; i < board.size(); i++)
        {
            if (num == board[row][i] - '0')
            {
                return false;
            }
        }
        //�������û���ظ��ģ�����з���faulse
        for (int i = 0; i < board.size(); i++)
        {
            if (num == board[i][col] - '0')return false;
        }
        //����������ڵķ�����û���ظ��ģ�����з���faulse
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
        //С�Ź����е��к��н����������£��ֽ�����ʽ
        int choice[9][2] = { {0,1},{0,2},{1,2},{3,4},{3,5},{4,5},{6,7},{6,8},{7,8} };
        for (int j = rand() % 20; j < 30; j++)//�ʴ�����������Ҳ���Բ������ѭ�����ͽ���һ��
        {
            int i = rand() % 9;//ȡ0��8֮������ֵ
            cout << i << " ";
            board[choice[i][0]].swap(board[choice[i][1]]);//�����������
            swapCol(choice[i][0], choice[i][1], board);//�����������
        }
        selectBlank(blank, board);//�����Ѷȿ���ѡ��ͬ�����Ŀո�

    }


    bool dfs(vector<vector<char>>& board, int start)//�ӣ���ʼ���α���81�����ӣ����������
    {
        if (start == 81)//start=81��˵���Ѿ��ɹ��������
        {
            return true;
        }
        else
        {
            bool ok = false;
            int row = start / 9;//���ݴ�ʱ�������ţ�������˷�����к���
            int col = start % 9;
            if (board[row][col] == '$')
            {
                for (int i = 1; i <= 9; i++)
                {
                    if (isValid(row, col, i, board))//�ӣ��������η���ո񣬲��ж��Ƿ�Ϸ�
                    {
                        board[row][col] = i + '0';//��������ֺϷ�����д������ֵ��ַ�
                        ok = dfs(board, start + 1);//�жϴ˷������һ�������Ƿ�ɹ�д��
                        if (!ok)//���������һ�������ǲ��Ϸ��ģ�˵�����������������������ȷ�Ľ⣬�����
                        {
                            board[row][col] = '$';//����
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