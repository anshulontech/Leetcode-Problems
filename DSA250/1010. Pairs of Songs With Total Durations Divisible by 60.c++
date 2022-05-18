// Link To The Problem:-
//  https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

// Solution:-

class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        unordered_map<int, int> map;

        int res = 0;

        for (auto x : time)
        {
            x %= 60;

            res += map[(60 - x) % 60];
            map[x]++;
        }

        return res;
    }
};