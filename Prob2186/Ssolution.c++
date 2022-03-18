// Link To The Problem:-
// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/

// Solution:-

class Solution
{
public:
    int minSteps(string s, string t)
    {
        vector<int> count(26, 0);

        for (auto x : s)
            count[x - 'a']++;

        for (auto x : t)
            count[x - 'a']--;

        int res = 0;

        for (auto x : count)
            res += abs(x);

        return res;
    }
};