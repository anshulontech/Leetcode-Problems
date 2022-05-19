// Link To The Problem:-
//  https://leetcode.com/problems/find-all-duplicates-in-an-array/

// Solution:-

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> res;

        int n = nums.size();

        bool isN = false;
        for (int i = 0; i < n; i++)
        {
            if (abs(nums[i]) == n)
            {
                if (isN)
                    res.push_back(n);
                else
                    isN = true;
            }
            else
            {

                if (nums[abs(nums[i])] < 0)
                    res.push_back(abs(nums[i]));

                nums[abs(nums[i])] *= -1;
            }
        }

        return res;
    }
};