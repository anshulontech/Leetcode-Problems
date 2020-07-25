// Approach 1:-

class Solution
{
public:
    int numSplits(string s)
    {
        int res = 0;

        unordered_map<char, int> store;
        unordered_set<char> set2;
        unordered_set<char> set1;

        set1.insert(s[0]);

        for (int i = 1; i < s.size(); i++)
        {
            store[s[i]]++;
            set2.insert(s[i]);
        }

        if (set1.size() == set2.size())
            res++;

        for (int i = 1; i < s.size(); i++)
        {
            store[s[i]]--;
            if (store[s[i]] == 0)
                set2.erase(set2.find(s[i]));

            set1.insert(s[i]);

            if (set1.size() == set2.size())
                res++;
        }

        return res;
    }
};