// Link To Problem:-
// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/

// METHOD 1:-

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