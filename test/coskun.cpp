
#include <bits/stdc++.h>
#include <cstring>

// Input: num = 1994
// Output: "MCMXCIV"
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4

using namespace std;
///////////////////////////////
class Solution
{
public:
    int myAtoi(string s)
    {
        int l = s.length() + 1;
        char carr[l];
        int i = 0;
        unsigned long long num = 0;
        bool neg = false;
        bool parse = false;

        memcpy(carr, s.c_str(), l);

        while(--l)
        {
            if(parse == false)
            {
                if(carr[i] == '-'  && (carr[i + 1] >= '0' && carr[i + 1] <= '9'))
                {
                    neg = true;
                    parse = true;
                }
                else if(carr[i] == '+' && (carr[i + 1] >= '0' && carr[i + 1] <= '9'))
                {
                    neg = false;
                    parse = true;
                }
                else if(carr[i] == '.' && (carr[i + 1] >= '0' && carr[i + 1] <= '9'))
                {
                    return 0;
                }
                else if(carr[i] >= '0' && carr[i] <= '9')
                {
                    num = carr[i] - '0';
                    parse = true;
                }
                else if(carr[i] != ' ')
                {
                    return 0;
                }
            }
            else
            {
                if(carr[i] >= '0' && carr[i] <= '9')
                {
                    num *= 10;
                    num += carr[i] - '0';
                    if(num > 2147483647)
                    {
                        if(neg)
                        {
                            return 0x80000000;
                        }
                        else
                        {
                            return 0x7FFFFFFF;
                        }
                    }
                }
                else
                {
                    break;
                }
            }
            i++;
        }
        return (int)(neg ? (0x100000000 - num) : num);
    }
};
//////////////////////////////

int main()
{
    Solution x;

    cout << "----------begin--------\n\n";

    cout << x.myAtoi("0000-123") << "\n";

    cout << "\n\n-----------end---------";


}