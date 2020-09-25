// Approach 1:-

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> store;
        int n = nums.size();
        vector<int> res;

        for (int i = 0; i < n; i++)
            store[nums[i]]++;

        for (auto x : store)
            if (x.second > n / 3)
                res.push_back(x.first);

        return res;
    }
};