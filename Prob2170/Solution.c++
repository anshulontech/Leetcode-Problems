// Link To The Problem:-
// https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating/

// Solution:-

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return 0;

        unordered_map<int, int> a, b;

        for (int i = 0; i < n; i++)
            if (i % 2 == 0)
                a[nums[i]]++;
            else
                b[nums[i]]++;

        int aFirstMax = -1, aFirstMaxCount = 0, aSecondMax = -1, aSecondMaxCount = 0;

        for (auto x : a)
        {
            if (x.second > aFirstMaxCount)
            {
                aSecondMax = aFirstMax;
                aSecondMaxCount = aFirstMaxCount;
                aFirstMax = x.first;
                aFirstMaxCount = x.second;
            }
            else if (x.second > aSecondMaxCount)
            {
                aSecondMax = x.first;
                aSecondMaxCount = x.second;
            }
        }

        int bFirstMax = -1, bFirstMaxCount = 0, bSecondMax = -1, bSecondMaxCount = 0;

        for (auto x : b)
        {
            if (x.second > bFirstMaxCount)
            {
                bSecondMax = bFirstMax;
                bSecondMaxCount = bFirstMaxCount;
                bFirstMax = x.first;
                bFirstMaxCount = x.second;
            }
            else if (x.second > bSecondMaxCount)
            {
                bSecondMax = x.first;
                bSecondMaxCount = x.second;
            }
        }

        if (aFirstMax != bFirstMax)
        {
            return n - aFirstMaxCount - bFirstMaxCount;
        }

        return min(n - aFirstMaxCount - bSecondMaxCount, n - aSecondMaxCount - bFirstMaxCount);
    }
};