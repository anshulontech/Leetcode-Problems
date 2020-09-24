// Approach 1:-

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        unordered_map<char, int> store;

        for (auto x : s)
            store[x]++;

        for (auto x : t)
            if (store[x] == 0)
                return x;
            else
                store[x]--;

        return NULL;
    }
};

// Approach 2:-

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        int n = t.size() - 1;

        char c = t[n];

        for (int i = 0; i < n; i++)
        {
            c ^= s[i];
            c ^= t[i];
        }

        return c;
    }
};
