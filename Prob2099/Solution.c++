// Link To Problem:-
// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

// Solution:-

class Solution
{
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        vector<int> temp = nums;

        sort(temp.begin(), temp.end());

        unordered_map<int, int> map;

        int len = nums.size();

        for (int i = 0; i < k; i++)
            map[temp[len - 1 - i]]++;

        vector<int> res;

        for (auto x : nums)
            if (map[x] != 0)
            {
                res.push_back(x);
                map[x]--;
            }

        return res;
    }
};