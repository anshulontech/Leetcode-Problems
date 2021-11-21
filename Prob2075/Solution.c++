// Link To Problem:-
// https://leetcode.com/problems/decode-the-slanted-ciphertext/

// Solution:-

class Solution
{
public:
    string decodeCiphertext(string e, int rows)
    {
        string res = "";
        int n = e.size(), col = n / rows, next = col + 1;

        for (int i = 0; i < col; i++)
            for (int j = i; j < n; j += next)
                res += e[j];

        int len = res.size(), count = 0;

        for (int i = len - 1; i >= 0 && res[i] == ' '; i--)
            count++;

        res = res.substr(0, len - count);

        return res;
    }
};