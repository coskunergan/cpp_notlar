
#include <bits/stdc++.h>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>  // cout
#include <iterator>  // back_inserter
#include <string>


using namespace std;

//////////////////////////////
//////////////////////////////
//////////////////////////////
class Solution
{
public:
    string convert(string s, int numRows)
    {
        vector<char> vstr(s.size());
        vector<vector<char>> matris(numRows, vector<char> (s.size() / numRows));        

        copy(s.rbegin(), s.rend(), vstr.begin());

        while(vstr.size() > 0)
        {
            for(int i = 0; i < numRows; i++)
            {
                if(vstr.size())
                {
                    matris[i].push_back(+[&]()
                    {
                        char x = vstr.back();
                        vstr.pop_back();
                        return x;
                    }
                    ());
                }
            }
            int index = numRows;
            int shift = numRows - 2;
            while(shift > 0)
            {
                index--;
                if(shift == index && vstr.size())
                {
                    matris[index].push_back(+[&]()
                    {
                        char x = vstr.back();
                        vstr.pop_back();
                        return x;
                    }
                    ());
                }
                else
                {
                    matris[index].push_back(' ');
                }
                if(index == 0)
                {
                    index = numRows - 1;
                    shift--;
                }
            }
        }
        string res{};
        for(int i = 0; i < numRows; i++)
        {
            copy_if(matris[i].begin(), matris[i].end(), back_inserter(res), [](char c)
            {
                return (c != ' ' && c != '\0');
            });
        }
        return res;
    }
};
//////////////////////////////
//////////////////////////////
//////////////////////////////
int main()
{
    Solution x;

    cout << "----------begin--------\n";

    string res = x.convert("PAYPALISHIRING", 3);// PAHNAPLSIIGYIR

    cout << "Result:" << res << '\n';

    cout << "-----------end---------";
}
//////////////////////////////
//////////////////////////////
//////////////////////////////
