// Link To Problem:-
// https://leetcode.com/problems/detonate-the-maximum-bombs/

// Solution:-

class area
{
public:
    int idx;
    vector<area *> friends;

    area(int val)
    {
        idx = val;
    }
};

class Solution
{
public:
    int maximumDetonation(vector<vector<int>> &bombs)
    {
        int n = bombs.size();
        if (n == 1)
            return 1;
        unordered_map<int, area *> map;

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
                area *first = NULL, *second = NULL;

                if (map.find(i) == map.end())
                {
                    first = new area(i);
                    map[i] = first;
                }
                else
                    first = map[i];

                if (map.find(j) == map.end())
                {
                    second = new area(j);
                    map[j] = second;
                }
                else
                    second = map[j];

                if (isIntersecting(bombs[i], bombs[j]))
                {
                    first->friends.push_back(second);
                }

                if (isIntersecting(bombs[j], bombs[i]))
                {
                    second->friends.push_back(first);
                }
            }

        int res = 0;

        for (int i = 0; i < n; i++)
        {
            unordered_set<int> visited;
            area *node = map[i];

            int count = 1;
            visited.insert(i);

            for (auto x : node->friends)
                dfs(x, visited, count);

            res = max(res, count);
        }

        return res;
    }

    bool isIntersecting(vector<int> &a, vector<int> &b)
    {
        long long x = abs(a[0] - b[0]), y = abs(a[1] - b[1]), dist = a[2];

        if (x * x + y * y > dist * dist)
            return false;
        return true;
    }

    void dfs(area *node, unordered_set<int> &visited, int &count)
    {
        if (visited.find(node->idx) != visited.end())
            return;

        visited.insert(node->idx);
        count++;

        for (auto x : node->friends)
            dfs(x, visited, count);
    }
};