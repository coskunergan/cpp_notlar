
#include <bits/stdc++.h>
#include <cstring>

using namespace std;


class Solution
{
public:
    string find_left(string s, int center)
    {
        string res{};
        int len = s.length();
        int right = center + 1;
        int left = 0;
        bool lock = false;
        if(center)
        {
            left = center - 1;
        }
        res.push_back(s[center]);
        while(right < len)
        {
            if(!lock && s[center] == s[right])
            {
                res.push_back(s[right]);
                if(s[center] == s[left])
                {
                    res.insert(0, 1, s[left]);
                    left--;
                }
                else
                {
                    lock = true;
                }
            }
            else if(s[right] == s[left])
            {
                res.insert(0, 1, s[left]);
                lock = true;
                left--;
                res.push_back(s[right]);
            }
            else
            {
                if(lock)
                {
                    left--;
                }
            }
            right++;
        }
        return res;
    }

    string find_right(string s, int center)
    {
        string res{};
        int len = s.length();
        int right = center + 1;
        int left = 0;
        bool lock = false;
        if(center)
        {
            left = center - 1;
        }
        res.push_back(s[center]);
        while(left >= 0)
        {
            if(!lock && s[center] == s[left])
            {
                res.insert(0, 1, s[left]);
                if(s[center] == s[right])
                {
                    res.push_back(s[right]);
                    right++;
                }
                else
                {
                    lock = true;
                }
            }
            else if(s[left] == s[right])
            {
                lock = true;
                res.push_back(s[right]);
                right++;
                res.insert(0, 1, s[left]);

            }
            else
            {
                if(lock)
                {
                    right++;
                }
            }
            left--;
        }
        return res;
    }

    string longestPalindrome(string s)
    {
        string ans{};
        string res{};
        int len = s.length();
        int center = len / 2;

        if(len <= 1)
        {
            return s;
        }
        if(len == 2)
        {
            if(s[0] != s[1])
            {
                return {s[0]};
            }
            return s;
        }

        while(center)
        {
            res = find_right(s, center);
            if(res.length() > ans.length())
            {
                ans = res;
            }
            center--;
        }

        center = (len / 2);
        while(center < len)
        {
            res = find_left(s, center);
            if(res.length() > ans.length())
            {
                ans = res;
            }
            center++;
        }
        return ans;
    }
};
//////////////////////////////


int main()
{
    Solution x;

    string test_str[][2] =
    {
        {"aacabdkacaa", "aca"},
        {"babad", "aba"},
        {"abcda", "a"},
        {"abb", "bb"},
        {"aab", "aa"},
        {"cbbd", "bb"},
        {"ac", "a"},
        {"bb", "bb"},
        {"a", "a"},
        {"ccc", "ccc"},
        {"cccc", "cccc"},
        {"ccccc", "ccccc"},
        {"123ccc", "ccc"},
        {"ccc123", "ccc"},
        {"0ccc123", "ccc"},
        {"123ccc4", "ccc"},
        {"123cc4", "cc"},
        {"xaabacxcabaaxcabaax", "xaabacxcabaax"}
    };

    cout << "----------begin--------\n\n";

    {
        for(int i = 0; i < 18; i++)
        {
            string ans = x.longestPalindrome(test_str[i][0]);
            if(ans == test_str[i][1])
            {
                cout << "OK    : " << test_str[i][0] << " -> " << test_str[i][1] << '\n';
            }
            else
            {
                cout << "FAIL  : " << test_str[i][0] << " -> " << test_str[i][1] << " Ans: " << ans << '\n';
            }
        }
    }

    cout << "\n\n-----------end---------";
}