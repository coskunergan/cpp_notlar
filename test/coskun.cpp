
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
public:
    int lengthOfLongestSubstring(string s)
    {
        int max = 0;
        vector<char> vstr{};
        for(char n : s)
        {
            if(auto x = find(vstr.begin(), vstr.end(), n); x != vstr.end())
            {
                copy(x + 1, vstr.end(), vstr.begin());
                vstr.resize(vstr.end() - x - 1);
            }
            vstr.push_back(n);
            if(max < vstr.size())
            {
                max = vstr.size();
            }
        }

        return max;
    }
};
//////////////////////////////
//////////////////////////////
//////////////////////////////
int main()
{
    Solution x;

    cout << "----------begin--------\n";
    //int res = x.lengthOfLongestSubstring("abcabcbb");
    //int res = x.lengthOfLongestSubstring("pwwkew");
    //int res = x.lengthOfLongestSubstring("bbbbb");
    int res = x.lengthOfLongestSubstring("dvdf");

    cout << "Result:" << res << '\n';

    cout << "-----------end---------";
}
//////////////////////////////
//////////////////////////////
//////////////////////////////
