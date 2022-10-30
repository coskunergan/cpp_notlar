
#include <bits/stdc++.h>
#include <vector>
#include <cstring>

using namespace std;

//////////////////////////////
//////////////////////////////
//////////////////////////////
class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        int s_row, row;
        int s_colum, colum;
        const vector<char> availible_nums{ '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        vector<char> possible_nums;

        for(s_row = 0; s_row < 9; ++s_row)
        {
            for(s_colum = 0; s_colum < 9; ++s_colum)
            {
                int x = board[s_row][s_colum];
                if(x == '.')
                {
                    possible_nums = availible_nums;
                    int left_row = 9;
                    int left_colum = 9;
                    for(int i = 0; i < 9; ++i)
                    {
                        if(board[s_row][i] != '.')
                        {
                            possible_nums[board[s_row][i] - 1] = 'x';
                            left_row--;
                        }
                        if(board[i][s_colum] != '.')
                        {
                            possible_nums[board[i][s_colum] - 1] = 'x';
                            left_colum--;
                        }
                    }
                    if(left_row == 1)
                    {

                    }
                    if(left_colum == 1)
                    {

                    }


                }
            }
        }



    }
};
//////////////////////////////
//////////////////////////////
//////////////////////////////
int main()
{
    Solution x;

    vector<vector<char>> board
    {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    vector<vector<char>> solved
    {
        {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
        {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
        {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
        {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
        {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
        {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
        {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
        {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
        {'3', '4', '5', '2', '8', '6', '1', '7', '9'}
    };

    cout << "----------begin--------\n\n";

    x.solveSudoku(board);

    for(int i = 0; i < board.size(); ++i)
    {
        for(int j = 0; j < board[i].size(); ++j)
        {
            if(board[i][j] != '.' && solved[i][j] != board[i][j])
            {
                cout << "[x" << board[i][j] << ']';
            }
            else
            {
                cout << '[' << board[i][j] << ']';
            }
        }
        cout << '\n';
    }

    cout << "-----------end---------";
}
//////////////////////////////
//////////////////////////////
//////////////////////////////
