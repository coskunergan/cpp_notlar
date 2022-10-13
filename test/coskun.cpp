
#include <bits/stdc++.h>
#include <cstring>

using namespace std;


class Solution
{
public:
    int reverse(int x)
    {
        unsigned int val = abs(x);
        unsigned long long rev = 0;
        unsigned int arr[10] =
        {
            val % 10,
            (val / 10) % 10,
            (val / 100) % 10,
            (val / 1000) % 10,
            (val / 10000) % 10,
            (val / 100000) % 10,
            (val / 1000000) % 10,
            (val / 10000000) % 10,
            (val / 100000000) % 10,
            (val / 1000000000)
        };

        bool start = false;
        unsigned int index = 9;
        unsigned int mult = 1;
        do
        {
            if(arr[index])
            {
                start = true;
            }
            if(start)
            {
                rev += ((unsigned long long)arr[index] * mult);
                mult *= 10;
            }
        }
        while(index--);

        if(rev > pow(2,31))
        {
            rev = 0;
        }

        return x < 0 ? rev * -1 : rev;
    }
};
//////////////////////////////


int main()
{
    Solution x;
    int number = 1234;

    cout << "----------begin--------\n\n";

    //cin >> number;

    cout << x.reverse(number) << ' ';

    cout << "\n\n-----------end---------";
}