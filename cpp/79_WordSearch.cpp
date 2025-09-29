#include <bits/stdc++.h>

class Solution
{
public:
    using Point = std::pair<int, int>;
    bool exist(std::vector<std::vector<char>> &board, std::string word)
    {
        height = board.size();
        width = board[0].size();
        word_ = &word;
        board_ = &board;

        for (int i{0}; i < height; i++)
        {
            for (int j{0}; j < width; j++)
            {
                if (board[i][j] == word[0] and dfs(Point(i, j), 0))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(const Point currentEdge, int it)
    {
        if (not isValidEdge(currentEdge))
        {
            return false;
        }

        char &currentLetter = (*board_)[currentEdge.first][currentEdge.second];
        if (it >= word_->size() or currentLetter != (*word_)[it])
        {
            return false;
        }
        if (it == word_->size() - 1)
        {
            return true;
        }

        char tempCopy = currentLetter;
        currentLetter = '?';
        for (int i{0}; i < 4; i++)
        {
            if (dfs(Point(currentEdge.first + moves[i].first, currentEdge.second + moves[i].second), it + 1))
            {
                currentLetter = tempCopy;
                return true;
            }
        }
        currentLetter = tempCopy;
        return false;
    }

private:
    inline bool isValidEdge(const Point &p)
    {
        return 0 <= p.first and p.first < height and 0 <= p.second and p.second < width;
    }

    std::vector<std::vector<char>> *board_;
    std::string *word_;
    size_t height;
    size_t width;
    static constexpr std::array<Point, 4> moves{{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};
};