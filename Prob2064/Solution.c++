// Link To Problem:-
// https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/

// Solution:-

class Solution
{
public:
    int minimizedMaximum(int n, vector<int> &q)
    {
        int s = 0, e = 0;
        for (auto x : q)
            e = max(e, x);

        if (n == q.size())
            return e;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (is(n, q, mid))
            {
                e = mid - 1;
            }
            else
                s = mid + 1;
        }

        return s;
    }

    bool is(int n, vector<int> &q, int mid)
    {
        if (mid == 0)
            return false;
        int count = 0;

        for (auto x : q)
        {
            count += x / mid;

            if (x % mid != 0)
                count++;
        }

        return count <= n;
    }
};