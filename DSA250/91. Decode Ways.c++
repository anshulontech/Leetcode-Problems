// Link To The Problem:-
//  https://leetcode.com/problems/decode-ways/

// Solution:-

class Solution
{
public:
    int numDecodings(string s)
    {
        if (s[0] == '0')
            return 0;

        int fir = 1, sec = 1, n = s.size();

        for (int i = 1; i < n; i++)
        {
            if (s[i] == '0')
                sec = 0;

            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
            {
                int temp = sec + fir;
                fir = sec;
                sec = temp;
            }
            else
            {
                fir = sec;
            }
        }

        return sec;
    }
};