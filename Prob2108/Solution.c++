// Link To Problem:-
// https://leetcode.com/problems/find-first-palindromic-string-in-the-array/

// Solution:-

class Solution
{
public:
    string firstPalindrome(vector<string> &words)
    {
        for (auto x : words)
        {
            int start = 0, end = x.size() - 1;

            while (start < end && x[start] == x[end])
                start++, end--;

            if (start >= end)
                return x;
        }
        return "";
    }
};