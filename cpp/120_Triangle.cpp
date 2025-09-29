#include <bits/stdc++.h>

class Solution
{
public:
    int minimumTotal(std::vector<std::vector<int>> &triangle)
    {
        const size_t n{triangle.size()};
        std::vector<std::vector<int>> dp{triangle};
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                dp[i][j] += std::min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }
        return dp[0][0];
    }
};