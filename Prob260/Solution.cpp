// Approahc 1 :-

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> store;

        for (int i = 0; i < nums.size(); i++)
            store[nums[i]]++;

        vector<int> res;

        for (auto x : store)
            if (x.second < 2)
                res.push_back(x.first);

        return res;
    }
};