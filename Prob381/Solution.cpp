// Approach 1 :-

class RandomizedCollection
{
private:
    vector<pair<int, int>> nums;
    unordered_map<int, vector<int>> store;

public:
    RandomizedCollection()
    {
    }

    bool insert(int val)
    {
        bool result = store.find(val) == store.end();

        store[val].push_back(nums.size());
        nums.push_back({val, store[val].size() - 1});

        return result;
    }

    bool remove(int val)
    {
        bool result = store.find(val) != store.end();
        if (result)
        {
            auto last = nums.back();
            store[last.first][last.second] = store[val].back();
            nums[store[val].back()] = last;
            store[val].pop_back();
            if (store[val].empty())
                store.erase(val);

            nums.pop_back();
        }

        return result;
    }

    int getRandom()
    {
        return nums[rand() % nums.size()].first;
    }
};
