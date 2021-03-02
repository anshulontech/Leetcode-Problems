// Solution:-

class Solution
{
public:
    int closestCost(vector<int> &bC, vector<int> &tC, int target)
    {
        vector<int> costs;
        unordered_set<int> visited;
        int n = tC.size();

        for (int i = 0; i < n; i++)
        {
            int sum = tC[i];
            helper(tC, costs, sum, i + 1, n, visited);
            sum += tC[i];
            helper(tC, costs, sum, i + 1, n, visited);
        }

        costs.push_back(0);

        sort(costs.begin(), costs.end());

        n = bC.size();

        int res = bC[0], min_diff = INT_MAX, m = costs.size();

        for (int i = 0; i < m; i++)
            cout << costs[i] << " ";
        cout << endl;

        for (int i = 0; i < n; i++)
        {
            int idx = lower_bound(costs.begin(), costs.end(), target - bC[i]) - costs.begin();
            if (idx < m && min_diff > abs(target - bC[i] - costs[idx]))
            {
                min_diff = abs(target - bC[i] - costs[idx]);
                res = bC[i] + costs[idx];
            }

            if (idx > 0 && min_diff >= abs(target - bC[i] - costs[idx - 1]))
            {
                min_diff = abs(target - bC[i] - costs[idx - 1]);
                res = bC[i] + costs[idx - 1];
            }
        }

        return res;
    }

private:
    void helper(vector<int> &tC, vector<int> &costs, int &sum, int idx, int &n, unordered_set<int> &visited)
    {

        if (visited.find(sum) == visited.end())
        {
            visited.insert(sum);
            costs.push_back(sum);
        }

        for (int i = idx; i < n; i++)
        {
            sum += tC[i];
            helper(tC, costs, sum, i + 1, n, visited);
            sum += tC[i];
            helper(tC, costs, sum, i + 1, n, visited);
            sum -= (2 * tC[i]);
        }
    }
};