// Link To The Problem:-
// https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/

// Solution:-

class Solution
{
public:
    vector<int> executeInstructions(int n, vector<int> &startPos, string s)
    {
        vector<int> res;
        int m = s.size();

        for (int i = 0; i < m; i++)
        {
            int x = startPos[0], y = startPos[1];

            int j = i;
            while (j < m)
            {
                if (s[j] == 'L')
                    y--;
                else if (s[j] == 'R')
                    y++;
                else if (s[j] == 'U')
                    x--;
                else
                    x++;

                if (x < 0 || y < 0 || x == n || y == n)
                    break;
                j++;
            }

            res.push_back(j - i);
        }

        return res;
    }
};