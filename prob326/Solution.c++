// Link To Problem:-
// https://leetcode.com/problems/power-of-three/

// Method 1:-

// Time Complexity:-O(log(N)--base to 3).
// Space Complexity:-O(1).

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n < 1)
            return false;

        while (n % 3 == 0)
            n /= 3;

        return n == 1;
    }
};

// Method 2:-

// Time Complexity:-O(1).
// Space Complexity:-O(1).

// Knowing the limitation of n, we can now deduce that the maximum value of n that is also a power of three is 1162261467.

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        return n > 0 && 1162261467 % n == 0;
    }
};