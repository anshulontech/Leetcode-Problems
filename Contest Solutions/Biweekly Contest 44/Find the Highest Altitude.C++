// Solution:-

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int res = 0, sum = 0, n = gain.size();
        for (int i = 0; i < n; i++)
        {
            sum += gain[i];
            res = max(res, sum);
        }

        return res;
    }
};