// https://leetcode.com/problems/add-digits/description/

// Space Complexity:-O(1).

// Approach:-
//     Till num will not become less tha  we will change num with the sum of digits.

class Solution
{
public:
    int addDigits(int num)
    {
        while (num > 9)
        {
            int sum = 0;

            while (num > 0)
            {
                sum += num % 10;
                num /= 10;
            }

            num = sum;
        }

        return num;
    }
};