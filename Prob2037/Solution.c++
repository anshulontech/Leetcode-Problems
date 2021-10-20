// Link To Problem:-
// https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/

// Solution:-

class Solution
{
public:
    int minMovesToSeat(vector<int> &se, vector<int> &st)
    {
        sort(se.begin(), se.end());
        sort(st.begin(), st.end());

        int res = 0, n = st.size();

        for (int i = 0; i < n; i++)
        {
            res += abs(st[i] - se[i]);
        }

        return res;
    }
};