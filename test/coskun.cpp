
#include <bits/stdc++.h>
#include <cstring>

using namespace std;


class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> result{};
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i; j < nums.size(); j++)
            {
                if((nums[j] + nums[i]) == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    return result; 
                }
            }
        }
        return result;
    }
};
//////////////////////////////


int main()
{
    Solution x;
    vector<int> nums = {3, 3};
    vector<int> res;

    cout << "----------begin--------\n\n";

    res = x.twoSum(nums, 6);
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << ' ';
    }

    cout << "\n\n-----------end---------";
}