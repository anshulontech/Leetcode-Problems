// Approach 1 : -

class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        unordered_map<int, int> store;
        int res = 0;

        for (int i = 0; i < points.size(); i++)
        {
            for (int j = 0; j < points.size(); j++)
            {
                if (i == j)
                    continue;

                int d = getDistance(points[i], points[j]);
                store[d]++;
            }

            for (auto x : store)
                res += x.second * (x.second - 1);

            store.clear();
        }

        return res;
    }

    int getDistance(vector<int> &a, vector<int> &b)
    {
        int x = a[0] - b[0];
        int y = a[1] - b[1];

        return x * x + y * y;
    }
};