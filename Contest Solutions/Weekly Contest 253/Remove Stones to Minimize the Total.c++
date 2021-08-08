// Solution:-

class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        priority_queue<int> pq;

        for (auto x : piles)
            pq.push(x);

        while (k-- && !pq.empty())
        {
            int val = pq.top();
            pq.pop();
            pq.push(val - val / 2);
        }

        int res = 0;

        while (!pq.empty())
        {
            res += pq.top();
            pq.pop();
        }

        return res;
    }
};