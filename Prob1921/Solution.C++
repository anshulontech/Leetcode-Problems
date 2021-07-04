// Link To Problem:-
// https://leetcode.com/problems/eliminate-maximum-number-of-monsters/

// METHOD 1:-

class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        int n = dist.size();
        vector<pair<double, int>> time(n);

        for (int i = 0; i < n; i++)
            time[i] = {(double)dist[i] / (double)speed[i], i};

        sort(time.begin(), time.end());

        int res = 0;

        for (int i = 0; i < n; i++)
            if (i * speed[time[i].second] >= dist[time[i].second])
                break;
            else
                res++;

        return res;
    }
};