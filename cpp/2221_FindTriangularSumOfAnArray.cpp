#include < bits / stdc++.h>

class Solution
{
public:
    int triangularSum(std::vector<int>& nums)
    {
        int n = nums.size() - 1;
        for (int i{0}; i < n; i++)
        {
            nums[i] += nums[i + 1];
            nums[i] %= 10;
            if (i == n - 1)
            {
                --n;
                i = -1;
            }
        }
        return nums[0];
    }
};