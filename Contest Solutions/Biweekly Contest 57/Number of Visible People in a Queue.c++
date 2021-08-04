// Solution:-

class Solution
{
public:
    vector<int> canSeePersonsCount(vector<int> &heights)
    {
        stack<int> s;
        int n = heights.size();
        s.push(heights[n - 1]);

        vector<int> res(n, 0);

        for (int i = n - 2; i >= 0; i--)
        {
            res[i] = s.size();
            int count = 0;

            while (!s.empty() && heights[i] > s.top())
            {
                count++;
                s.pop();
            }

            if (!s.empty())
                count++;

            res[i] = count;
            s.push(heights[i]);
        }

        return res;
    }
};