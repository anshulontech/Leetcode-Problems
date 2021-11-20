// Link To Problem:-
// https://leetcode.com/problems/most-beautiful-item-for-each-query/

// Solution:-

class Solution
{
public:
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
    {
        sort(items.begin(), items.end());

        int n = items.size();

        for (int i = 1; i < n; i++)
            items[i][1] = max(items[i][1], items[i - 1][1]);
        int m = queries.size();
        vector<int> res(m);

        for (int i = 0; i < m; i++)
        {
            int idx = search(items, queries[i]);
            if (idx == -1)
                res[i] = 0;
            else if (idx == n)
                res[i] = items[idx - 1][1];
            else
                res[i] = items[idx][1];
        }

        return res;
    }

    int search(vector<vector<int>> &items, int val)
    {
        int s = 0, e = items.size() - 1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (items[mid][0] <= val)
                s = mid + 1;
            else
                e = mid - 1;
        }

        return s - 1;
    }
};