// Approach 1:-

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string res = "";

        int i = num1.size() - 1, j = num2.size() - 1;
        int carry = 0, ans;

        while (i >= 0 && j >= 0)
        {
            ans = num1[i] - '0' + num2[j] - '0' + carry;
            carry = ans / 10;
            res += to_string(ans % 10);
            i--, j--;
        }

        while (i >= 0)
        {
            ans = num1[i] - '0' + carry;
            carry = ans / 10;
            res += to_string(ans % 10);
            i--;
        }

        while (j >= 0)
        {
            ans = num2[j] - '0' + carry;
            carry = ans / 10;
            res += to_string(ans % 10);
            j--;
        }

        if (carry)
            res += to_string(carry);

        reverse(res.begin(), res.end());

        return res;
    }
};