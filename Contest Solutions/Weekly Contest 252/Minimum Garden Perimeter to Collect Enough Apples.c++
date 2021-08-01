// Solution:-

class Solution
{
public:
    long long minimumPerimeter(long long neededApples)
    {
        long long x = 1, currApple = 12, perimeter = 12, prevVal = 0;

        while (currApple < neededApples)
        {
            x++;
            prevVal = currApple;
            currApple = currApple + perimeter + ((x - 1) * 2 + 1) * 4 + (x - 1) * 8 + x * 8;
            perimeter = currApple - prevVal;
        }

        return x * 8;
    }
};