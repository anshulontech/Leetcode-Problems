// https://leetcode.com/problems/plus-one/

// Time Complexity:-O(N).
// Space Complexity:-O(1).

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int i = digits.size() - 1;

        while (i >= 0 && digits[i] == 9)
            i--;

        if (i < 0)
        {
            digits.push_back(0);

            digits[0] = 1;

            for (i = 1; i < digits.size(); i++)
                digits[i] = 0;
        }
        else
        {
            digits[i] += 1;
            for (i = i + 1; i < digits.size(); i++)
                digits[i] = 0;
        }

        return digits;
    }
};