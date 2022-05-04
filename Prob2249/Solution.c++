// Link To The Problem:-
// https://leetcode.com/problems/count-lattice-points-inside-a-circle/

// Solution:-

class Solution
{
public:
    int countLatticePoints(vector<vector<int>> &circles)
    {
        set<pair<int, int>> visited;

        int res = 0;

        for (auto &a : circles)
        {
            for (int y = 0;; y++)
            {
                int count = 0;

                for (int x = 0;; x++)
                {
                    if ((x * x + y * y) <= a[2] * a[2])
                    {
                        if (visited.find({a[0] + x, a[1] + y}) == visited.end())
                        {
                            visited.insert({a[0] + x, a[1] + y});
                            res++;
                        }

                        if (visited.find({a[0] + x, a[1] - y}) == visited.end())
                        {
                            visited.insert({a[0] + x, a[1] - y});
                            res++;
                        }

                        if (visited.find({a[0] - x, a[1] + y}) == visited.end())
                        {
                            visited.insert({a[0] - x, a[1] + y});
                            res++;
                        }

                        if (visited.find({a[0] - x, a[1] - y}) == visited.end())
                        {
                            visited.insert({a[0] - x, a[1] - y});
                            res++;
                        }
                        count++;
                    }
                    else
                        break;
                }

                if (count == 0)
                    break;
            }
        }

        return res;
    }
};