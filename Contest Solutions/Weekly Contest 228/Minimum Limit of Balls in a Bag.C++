// Solution:-

class Solution
{
private:
    bool check(vector<int> &nums, int m, int O)
    {
        int n = nums.size();
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            temp += nums[i] / m;
            if (nums[i] % m == 0)
                temp--;
        }

        return temp <= O;
    }

public:
    int minimumSize(vector<int> &nums, int O)
    {
        int start = 1, end = INT_MAX;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (check(nums, mid, O))
                end = mid - 1;
            else
                start = mid + 1;
        }

        return start;
    }
};