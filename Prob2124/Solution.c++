// Link To The Problem:-
// https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/

// Solution:-

class Solution
{
public:
    bool checkString(string s)
    {
        bool isBFound = false;

        for (auto x : s)
            if (x == 'b')
                isBFound = true;
            else if (isBFound)
                return false;

        return true;
    }
};