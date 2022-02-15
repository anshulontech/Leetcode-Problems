// Link To Problem:-
// https://leetcode.com/problems/sort-even-and-odd-indices-independently/

// Solution:-

class Solution
{
public:
    vector<int> sortEvenOdd(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> temp;

        for (int i = 0; i < n; i += 2)
            temp.push_back(nums[i]);

        sort(temp.begin(), temp.end());

        for (int i = 0, k = 0; i < n; i += 2, k++)
            nums[i] = temp[k];

        temp.clear();

        for (int i = 1; i < n; i += 2)
            temp.push_back(nums[i]);

        sort(temp.begin(), temp.end());

        for (int i = 1, k = temp.size() - 1; i < n; i += 2, k--)
            nums[i] = temp[k];

        return nums;
    }
};