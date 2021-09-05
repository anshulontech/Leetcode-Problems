// Link To Problem:-
// https://leetcode.com/problems/find-all-groups-of-farmland/

// Solution:-

class Solution
{
public:
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        int n = land.size(), m = land[0].size();
        vector<vector<int>> res;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (land[i][j] == 0)
                    continue;
                else
                {
                    int x1 = i, x2 = i, y1 = j, y2 = j;
                    while (x2 < n && land[x2][j] == 1)
                        x2++;
                    while (y2 < m && land[i][y2] == 1)
                        y2++;

                    x2--, y2--;

                    res.push_back({x1, y1, x2, y2});

                    for (int p = x1; p <= x2; p++)
                        for (int q = y1; q <= y2; q++)
                            land[p][q] = 0;
                }

        return res;
    }
};