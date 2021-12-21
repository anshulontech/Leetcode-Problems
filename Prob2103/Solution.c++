// Link To Problem:-
// https://leetcode.com/problems/rings-and-rods/

// Solution:-

class Solution
{
public:
    int countPoints(string s)
    {
        int n = s.size();
        vector<vector<bool>> rods(10, vector<bool>(3, false));

        for (int i = 0; i < n; i = i + 2)
        {
            if (s[i] == 'R')
                rods[s[i + 1] - '0'][0] = true;
            else if (s[i] == 'G')
                rods[s[i + 1] - '0'][1] = true;
            else if (s[i] == 'B')
                rods[s[i + 1] - '0'][2] = true;
        }

        int res = 0;

        for (auto x : rods)
            if (x[0] && x[1] && x[2])
                res++;

        return res;
    }
};