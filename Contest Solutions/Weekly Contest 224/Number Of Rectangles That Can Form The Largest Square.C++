// Solution:-

class Solution
{
public:
    int countGoodRectangles(vector<vector<int>> &rectangles)
    {
        int res = 0;
        int maxLen = 0;

        for (auto &x : rectangles)
        {
            int currLen = min(x[0], x[1]);

            if (currLen > maxLen)
            {
                maxLen = currLen;
                res = 1;
            }
            else if (currLen == maxLen)
                res++;
        }

        return res;
    }
};