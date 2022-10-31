
#include <bits/stdc++.h>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

//////////////////////////////
//////////////////////////////
//////////////////////////////
class Solution
{
private:
    string possible[81]
    {
        "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789",
        "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789",
        "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789",
        "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789",
        "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789",
        "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789",
        "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789",
        "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789",
        "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789",
    };
    /*****************************************/
    void direct_extract_number(size_t colum, size_t row, char c)
    {
        size_t cube_row;
        size_t cube_colum;
        size_t index = (colum * 9) + row;
        size_t i;
        possible[index].erase();
        for(i = 0; i < 9; i++)
        {
            index = (colum * 9) + i;
            possible[index].erase(remove(possible[index].begin(), possible[index].end(), c), possible[index].end());
            index = (i * 9) + row;
            possible[index].erase(remove(possible[index].begin(), possible[index].end(), c), possible[index].end());
            cube_row = ((row / 3) * 3) + (i % 3);
            cube_colum = ((colum / 3) * 3) + (i / 3);
            index = (cube_colum * 9) + cube_row;
            possible[index].erase(remove(possible[index].begin(), possible[index].end(), c), possible[index].end());
        }
    }
    /*****************************************/
    void releated_extract_number(void)
    {
        size_t row, cube_row;
        size_t colum, cube_colum;
        size_t index;
        size_t subindex;
        size_t i;

        for(colum = 0; colum < 9; colum++)
        {
            for(row = 0; row < 9; row++)
            {
                index = (colum * 9) + row;
                for(char c : possible[index])
                {
                    if(c)
                    {
                        for(i = 0; i < 9; i++)
                        {
                            subindex = (colum * 9) + i;
                            if(index != subindex)
                            {
                                if(possible[subindex].find(c) != string::npos)
                                {
                                    break;
                                }
                            }
                        }
                        if(i == 9)
                        {
                            possible[index].erase();
                            possible[index].push_back(c);
                        }
                        for(i = 0; i < 9; i++)
                        {
                            subindex = (i * 9) + row;
                            if(index != subindex)
                            {
                                if(possible[subindex].find(c) != string::npos)
                                {
                                    break;
                                }
                            }
                        }
                        if(i == 9)
                        {
                            possible[index].erase();
                            possible[index].push_back(c);
                        }
                        for(i = 0; i < 9; i++)
                        {
                            cube_row = ((row / 3) * 3) + (i % 3);
                            cube_colum = ((colum / 3) * 3) + (i / 3);
                            subindex = (cube_colum * 9) + cube_row;
                            if(index != subindex)
                            {
                                if(possible[subindex].find(c) != string::npos)
                                {
                                    break;
                                }
                            }
                        }
                        if(i == 9)
                        {
                            possible[index].erase();
                            possible[index].push_back(c);
                        }
                    }
                }
            }
        }
    }
    /*****************************************/
    bool find_number(vector<vector<char>> &board)
    {
        size_t row, cube_row;
        size_t colum, cube_colum;
        size_t match;
        char c, res;
        bool solve = false;
        for(colum = 0; colum < 9; colum++)
        {
            for(row = 0; row < 9; row++)
            {
                if(possible[(colum * 9) + row].size() == 1)
                {
                    c = possible[(colum * 9) + row][0];
                    direct_extract_number(colum, row, c);
                    board[colum][row] = c;
                    solve = true;
                }
            }
        }
        return solve;
    }
    /*****************************************/
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        size_t row, cube_row;
        size_t colum, cube_colum;
        size_t match;
        char c, res;
        for(colum = 0; colum < 9; colum++)
        {
            for(row = 0; row < 9; row++)
            {
                c = board[colum][row];
                if(c != '.')
                {
                    direct_extract_number(colum, row, c);
                }
            }
        }
        while(find_number(board))
        {
            releated_extract_number();
        }
    }
};
//////////////////////////////
//////////////////////////////
//////////////////////////////
int main()
{
    Solution x;

    vector<vector<char>> board{{'.', '.', '9', '7', '4', '8', '.', '.', '.'}, {'7', '.', '.', '.', '.', '.', '.', '.', '.'}, {'.', '2', '.', '1', '.', '9', '.', '.', '.'}, {'.', '.', '7', '.', '.', '.', '2', '4', '.'}, {'.', '6', '4', '.', '1', '.', '5', '9', '.'}, {'.', '9', '8', '.', '.', '.', '3', '.', '.'}, {'.', '.', '.', '8', '.', '3', '.', '2', '.'}, {'.', '.', '.', '.', '.', '.', '.', '.', '6'}, {'.', '.', '.', '2', '7', '5', '9', '.', '.'}};
    vector<vector<char>> solve{{'5', '1', '9', '7', '4', '8', '6', '3', '2'}, {'7', '8', '3', '6', '5', '2', '4', '1', '9'}, {'4', '2', '6', '1', '3', '9', '8', '7', '5'}, {'3', '5', '7', '9', '8', '6', '2', '4', '1'}, {'2', '6', '4', '3', '1', '7', '5', '9', '8'}, {'1', '9', '8', '5', '2', '4', '3', '6', '7'}, {'9', '7', '5', '8', '6', '3', '1', '2', '4'}, {'8', '3', '2', '4', '9', '1', '7', '5', '6'}, {'6', '4', '1', '2', '7', '5', '9', '8', '3'}};

    cout << "----------begin--------\n";
    x.solveSudoku(board);
    int left = 0;
    for(int i = 0; i < board.size(); ++i)
    {
        for(int j = 0; j < board[i].size(); ++j)
        {
            if(board[i][j] != '.' && solve[i][j] != board[i][j])
            {
                cout << "[x" << board[i][j] << ']';
            }
            else
            {
                cout << '[' << board[i][j] << ']';
            }
            if(board[i][j] == '.')
            {
                left++;
            }
        }
        cout << '\n';
    }
    cout << "Left:" << left << '\n';

    cout << "-----------end---------";
}
//////////////////////////////
//////////////////////////////
//////////////////////////////
