// Link To The Problem:-
// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/

// Solution:-

class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        unordered_map<int, int> freq;

        for (auto x : tasks)
            freq[x]++;

        int res = 0;

        for (auto x : freq)
            if (x.second == 1)
                return -1;
            else if (x.second % 3 == 0)
                res += x.second / 3;
            else
                res += x.second / 3 + 1;

        return res;
    }
};