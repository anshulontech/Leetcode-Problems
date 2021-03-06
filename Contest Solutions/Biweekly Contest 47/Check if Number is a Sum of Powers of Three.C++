// Solution:-

class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        if (n == 0)
            return true;

        return helper(n, 0);
    }

private:
    bool helper(int n, int idx)
    {
        if (n == 0)
            return true;

        if (n < pow(3, idx))
            return false;

        return helper(n - pow(3, idx), idx + 1) || helper(n, idx + 1);
    }
};