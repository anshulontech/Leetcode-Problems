// Solution:-

class Solution
{
public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
    {
        unordered_map<int, vector<int>> store;

        for (auto &x : adjacentPairs)
        {
            store[x[0]].push_back(x[1]);
            store[x[1]].push_back(x[0]);
        }
        int first = -1;

        for (auto &x : store)
            if (x.second.size() == 1)
            {
                first = x.first;
                break;
            }

        vector<int> res;
        unordered_set<int> visited;

        res.push_back(first);
        visited.insert(first);

        first = store[first][0];

        while (visited.find(first) == visited.end())
        {
            res.push_back(first);
            visited.insert(first);

            if (store[first].size() < 2 || visited.find(store[first][0]) == visited.end())
                first = store[first][0];
            else
                first = store[first][1];
        }

        return res;
    }
};