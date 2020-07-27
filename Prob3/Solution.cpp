// Approach 1:-

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int len = 0;
        unordered_set<char> store;

        for (int i = 0; i < s.size(); i++)
        {
            int j = i;
            for (; j < s.size(); j++)
                if (store.find(s[j]) != store.end())
                    break;
                else
                    store.insert(s[j]);

            len = max(len, j - i);

            store.clear();
        }

        return len;
    }
};

// Approach 2 :-

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int len = 0;

        int start = 0, end = 0;

        unordered_set<char> store;

        while (end < s.size())
            if (store.find(s[end]) != store.end())
                store.erase(store.find(s[start++]));
            else
            {
                store.insert(s[end++]);
                len = max(len, end - start);
            }

        return len;
    }
};