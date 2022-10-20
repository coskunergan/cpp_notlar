
#include <bits/stdc++.h>
#include <cstring>

using namespace std;


class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int len = nums1.size();
        int i;        
        
        while(nums2.size())
        {
            int val = nums2.back();
            nums2.pop_back();

            for(i = len - 1; i >= 0; i--)
            {
                if(nums1[i] <= val)
                {
                    nums1.insert(nums1.begin() + i + 1, val);
                    break;
                }
            }
            if(i < 0)
            {
                nums1.insert(nums1.begin(), val);
            }
        }
        len = nums1.size();
        if(len % 2 == 0)
        {
            return (double)(nums1[(len - 1) / 2] + nums1[((len - 1) / 2) + 1]) / 2;
        }
        return nums1[(len - 1) / 2];
    }
};
//////////////////////////////


int main()
{
    Solution x;

    vector<int>nums1 = {0, 0, 0, 0, 0};
    vector<int>nums2 = {-1, 0, 0, 0, 0, 0, 1};

    cout << "----------begin--------\n\n";

    {
        double ans = x.findMedianSortedArrays(nums1, nums2);
        cout << " Ans: " << ans << '\n';
    }

    cout << "\n\n-----------end---------";
}
