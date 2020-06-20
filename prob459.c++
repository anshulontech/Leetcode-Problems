// https://leetcode.com/problems/repeated-substring-pattern/

// Time Complexity:-O(N^2).
// Space Complexity:-O(1).
    
// Approach:-
//     In this what we are going to do is that if we will found any index same as that f 0th index than we will check 
// that is that part would be a repeated substring or not. If it will than return true else move on. Now if no such 
// part occur than we will return false.

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int i = 1;

        while (i <= s.size() / 2)
            if (s[i] == s[0] && check(s, i))
                return true;
            else
                i++;

        return false;
    }

    bool check(string &s, int &end)
    {
        string temp = s.substr(0, end);

        int i = end;

        while (i < s.size())
            if (s.substr(i, end) == temp)
                i += end;
            else
                return false;

        return true;
    }
};

// Time Complexity:-O(N).
// Space Complexity:-O(N).

// Approach:-
    // Using KMP Algorithm.

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        if (s.size() < 2)
            return false;
        int len = s.size(), i = 0, j = 1;
        vector<int> dp(len);

        while (j < len)
            if (s[i] == s[j])
                dp[j++] = ++i;
            else if (i == 0)
                dp[j++] = 0;
            else
                i = dp[i - 1];

        return dp[len - 1] && len % (len - dp[len - 1]) == 0;
    }
};