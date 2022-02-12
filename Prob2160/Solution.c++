// Link To The Problem:-
// https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/

// Solution:-

class Solution
{
public:
    int minimumSum(int num)
    {
        string s = to_string(num);

        sort(s.begin(), s.end());

        return (s[0] - '0') * 10 + (s[1] - '0') * 10 + (s[2] - '0') + (s[3] - '0');
    }
};