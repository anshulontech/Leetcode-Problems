// Solution:-

class Solution
{
public:
    bool isThree(int n)
    {
        if (n == 1)
            return false;
        int x = sqrt(n);
        return isPrime(x) && x * x == n;
    }

    bool isPrime(int n)
    {
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0)
                return false;

        return true;
    }
};