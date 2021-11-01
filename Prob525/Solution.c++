// Link To Problem:-
// https://leetcode.com/problems/contiguous-array/submissions/

// METHOD 1:-

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> store;
        store.insert(make_pair(0, -1));

        int count = 0;
        int max_length = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                count--;
            else
                count++;

            if (store.find(count) != store.end())
                max_length = max(max_length, i - store[count]);
            else
                store.insert(make_pair(count, i));
        }

        return max_length;
    }
};