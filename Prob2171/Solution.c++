// Link To The Problem:-
// https://leetcode.com/problems/removing-minimum-number-of-magic-beans/

// Solution 1:-

class Solution
{
public:
    long long minimumRemoval(vector<int> &beans)
    {
        long long n = beans.size();

        sort(beans.begin(), beans.end());
 
        vector<long long> leftBeans(n, 0);

        leftBeans[n - 1] = beans[n - 1];

        for (int i = n - 2; i >= 0; i--)
            leftBeans[i] = leftBeans[i + 1] + beans[i];

        long long res = LLONG_MAX;

        long long currSum = 0;

        for (long long i = 0; i < n; i++)
        {
            long long beansToRemoveNext = leftBeans[i] - (long long)beans[i] * (long long)(n - i);
            res = min(res, beansToRemoveNext + currSum);
            currSum += beans[i];
        }

        return min(res, currSum);
    }
};

// Solution 2:-

class Solution
{
public:
    long long minimumRemoval(vector<int> &beans)
    {
        long long n = beans.size();

        sort(beans.begin(), beans.end());

        long long sum = 0;
        for (auto x : beans)
            sum += (long long)x;

        long long res = LLONG_MAX;

        long long currSum = 0;

        for (long long i = 0; i < n; i++)
        {
            long long beansToRemoveNext = sum - (long long)beans[i] * (long long)(n - i);
            res = min(res, beansToRemoveNext + currSum);
            currSum += beans[i];
            sum -= beans[i];
        }

        return min(res, currSum);
    }
};