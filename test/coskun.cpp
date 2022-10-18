
#include <bits/stdc++.h>
#include <cstring>

using namespace std;


class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        unsigned int res = 0;
        unsigned long long dv = (unsigned int)abs(dividend);
        unsigned long long dr = (unsigned int)abs(divisor);
        unsigned int shift = 0;
        if(dv < dr)
        {
            return 0;
        }
        if(divisor == 1)
        {
            return dividend;
        }
        if(divisor == dividend)
        {
            return 1;
        }
        if(divisor < 0 && dividend < 0)
        {
            if(divisor == -1)
            {
                return abs(dividend) - 1;
            }
        }
        for(int i = 32; i > 2; i--)
        {
            if(dv >= (dr << i))
            {
                shift = i;
                break;
            }
        }
        if(shift)
        {
            dr <<= shift;
            while(dv >= dr)
            {
                dv -= dr;
                res += 1;
            }
            res <<= shift;
            dr >>= shift;
            while(dv >= dr)
            {
                dv -= dr;
                res += 1;
            }
        }
        else
        {
            while(dv >= dr)
            {
                dv -= dr;
                res += 1;
            }
        }
        if(dividend < 0 && divisor >= 0)
        {
            res = (0xFFFFFFFF - res) + 1;
        }
        else if(divisor < 0 && dividend >= 0)
        {
            res = (0xFFFFFFFF - res) + 1;
        }
        return (int)res;
    }
};
//////////////////////////////


int main()
{
    Solution x;

    cout << "----------begin--------\n\n";

    {
        cout << x.divide(-1021989372, -82778243) << '\n';
        cout << x.divide(2147483647, 1) << '\n';
        cout << x.divide(1026117192, -874002063) << '\n';
        cout << x.divide(0, 1) << '\n';
        cout << x.divide(-2147483648, -1) << '\n';
        cout << x.divide(7, -3) << '\n';
        cout << x.divide(-2147483648, -3) << '\n';
    }

    cout << "\n\n-----------end---------";
}