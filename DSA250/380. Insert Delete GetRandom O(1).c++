// Link To The Problem:-
//  https://leetcode.com/problems/insert-delete-getrandom-o1/

// Solution:-

class RandomizedSet
{
    unordered_map<int, int> map;
    vector<int> arr;
    int k = 0;

public:
    RandomizedSet()
    {
        srand(time(0));
    }

    bool insert(int val)
    {
        if (map.find(val) != map.end())
            return false;

        arr.push_back(val);
        map[val] = k;
        k++;

        return true;
    }

    bool remove(int val)
    {
        if (map.find(val) == map.end())
            return false;

        int idx = map[val];

        swap(arr[idx], arr[k - 1]);
        map[arr[idx]] = idx;
        k--;
        map.erase(val);
        arr.pop_back();

        return true;
    }

    int getRandom()
    {
        int idx = rand();

        idx %= k;

        return arr[idx];
    }
};