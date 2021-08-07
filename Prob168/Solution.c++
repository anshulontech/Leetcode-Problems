// Link To Problem:-
// https://leetcode.com/problems/excel-sheet-column-title/

// METHOD 1:-

class Solution
{
public:
    string convertToTitle(int n)
    {
        string s;
        while (n)
        {
            n--;
            char temp = 'A' + n % 26;
            n = n / 26;
            s = temp + s;
        }

        return s;
    }
};