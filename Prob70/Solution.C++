// Link To Problem:-
// https://leetcode.com/problems/climbing-stairs/

// METHOD 1:-

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n < 2)
            return 1;
        vector<int> store(n + 1);

        store[0] = 1;
        store[1] = 1;

        for (int i = 2; i < n + 1; i++)
            store[i] = store[i - 1] + store[i - 2];

        return store[n];
    }
};

// METHOD 2:-

class Solution
{
public:
    int climbStairs(int n)
    {
        int first_last = 1, second_last = 1;

        for (int i = 2; i < n + 1; i++)
        {
            int temp = first_last + second_last;
            second_last = first_last;
            first_last = temp;
        }

        return first_last;
    }
};