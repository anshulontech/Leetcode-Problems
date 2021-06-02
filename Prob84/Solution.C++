// Link To Problem:-
// https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        heights.push_back(0);
        stack<int> store;
        int res = 0;

        for (int i = 0; i < heights.size(); i++)
        {
            while (!store.empty() && heights[store.top()] > heights[i])
            {
                int h = heights[store.top()];
                store.pop();
                int l = store.empty() ? -1 : store.top();

                res = max(res, (i - l - 1) * h);
            }

            store.push(i);
        }

        return res;
    }
};