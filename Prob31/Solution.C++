// Link To Problem:-
// https://leetcode.com/problems/next-permutation/

void swap(int *, int *);

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int i = nums.size() - 1;
        while (i > 0 && nums[i] <= nums[i - 1])
            i--;
        if (i <= 0)
        {
            sort(nums.begin(), nums.end());
            return;
        }

        else
        {
            i--;
            int j;
            for (j = nums.size() - 1; j > i; j--)
                if (nums[j] > nums[i])
                    break;

            swap(&nums[j], &nums[i]);
            sort(nums.begin() + i + 1, nums.end());
            return;
        }

        return;
    }
};

void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}