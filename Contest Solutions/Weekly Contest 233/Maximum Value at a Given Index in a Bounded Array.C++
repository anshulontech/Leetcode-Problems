// Solution:-

class Solution
{
public:
    int maxValue(int n, int index, int maxSum)
    {
        long long leftCount = index, rightCount = n - 1 - index;
        maxSum -= n;

        long long start = 0, end = maxSum;

        while (start < end)
        {
            long long mid = (end + start + 1) / 2;

            if (check(leftCount, rightCount, mid, maxSum))
                start = mid;
            else
                end = mid - 1;
        }

        return start + 1;
    }

private:
    bool check(long long leftCount, long long rightCount, long long mid, long long maxSum)
    {
        long long leftSum;
        if (leftCount > mid)
            leftSum = mid * (mid - 1) / 2;
        else
            leftSum = (leftCount * (2 * mid - leftCount - 1)) / 2;

        long long rightSum;
        if (rightCount > mid)
            rightSum = mid * (mid - 1) / 2;
        else
            rightSum = (rightCount * (2 * mid - rightCount - 1)) / 2;

        return (leftSum + rightSum + mid) <= maxSum;
    }
};