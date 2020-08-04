// Approach 1:-

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int N = nums.size();
        vector<int> res(N, -1);
        stack<int> s;

        for (int i = 0; i < nums.size() * 2; i++)
        {
            int val = nums[i % N];
            while (!s.empty() && nums[s.top()] < val)
            {
                res[s.top()] = val;
                s.pop();
            }

            if (i < N)
                s.push(i);
        }

        return res;
    }
};