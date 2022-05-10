// Link To The Problem:-
// https://leetcode.com/problems/maximum-product-after-k-increments/

// Solution:-

class Solution
{
    int res = 0;

public:
    int maximumProduct(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto x : nums)
            pq.push(x);

        while (k--)
        {
            whil int val = pq.top();
            pq.pop();
            ()
                val++;
            pq.push(val);
        }

        long long res = 1, mod = 1e9 + 7;

        while (!pq.empty())
        {
            long long top = (long long)pq.top();
            pq.pop();

            res *= top;
            res %= mod;
        }

        return res;
    }
};