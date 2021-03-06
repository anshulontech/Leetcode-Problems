// Solution:-

class Solution
{
public:
    int nearestValidPoint(int x, int y, vector<vector<int>> &points)
    {
        int res = -1, n = points.size(), dist = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            auto p = points[i];
            if ((p[0] == x || p[1] == y) && dist > (abs(p[0] - x) + abs(p[1] - y)))
            {
                res = i;
                dist = abs(p[0] - x) + abs(p[1] - y);
            }
        }

        return res;
    }
};