// Link To Problem:-
// https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/submissions/

// Solution:-

class Solution
{
public:
    vector<int> findLonely(vector<int> &nums)
    {
        unordered_map<int, int> freq;

        for (auto x : nums)
            freq[x]++;

        vector<int> res;

        for (auto x : nums)
            if (freq[x] == 1 && freq[x - 1] == 0 && freq[x + 1] == 0)
                res.push_back(x);

        return res;
    }
};

// Also possible by sorting the array, with O(1) space complexity.