// Link To Problem:-
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {

        vector<string> res;

        if (digits.size() == 0)
            return res;
        vector<string> store = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        for (int i = 0; i < store[digits[0] - '0'].size(); i++)
        {
            string s;
            s.push_back(store[digits[0] - '0'][i]);
            combination(store, digits, res, s, 1);
            s.erase(s.size() - 1, 1);
        }

        return res;
    }

    void combination(vector<string> &store, string &digits, vector<string> &res, string &s, int poisition)
    {
        if (poisition == digits.size())
        {
            res.push_back(s);
            return;
        }

        for (int i = 0; i < store[digits[poisition] - '0'].size(); i++)
        {
            s.push_back(store[digits[poisition] - '0'][i]);
            combination(store, digits, res, s, poisition + 1);
            s.erase(s.size() - 1, 1);
        }

        return;
    }
};