// Link To The Problem:-
// https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/

// Solution:-

class Solution
{
public:
    int largestInteger(int num)
    {
        string odd = "", even = "";

        int x = num;

        while (x)
        {
            int val = x % 10;
            if (val % 2 == 0)
                even += to_string(val);
            else
                odd += to_string(val);

            x /= 10;
        }

        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());

        int res = 0, p1 = 0, p2 = 0, ten = 0;

        while (num)
        {
            if (num % 2 == 0)
                res += pow(10, ten) * (even[p1++] - '0');
            else
                res += pow(10, ten) * (odd[p2++] - '0');

            ten++;

            num /= 10;
        }

        return res;
    }
};