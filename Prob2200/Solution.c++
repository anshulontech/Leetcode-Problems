// Link To The Problem:-
// https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/

// Solution:-

class Solution
{
public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
    {
        vector<int> res;

        int i = 0, j = 0, n = nums.size();

        while (i < n && j < n)
        {
            if (nums[i] == key)
            {
                while (j < n && (j - i) <= k)
                {
                    if (abs(j - i) <= k)
                        res.push_back(j);

                    j++;
                }
            }

            i++;
        }

        return res;
    }
};