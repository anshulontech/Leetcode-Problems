// Link To Problem:-
// https://leetcode.com/problems/largest-number/submissions/

// METHOD 1:-

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> store;
        for (int i = 0; i < nums.size(); i++)
            store.push_back(to_string(nums[i]));

        for (int i = 0; i < store.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                if ((store[i] + store[j]) < (store[j] + store[i]))
                    swap(store[i], store[j]);

        string res = "";

        for (int i = 0; i < store.size(); i++)
            res += store[i];

        while (res[0] == '0' && res.length() > 1)
            res.erase(0, 1);

        return res;
    }
};

// METHOD 2:-

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> store;
        for (int i = 0; i < nums.size(); i++)
            store.push_back(to_string(nums[i]));

        sort(store.begin(), store.end(), [](string &s1, string &s2)
             { return s1 + s2 > s2 + s1; });

        string res = "";

        for (int i = 0; i < store.size(); i++)
            res += store[i];

        while (res[0] == '0' && res.length() > 1)
            res.erase(0, 1);

        return res;
    }
};