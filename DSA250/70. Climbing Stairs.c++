// Link To The Problem:-
//  https://leetcode.com/problems/climbing-stairs/submissions/

// Solution:-

class Solution
{
public:
    int climbStairs(int n)
    {
        int first = 1, second = 1;

        int i = 1;

        while (i < n)
        {
            int temp = first + second;
            first = second;
            second = temp;

            i++;
        }

        return second;
    }
};