// Link To Problem:-
// https://leetcode.com/problems/excel-sheet-column-number/

// METHOD 1:-

class Solution
{
public:
    int titleToNumber(string s)
    {
        int count = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
            count += pow(26, i) * (s[n - i - 1] - 'A' + 1);

        return count;
    }
};