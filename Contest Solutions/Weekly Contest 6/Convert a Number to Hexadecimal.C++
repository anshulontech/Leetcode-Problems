// Solution:-

class Solution
{
public:
    string toHex(int num)
    {
        if (num == 0)
            return "0";

        if (num < 0)
            return forNeg(num);

        string s = "0123456789abcdef";

        string res = "";

        while (num > 0)
        {
            res += s[num % 16];

            num /= 16;
        }

        reverse(res.begin(), res.end());

        return res;
    }

private:
    string forNeg(int num)
    {
        string s = "0123456789abcdef";
        string res = "ffffffff";

        num++;
        num = -num;

        int idx = 7;

        while (num > 0)
        {
            res[idx] = s[15 - num % 16];
            num /= 16;
            idx--;
        }

        return res;
    }
};