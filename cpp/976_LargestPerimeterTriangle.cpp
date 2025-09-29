#include <bits/stdc++.h>

class Solution
{
public:
    int largestPerimeter(std::vector<int> &nums)
    {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        for (auto k{n - 1}, i{n - 2}, j{n - 3}; k >= 2; k--, j--, i--)
        {
            if (nums[i] + nums[j] > nums[k])
                return nums[i] + nums[j] + nums[k];
        }
        return 0;
    }
};