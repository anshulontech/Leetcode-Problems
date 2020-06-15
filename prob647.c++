// https://leetcode.com/problems/palindromic-substrings/

// Time Complexity:-O(N^2).  Worst.
// Space Complexity:-O(1).
    
// Aproach:-
//     We will use a expandPalindrome function which will tell us that on making that index as center how many palindromes 
// can be formed or also by making two element set as center. So for each index we will use this function for our help and 
// it will give us the the maximum number of palindromes formed by taking i as center and also taking i,i+1 as center and 
// we will store our result in variable res and finally return that one.

class Solution
{
public:
    int countSubstrings(string s)
    {
        int res = 0;

        for (int i = 0; i < s.size(); i++)
        {
            int first = 0, second = 0;

            expandPalindrome(s, i, i, first);
            expandPalindrome(s, i, i + 1, second);

            res += (first + second);
        }

        return res;
    }

    void expandPalindrome(string &s, int i, int j, int &count)
    {
        while (i >= 0 && j < s.size() && s[i] == s[j])
        {
            count++, i--, j++;
        }

        return;
    }
};