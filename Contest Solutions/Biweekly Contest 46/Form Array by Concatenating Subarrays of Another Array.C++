// Solution:-

class Solution
{
public:
    bool canChoose(vector<vector<int>> &groups, vector<int> &nums)
    {
        int n1 = groups.size(), n2 = nums.size();

        int i = n1 - 1, j = n2 - 1;

        while (i >= 0 && j >= 0)
        {

            int idx = findSubArray(nums, groups[i], j);
            j = idx;
            if (idx != -10)
                i--;
        }

        if (i < 0)
            return true;
        else
            return false;
    }

private:
    int findSubArray(vector<int> &nums, vector<int> subArray, int idx)
    {

        int n = subArray.size();
        for (int i = idx; i >= n - 1; i--)
        {
            int flag = 1;
            for (int j = 0; j < n; j++)
                if (nums[i - j] != subArray[n - j - 1])
                {
                    flag = 0;
                    break;
                }

            if (flag)
                return i - n;
        }

        return -10;
    }
};