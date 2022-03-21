// Link To The Problem:-
// https://leetcode.com/problems/append-k-integers-with-minimal-sum/

// Solution:-

class Solution
{
public:
    vector<string> cellsInRange(string s)
    {
        vector<string> res;
        string temp;

        for (char c = s[0]; c <= s[3]; c++)
            for (char x = s[1]; x <= s[4]; x++)
            {
                temp = "";
                temp += c;
                temp += x;
                res.push_back(temp);
            }

        return res;
    }
};