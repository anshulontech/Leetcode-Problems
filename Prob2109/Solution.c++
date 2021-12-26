// Link To Problem:-
// https://leetcode.com/problems/adding-spaces-to-a-string/

// Solution:-

class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        string res = "";
        int n = s.size(), idx = 0, m = spaces.size();

        for (int i = 0; i < n; i++)
        {
            if (idx < m && spaces[idx] == i)
            {
                idx++;
                res += ' ';
            }

            res += s[i];
        }

        return res;
    }
};