#include <bits/stdc++.h>

class Solution
{
public:
    double largestTriangleArea(std::vector<std::vector<int>> &points)
    {
        double maxArea{-1.0};
        for (int i{0}; i < points.size(); i++)
        {
            for (int j{i + 1}; j < points.size(); j++)
            {
                for (int k{j + 1}; k < points.size(); k++)
                {
                    const auto &a{points[i]}, b{points[j]}, c{points[k]};
                    maxArea = std::max(maxArea, calculateArea(a, b, c));
                }
            }
        }
        return maxArea;
    }
    using Point = std::vector<int>;
    inline const double calculateArea(const Point &a, const Point &b, const Point &c)
    {
        const double &newArea{std::fabs(a[0] * (b[1] - c[1]) + b[0] * (c[1] - a[1]) + c[0] * (a[1] - b[1]))};
        return newArea / 2.0;
    }
};