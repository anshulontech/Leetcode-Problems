// Link To Problem:-
// https://leetcode.com/problems/longest-consecutive-sequence/

// METHOD 1:-

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, int> store;
        int res = 0;

        for (int i = 0; i < nums.size(); i++)
            store[nums[i]]++;

        for (int i = 0; i < nums.size(); i++)
            if (store[nums[i]] != 0)
            {

                int curr = 1;
                int k = 1;

                while (store[nums[i] + k] != 0)
                {
                    store[nums[i] + k] = 0;
                    k++;
                    curr++;
                }

                k = 1;
                while (store[nums[i] - k] != 0)
                {
                    store[nums[i] - k] = 0;
                    k++;
                    curr++;
                }

                if (curr > res)
                    res = curr;
            }

        return res;
    }
};

// METHOD 2:-

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, int> store;
        int res = 0;

        for (int i = 0; i < nums.size(); i++)
            store[nums[i]]++;

        for (auto x : store)
        {
            int i = 1;
            int curr = 1;

            while (store.find(x.first + i) != store.end())
            {
                store.erase(store.find(x.first + i));
                i++;
                curr++;
            }

            i = 1;
            while (store.find(x.first - i) != store.end())
            {
                store.erase(store.find(x.first - i));
                i++;
                curr++;
            }

            if (curr > res)
                res = curr;
        }

        return res;
    }
};

// METHOD 3:-

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> store;
        int res = 0;

        for (int i = 0; i < nums.size(); i++)
            store.insert(nums[i]);

        for (auto x : store)
        {
            int i = 1;
            int curr = 1;

            while (store.find(x + i) != store.end())
            {
                store.erase(store.find(x + i));
                i++;
                curr++;
            }

            i = 1;
            while (store.find(x - i) != store.end())
            {
                store.erase(store.find(x - i));
                i++;
                curr++;
            }

            if (curr > res)
                res = curr;
        }

        return res;
    }
};