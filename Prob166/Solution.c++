// Link To Problem:-
// https://leetcode.com/problems/fraction-to-recurring-decimal/

class Solution
{
public:
    string fractionToDecimal(int num, int den)
    {
        string res = "";
        if ((num > 0 && den < 0) || (num < 0 && den > 0))
            res += '-';

        long n = labs(num), d = labs(den), r = n % d;

        res += to_string(n / d);

        if (!r)
        {
            return res;
        }
        else
            res += '.';

        unordered_map<long, int> remainder;

        while (r)
        {
            if (remainder.find(r) != remainder.end())
            {
                res.insert(remainder[r], "(");
                res += ')';

                break;
            }
            remainder[r] = res.size();
            r *= 10;
            res += to_string(r / d);
            r %= d;
        }

        return res;
    }
};