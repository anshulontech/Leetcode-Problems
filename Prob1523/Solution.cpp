// Approach 1 :-

class Solution
{
public:
    int countOdds(int low, int high)
    {
        int res = 0;
        for (int i = low; i <= high; i++)
            if (i % 2 != 0)
                res++;

        return res;
    }
};

// Approach 2 :-

class Solution
{
public:
    int countOdds(int low, int high)
    {
        return (high + 1) / 2 - low / 2;
    }
};