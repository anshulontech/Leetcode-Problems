// Link To Problem:-
// https://leetcode.com/problems/maximum-units-on-a-truck/

// Solution:-

class Solution
{
public:
    int maximumUnits(vector<vector<int>> &T, int S)
    {
        sort(T.begin(), T.end(), [](auto &left, auto &right) {
            return left[1] > right[1];
        });
        int count = 0, curr = 0;

        int n = T.size();

        for (int i = 0; i < n && curr < S; i++)
        {
            if (curr + T[i][0] <= S)
            {
                curr += T[i][0];
                count += (T[i][0] * T[i][1]);
            }
            else
            {
                int val = S - curr;
                count += (val * T[i][1]);
                curr = S;
            }
        }

        return count;
    }
};