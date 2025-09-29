#include <bits/stdc++.h>

class Solution
{
public:
    int minScoreTriangulation(std::vector<int> &values)
    {
        int n = values.size();
        std::map<std::pair<int, int>, int> alreadyCalculated;

        std::function<int(int, int)> dp = [&](int l, int r) -> int
        {
            if (l + 2 > r)
            {
                return 0;
            }
            if (l + 2 == r)
            {
                return values[l] * values[l + 1] * values[r];
            }
            int minVal = INT_MAX;
            const auto key{std::make_pair(l, r)};
            if (alreadyCalculated.count(key) not_eq 0)
            {
                return std::min(minVal, alreadyCalculated[key]);
            }
            for (int i{l + 1}; i < r; i++)
            {
                minVal = std::min(minVal, values[l] * values[i] * values[r] + dp(l, i) + dp(i, r));
            }
            alreadyCalculated[key] = minVal;
            return minVal;
        };
        return dp(0, n - 1);
    }
};