// Link To Problem:-
// https://leetcode.com/problems/rearrange-array-elements-by-sign/

// Solution:-

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> res(n, 0);

        int first = 0, second = 0, k = 0;

        while (first < n && second < n)
        {
            while (first < n && nums[first] > 0)
                first++;
            while (second < n && nums[second] < 0)
                second++;

            res[k++] = nums[second];
            res[k++] = nums[first];

            first++;
            second++;
        }

        return res;
    }
};