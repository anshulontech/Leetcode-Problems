// Link To Prolem:-
// https://leetcode.com/problems/permutation-sequence/

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        vector<int> fact(n, 1);
        vector<int> digits(n, 1);

        for (int i = 1; i < n; i++)
        {
            fact[i] = fact[i - 1] * (i + 1);
            digits[i] = i + 1;
        }

        string res = "";

        while (res.size() < n - 1)
        {
            int repeat = fact[fact.size() - 2];
            int next_digit = (k - 1) / repeat;

            res += to_string(digits[next_digit]);
            digits.erase(digits.begin() + next_digit);
            fact.pop_back();
            k = k % repeat;

            if (k == 0)
                for (int i = digits.size() - 1; i >= 0; i--)
                    res += to_string(digits[i]);
        }

        if (res.size() < n)
            res += to_string(digits[0]);

        return res;
    }
};