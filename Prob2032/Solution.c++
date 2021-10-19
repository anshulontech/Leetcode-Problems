// Link To Problem:-
// https://leetcode.com/problems/two-out-of-three/

// Solution:-

class Solution
{
public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
    {

        vector<vector<int>> arr(101, vector<int>(3, 0));

        for (auto x : nums1)
            arr[x][0] = 1;
        for (auto x : nums2)
            arr[x][1] = 1;
        for (auto x : nums3)
            arr[x][2] = 1;

        vector<int> res;

        for (int i = 0; i < 101; i++)
        {
            if (arr[i][0] + arr[i][1] + arr[i][2] >= 2)
                res.push_back(i);
        }

        return res;
    }
};