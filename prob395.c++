// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/

// Time Complexity:-O(N^2).
// Space Complexity:-O(N^2).
    
// Approach:-
//     In this what we are going to do is the use of divide and conqure approach. So initially we will count the 
// occurence of each character in a map . Now we will start to traverse the string till the character whose count is 
// not less than k. At this stage we will divide the substring into two parts left and right and than check individually 
// for these strings using recurssion and than return the max result that would come from these two.

class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        if (s.size() < k)
            return 0;

        if (k == 0)
            return s.size();

        unordered_map<char, int> store;

        for (int i = 0; i < s.size(); i++)
            store[s[i]]++;

        int idx = 0;

        while (idx < s.size() && store[s[idx]] >= k)
            idx++;

        if (idx == s.size())
            return s.size();

        int left = longestSubstring(s.substr(0, idx), k);

        while (idx < s.size() && store[s[idx]] < k)
            idx++;

        int right = longestSubstring(s.substr(idx), k);

        return max(left, right);
    }
};