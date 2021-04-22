// Link To Problem:-
// https://leetcode.com/problems/substring-with-concatenation-of-all-words/

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> res;
        if (words.size() == 0 || s.size() == 0)
            return res;
        int length = words[0].size();
        int words_length = words.size();

        if (s.size() + 1 < length)
            return res;

        unordered_map<string, int> store;
        for (int i = 0; i < words.size(); i++)
            store[words[i]]++;

        for (int i = 0; i < s.size() - length * words_length + 1; i++)
        {
            string temp = s.substr(i, length);
            if (store[temp] != 0)
            {
                int count = 1;
                store[temp]--;
                check(store, s, i + length, count, res, words_length, length);
                store[temp]++;
            }
        }
        return res;
    }

    void check(unordered_map<string, int> &store, string &s, int i, int count, vector<int> &res, int words_length, int length)
    {
        if (count == words_length)
        {
            res.push_back(i - count * length);
            return;
        }

        string temp = s.substr(i, length);
        if (store[temp] != 0)
        {
            store[temp]--;
            check(store, s, i + length, count + 1, res, words_length, length);
            store[temp]++;
        }

        return;
    }
};