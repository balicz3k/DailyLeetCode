#include <bits/stdc++.h>

class Solution
{
public:
    int triangleNumber(std::vector<int> &nums)
    {
        uint64_t result{0};
        int n = {static_cast<int>(nums.size())};
        if (n < 3)
            return 0;
        std::sort(nums.begin(), nums.end());
        for (int i{n - 1}; i >= 2; i--)
        {
            int j{i - 1};
            int k{0};
            while (k < j)
            {
                if (nums[k] + nums[j] > nums[i])
                {
                    result += j - k;
                    --j;
                }
                else
                {
                    ++k;
                }
            }
        }
        return result;
    }
};