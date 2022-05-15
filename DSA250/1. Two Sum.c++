// Link To The Problem:-
// https://leetcode.com/problems/two-sum/

// Solution:-

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;

        int i = 0;

        for (auto x : nums)
            if (map.find(target - x) != map.end())
                return {i, map[target - x]};
            else
                map[x] = i++;

        return {};
    }
};