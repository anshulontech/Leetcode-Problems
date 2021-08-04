// Solution:-

class Solution
{
public:
    bool areOccurrencesEqual(string s)
    {
        vector<int> count(26, 0);
        int val = 0;

        for (auto x : s)
        {
            count[x - 'a']++;
            val = count[x - 'a'];
        }

        for (auto x : count)
            if (x != 0 && x != val)
                return false;

        return true;
    }
};