// https://leetcode.com/problems/arranging-coins/description/

// Time Complexity:-O(1).
// Space Complexity:-O(1).
    
// Approach:-
//     Use the concept of quadratic formulae .

class Solution {
public:
    int arrangeCoins(int n) {
        return (int )(sqrt(.25+2*(long)n)-0.5);
    }
};

// Time Complexity:-O(log(n)).
// Space Complexity:-O(1).

// Approach:-
//     Use the concept of Binary search to find the number.

class Solution
{
public:
    int arrangeCoins(int n)
    {
        int start = 0, end = n;

        while (start <= end)
        {
            long mid = start + (end - start) / 2;

            long curr = mid * (mid + 1) / 2;

            if (curr == n)
                return (int)mid;

            if (curr < n)
                start = mid + 1;
            else
                end = mid - 1;
        }

        return (int)end;
    }
};