// Solution:-

class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, vector<pair<string, double>>> store;
        int n = equations.size();
        for (int i = 0; i < n; i++)
        {
            store[equations[i][0]].push_back({equations[i][1], (double)values[i]});
            store[equations[i][1]].push_back({equations[i][0], 1.0 / (double)values[i]});
        }

        vector<double> res;

        n = queries.size();

        unordered_set<string> visited;

        for (int i = 0; i < n; i++)
            res.push_back(dfs(queries[i][0], queries[i][1], store, visited));

        return res;
    }

private:
    double dfs(string &sou, string &des, unordered_map<string, vector<pair<string, double>>> &store, unordered_set<string> &visited)
    {
        if (store.find(sou) == store.end() || store.find(des) == store.end())
            return -1.0;

        if (sou == des)
            return 1.0;

        visited.insert(sou);

        for (auto x : store[sou])
            if (visited.find(x.first) == visited.end())
            {
                double ans = dfs(x.first, des, store, visited);
                if (ans != (-1.0))
                {
                    visited.erase(sou);
                    return ans * x.second;
                }
            }

        visited.erase(sou);

        return -1.0;
    }
};