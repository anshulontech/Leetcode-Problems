// Link To The Problem:-
// https://leetcode.com/problems/calculate-digit-sum-of-a-string/

// Solution:-

class Solution
{
public:
    string digitSum(string s, int k)
    {
        if (s.size() <= k)
            return s;

        string temp = "";
        int n = s.size();

        for (int i = 0; i < n;)
        {
            int sum = 0;
            for (int x = 0; x < k && i < n; x++, i++)
                sum += s[i] - '0';

            temp += to_string(sum);
        }

        return digitSum(temp, k);
    }
};