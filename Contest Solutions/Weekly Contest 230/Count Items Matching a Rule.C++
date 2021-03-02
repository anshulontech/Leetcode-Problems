// Solution:-

class Solution
{
public:
    int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
    {
        int idx = -1;

        if (ruleKey == "type")
            idx = 0;
        else if (ruleKey == "color")
            idx = 1;
        else
            idx = 2;

        int res = 0;

        for (auto &x : items)
            if (x[idx] == ruleValue)
                res++;

        return res;
    }
};