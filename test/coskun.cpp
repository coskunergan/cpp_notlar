
#include <bits/stdc++.h>
#include <cstring>

using namespace std;


class Solution
{
public:
    bool isPalindrome(int x)
    {
        char arr[10];
        if(x < 0)
        {
            return false;
        }

        if(x == 0)
        {
            return true;
        }        

        arr[0]  = x % 10;
        arr[1]  = x / 10 % 10;
        arr[2]  = x / 100 % 10;
        arr[3]  = x / 1000 % 10;
        arr[4]  = x / 10000 % 10;
        arr[5]  = x / 100000 % 10;
        arr[6]  = x / 1000000 % 10;
        arr[7]  = x / 10000000 % 10;
        arr[8]  = x / 100000000 % 10;
        arr[9]  = x / 1000000000 % 10;

        int len;
        int i ;

        for(i = 9; i > 0; i--)
        {
            if(arr[i])
            {
                len = i;
                break;
            }
        }             
        for(i = 0; i < len; i++)
        {
            if(arr[i] != arr[len - i])
            {
                return false;
            }
        }
        return true;
    }
};
//////////////////////////////


int main()
{
    Solution x;

    cout << "----------begin--------\n\n";

    {
        cout << x.isPalindrome(12321) << ' ';
    }

    cout << "\n\n-----------end---------";
}