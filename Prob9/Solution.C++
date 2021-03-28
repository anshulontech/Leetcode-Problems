// https://leetcode.com/problems/palindrome-number/

// Approach 1:-

class Solution
{
public:
    bool isPalindrome(int x)
    {
        vector<int> A;
        if (x < 0)
            return 0;
        else
        {
            while (x > 0)
            {
                A.push_back(x % 10);
                x = x / 10;
            }
        }

        for (int i = 0; i < A.size() / 2; i++)
            if (A[i] != A[A.size() - 1 - i])
                return 0;

        return 1;
    }
};

// Approach 2:-

class Solution
{
public:
    bool isPalindrome(long int x)
    {
        if (x < 0)
            return 0;

        int run = 0;
        int y = x;
        while (y > 0)
        {
            run++;
            y = y / 10;
        }
        run--;
        while (x >= 10)
        {
            int p = pow(10, run);
            if (x % 10 != x / p)
                return 0;
            x = x % p;
            x = x / 10;
            run = run - 2;
        }
        if (run > 0 && x != 0)
            return 0;
        else
            return 1;
    }
};