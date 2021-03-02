// Solution:-

class Solution
{
public:
    int minOperations(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();

        if (n2 > n1 * 6 || n1 > n2 * 6)
            return -1;

        int sum1 = 0, sum2 = 0;
        for (auto &x : nums1)
            sum1 += x;

        for (auto &x : nums2)
            sum2 += x;

        if (sum1 < sum2)
            return helper(nums1, sum1, n1, nums2, sum2, n2);
        else
            return helper(nums2, sum2, n2, nums1, sum1, n1);
    }

private:
    int helper(vector<int> &nums1, int &sum1, int &n1, vector<int> &nums2, int &sum2, int &n2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = n2 - 1;
        int res = 0;

        while (sum1 != sum2 && i < n1 && j >= 0)
        {
            res++;
            int val1 = 6 - nums1[i];
            int val2 = nums2[j] - 1;
            int currDiff = sum2 - sum1;

            if (val1 < val2)
            {
                sum2 -= min(currDiff, val2);
                j--;
            }
            else
            {
                sum1 += min(currDiff, val1);
                i++;
            }
        }

        while (sum1 != sum2 && i < n1)
        {
            res++;
            sum1 += min(sum2 - sum1, 6 - nums1[i]);
            i++;
        }

        while (sum1 != sum2 && j >= 0)
        {
            res++;
            sum2 -= min(sum2 - sum2, nums2[j] - 1);
            j--;
        }

        return res;
    }
};