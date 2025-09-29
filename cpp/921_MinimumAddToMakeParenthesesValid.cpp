#include <bits/stdc++.h>

class Solution
{
public:
    int minAddToMakeValid(std::string s)
    {
        std::stack<char> stack;
        for (const auto ele : s)
        {
            if (stack.size() > 0 and stack.top() == '(' and ele == ')')
            {
                stack.pop();
            }
            else
            {
                stack.push(ele);
            }
        }
        return stack.size();
    }
};