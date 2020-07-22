// Approach 1:-

class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> store;

        for (int i = 0; i < s.size(); i++)
            store[s[i]]++;

        int flag = 0, sets = 0;

        for (auto x : store)
        {
            if (x.second % 2 != 0)
                flag = 1;

            sets += x.second / 2;
        }

        return sets * 2 + (flag ? 1 : 0);
    }
};