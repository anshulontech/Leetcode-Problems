// Link To Problem:-
// https://leetcode.com/problems/group-anagrams/

// Approach 1:-

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &str)
    {
        unordered_map<string, vector<string>> temp;
        for (int i = 0; i < str.size(); i++)
        {
            string curr = str[i];
            sort(curr.begin(), curr.end());

            if (temp.find(curr) == temp.end())
                temp[curr].push_back(str[i]);
            else
                temp[curr].push_back(str[i]);
        }

        vector<vector<string>> res;

        for (auto x : temp)
            res.push_back(x.second);

        return res;
    }
};

// Approach:-2

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &str)
    {
        unordered_map<string, vector<string>> temp;
        for (int i = 0; i < str.size(); i++)
        {
            string curr = str[i];
            StrSort(curr);

            temp[curr].push_back(str[i]);
        }

        vector<vector<string>> res;

        for (auto x : temp)
            res.push_back(x.second);

        return res;
    }

private:
    void StrSort(string &s)
    {
        char store[26] = {0};
        for (int i = 0; i < s.size(); i++)
            store[s[i] - 97]++;

        s.clear();
        for (int i = 0; i < 26; i++)
            s += string(store[i], i + 97);

        return;
    }
};