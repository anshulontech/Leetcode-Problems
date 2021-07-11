// Solution:-

class Solution
{
public:
    int countTriples(int n)
    {
        int res = 0;

        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++)
                if (isValid(i, j, n))
                    res += 2;

        return res;
    }

    bool isValid(int f, int s, int n)
    {
        int temp = f * f + s * s;

        int root = sqrt(temp);

        if (root * root == temp && root <= n)
            return true;
        else
            return false;
    }
};