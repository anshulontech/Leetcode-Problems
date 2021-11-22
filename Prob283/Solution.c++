// Link To Problem:-
// https://leetcode.com/problems/move-zeroes/

// METHOD 1:-

void swap(int *, int *);

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != 0)
            {
                swap(&nums[i], &nums[j]);
                j++;
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