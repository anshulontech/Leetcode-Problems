// Solution:-

class Solution
{
public:
    int findNthDigit(int n)
    {
        int num = 9;
        long long digits = 1;

        while (n > num * digits)
        {
            n -= num * digits;
            num *= 10;
            digits++;
        }

        long val = (n - 1) / digits;
        long pos = (n - 1) % digits;

        string res = to_string(pow(10, digits - 1) + val);

        return res[pos] - '0';
    }
};