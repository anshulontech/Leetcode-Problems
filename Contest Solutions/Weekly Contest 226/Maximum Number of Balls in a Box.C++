// Solution:-

class Solution
{
public:
    int countBalls(int lowLimit, int highLimit)
    {
        vector<int> arr(47, 0);

        for (int i = lowLimit; i <= highLimit; i++)
        {
            int val = i;
            int sum = 0;
            while (val)
            {
                sum += (val % 10);
                val /= 10;
            }

            arr[sum]++;
        }

        int res = -1;
        for (int i = 0; i < 47; i++)
            res = max(res, arr[i]);

        return res;
    }
};