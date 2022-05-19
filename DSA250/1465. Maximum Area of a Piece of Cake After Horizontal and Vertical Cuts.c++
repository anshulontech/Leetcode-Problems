// Link To The Problem:-
//  https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

// Solution:-

class Solution
{
public:
    int maxArea(int h, int w, vector<int> &hC, vector<int> &vC)
    {
        hC.push_back(0);
        vC.push_back(0);

        hC.push_back(h);
        vC.push_back(w);

        sort(hC.begin(), hC.end());
        sort(vC.begin(), vC.end());

        long long hMax = 0, vMax = 0;

        for (int i = 0; i < hC.size() - 1; i++)
            hMax = max(hMax, hC[i + 1] - hC[i]);

        for (int i = 0; i < vC.size() - 1; i++)
            vMax = max(vMax, vC[i + 1] - vC[i]);

        return (vMax * hMax) % ((long long)(1e9 + 7));
    }

    long long max(long long a, long long b)
    {
        if (a > b)
            return a;
        else
            return b;
    }
};