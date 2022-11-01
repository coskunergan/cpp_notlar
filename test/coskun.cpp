
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
    void find_obvious_triples(void)
    {
        size_t row, cube_row;
        size_t colum, cube_colum;
        size_t index;
        size_t triples_index[3];
        char tripA, tripB, tripC;
        for(size_t i = 0; i < 9; i++)
        {
            colum = (i / 3) * 3;
            row = (i * 3) % 9;
            tripA = 0;
            tripB = 0;
            tripC = 0;
            for(size_t i = 0; i < 9; i++)
            {
                cube_row = ((row / 3) * 3) + (i % 3);
                cube_colum = ((colum / 3) * 3) + (i / 3);
                index = (cube_colum * 9) + cube_row;
                if(tripA == 0)
                {
                    if(possible[index].size() == 2)
                    {
                        tripA = possible[index][0]; // 1 -> 1
                        tripB = possible[index][1]; // 8 -> 8
                        triples_index[0] = index;
                    }
                }
                else if(tripC == 0)
                {
                    if(possible[index].size() == 2)
                    {
                        size_t p = possible[index].find(tripA);
                        if(p != string::npos)
                        {
                            p++;
                            tripC = possible[index][p % 2];
                        }
                        else
                        {
                            p = possible[index].find(tripB);
                            if(p != string::npos)
                            {
                                p++;
                                tripC = tripB;
                                tripB = tripA;
                                tripA = tripC;
                                tripC = possible[index][p % 2];
                                triples_index[1] = index;
                            }
                            else
                            {
                                tripA = possible[index][0];
                                tripB = possible[index][1];
                                triples_index[0] = index;
                            }
                        }
                    }
                }
                else if(possible[index].size() == 2)
                {
                    size_t p = possible[index].find(tripC);
                    if(p != string::npos)
                    {
                        p++;
                        if(possible[index][p % 2] == tripB)
                        {
                            triples_index[2] = index;
                            // finded triples.
                            for(size_t i = 0; i < 9; i++)
                            {
                                cube_row = ((row / 3) * 3) + (i % 3);
                                cube_colum = ((colum / 3) * 3) + (i / 3);
                                index = (cube_colum * 9) + cube_row;
                                if(index != triples_index[0] && index != triples_index[1] && index != triples_index[2])
                                {
                                    possible[index].erase(remove(possible[index].begin(), possible[index].end(), tripA), possible[index].end());
                                    possible[index].erase(remove(possible[index].begin(), possible[index].end(), tripB), possible[index].end());
                                    possible[index].erase(remove(possible[index].begin(), possible[index].end(), tripC), possible[index].end());
                                }
                            }
                            return;
                        }
                    }
                }
            }
        }
    }
    /*****************************************/
    void find_hidded_pairs(void)
    {
        size_t row, cube_row;
        size_t colum, cube_colum;
        size_t index;
        size_t indexA;
        size_t indexB;
        vector<char> pairs;
        vector<size_t> count;
        size_t testB;
        char pair;
        for(size_t i = 0; i < 9; i++)
        {
            colum = (i / 3) * 3;
            row = (i * 3) % 9;
            for(size_t i = 0; i < 9; i++)// count use numb.
            {
                cube_row = ((row / 3) * 3) + (i % 3);
                cube_colum = ((colum / 3) * 3) + (i / 3);
                index = (cube_colum * 9) + cube_row;
                for(char c : possible[index])
                {
                    count[c - '1']++;
                }
            }
            for(size_t i = 0; i < count.size(); i++) // find pairs.
            {
                if(count[i] == 2)
                {
                    pairs.push_back(i + '1');
                }
            }
            indexA = indexB = string::npos;
            if(pairs.size() >= 2)
            {
                for(size_t p = 0; p < pairs.size(); p++)// pairs search
                {
                    for(size_t i = 0; i < 9; i++)
                    {
                        cube_row = ((row / 3) * 3) + (i % 3);
                        cube_colum = ((colum / 3) * 3) + (i / 3);
                        index = (cube_colum * 9) + cube_row;
                        if(indexA == string::npos)
                        {
                            if(possible[index].find(pairs[pairs.size() - 2]) != string::npos)
                            {
                                if(possible[index].find(pairs[pairs.size() - 1]) != string::npos)
                                {
                                    indexA = index;
                                }
                            }
                        }
                        else if(indexB == string::npos)
                        {
                            if(possible[index].find(pairs[pairs.size() - 2]) != string::npos)
                            {
                                if(possible[index].find(pairs[pairs.size() - 1]) != string::npos)
                                {
                                    indexB = index;
                                }
                            }
                        }
                        else
                        {
                            if(possible[index].find(pairs[pairs.size() - 2]) != string::npos)
                            {
                                if(possible[index].find(pairs[pairs.size() - 1]) != string::npos)
                                {
                                    pairs.pop_back();
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    /*****************************************/
    void find_obvious_pairs(void)
    {
        size_t row, cube_row;
        size_t colum, cube_colum;
        size_t index;
        size_t subindex;
        size_t lastindex;
        char pairA, pairB;
        for(size_t i = 0; i < 9; i++)
        {
            colum = (i / 3) * 3;
            row = (i * 3) % 9;
            for(size_t i = 0; i < 9; i++)
            {
                cube_row = ((row / 3) * 3) + (i % 3);
                cube_colum = ((colum / 3) * 3) + (i / 3);
                index = (cube_colum * 9) + cube_row;
                if(possible[index].size() == 2)
                {
                    for(size_t i = 0; i < 9; i++)
                    {
                        cube_row = ((row / 3) * 3) + (i % 3);
                        cube_colum = ((colum / 3) * 3) + (i / 3);
                        subindex = (cube_colum * 9) + cube_row;
                        if(subindex != index && possible[subindex].size() == 2)
                        {
                            if(possible[subindex] == possible[index])
                            {
                                pairA = possible[subindex][0];
                                pairB = possible[subindex][1];
                                for(size_t i = 0; i < 9; i++)
                                {
                                    cube_row = ((row / 3) * 3) + (i % 3);
                                    cube_colum = ((colum / 3) * 3) + (i / 3);
                                    lastindex = (cube_colum * 9) + cube_row;
                                    if(lastindex != index && lastindex != subindex)
                                    {
                                        //if(possible[lastindex].find(pairA) != string::npos)
                                        {
                                            possible[lastindex].erase(remove(possible[lastindex].begin(), possible[lastindex].end(), pairA), possible[lastindex].end());
                                        }
                                        //if(possible[lastindex].find(pairB) != string::npos)
                                        {
                                            possible[lastindex].erase(remove(possible[lastindex].begin(), possible[lastindex].end(), pairB), possible[lastindex].end());
                                        }
                                    }
                                }
                                return;
                            }
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
            find_obvious_pairs();
            find_obvious_triples();
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
