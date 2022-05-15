// Link To The Problem:-
// https://leetcode.com/problems/plus-one/

// Solution:-

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 1;
        int i = digits.size() - 1;

        while (carry && i >= 0)
        {
            digits[i]++;
            carry = digits[i] / 10;
            digits[i] %= 10;
            i--;
        }

        if (carry)
        {
            digits[0] = 1;
            digits.push_back(0);
        }

        return digits;
    }
};