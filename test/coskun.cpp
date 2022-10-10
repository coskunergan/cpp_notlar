
#include <bits/stdc++.h>

// Input: num = 1994
// Output: "MCMXCIV"
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4

using namespace std;
///////////////////////////////
class Solution
{
public:
    string intToRoman(int num)
    {
        char str[16];
        int index = 0;

        while(num)
        {
            if(num >= 900)
            {
                if(num >= 1000)
                {
                    num -= 1000;                
                }
                else
                {                
                    num -= 900;
                    str[index++] = 'C';                    
                }
                str[index++] = 'M';
            }
            else if(num >= 400)
            {
                if(num >= 500)
                {
                    num -= 500;                
                }
                else
                {                
                    num -= 400;
                    str[index++] = 'C';                    
                }
                str[index++] = 'D';
            }
            else if(num >= 90)
            {
                if(num >= 100)
                {
                    num -= 100;                
                }
                else
                {                
                    num -= 90;
                    str[index++] = 'X';                    
                }
                str[index++] = 'C';
            }
            else if(num >= 40)
            {
                if(num >= 50)
                {
                    num -= 50;                
                }
                else
                {                
                    num -= 40;
                    str[index++] = 'X';                    
                }
                str[index++] = 'L';
            }
            else if(num >= 9)
            {
                if(num >= 10)
                {
                    num -= 10;                
                }
                else
                {                
                    num -= 9;
                    str[index++] = 'I';                    
                }
                str[index++] = 'X';
            }   
            else if(num >= 4)
            {
                if(num >= 5)
                {
                    num -= 5;                
                }
                else
                {                
                    num -= 4;
                    str[index++] = 'I';                    
                }
                str[index++] = 'V';
            }            
            else if(num >= 1)
            {
                num -= 1;
                str[index++] = 'I';
            }
            if(index > 14)
            {
                break;
            }                    
        }
        str[index] = '\0';
        return str;
    }
};
//////////////////////////////

int main()
{
    Solution x;

    cout << "----------begin--------\n\n";

    cout << x.intToRoman(1994) << "\n";

    cout << x.intToRoman(58) << "\n";

    cout << x.intToRoman(3888) << "\n";


    cout << "\n\n-----------end---------";


}