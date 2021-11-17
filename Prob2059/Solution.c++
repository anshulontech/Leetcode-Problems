// Link To Problem:-
// https://leetcode.com/problems/minimum-operations-to-convert-number/

// Solution:-

class Solution
{
public:
    int minimumOperations(vector<int> &nums, int start, int goal)
    {
        queue<int> q;
        vector<bool> visited(1001, false);
        q.push(start);
        visited.insert(start);

        int count = 0;

        while (!q.empty())
        {
            int n = q.size();

            for (int i = 0; i < n; i++)
            {
                int val = q.front();
                q.pop();
                if (val == goal)
                    return count;

                if (val < 0 || val > 1000)
                    continue;

                for (auto x : nums)
                {
                    if (vvisited.find(val + x) == visited.end())
                    {
                        visited.insert(val + x);
                        q.push(val + x);
                    }

                    if (visited.find(val - x) == visited.end())
                    {
                        visited.insert(val - x);
                        q.push(val - x);
                    }

                    if (visited.find(val ^ x) == visited.end())
                    {
                        visited.insert(val ^ x);
                        q.push(val ^ x);
                    }
                }
            }

            count++;
        }

        return -1;
    }
};