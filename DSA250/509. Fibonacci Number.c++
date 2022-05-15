// Link To The Problem:-
//  https://leetcode.com/problems/fibonacci-number/

// Solution 1:-

class Solution
{
    unordered_map<int, int> map;
    int f = 0, s = 1, k = 2;

public:
    Solution()
    {
        map.insert({0, 0});
        map.insert({1, 1});
    }

    int fib(int n)
    {
        if (n < k)
            return map[n];

        while (k <= n)
        {
            map[k] = f + s;
            f = s;
            s = map[k];
            k++;
        }

        return map[n];
    }
};

// Solution 2:- For this Particular Problem;

class Solution
{
    vector<int> arr;
    int f = 0, s = 1, k = 2;

public:
    Solution()
    {
        arr.resize(31);
        arr[0] = 0;
        arr[1] = 1;
    }

    int fib(int n)
    {
        if (n < k)
            return arr[n];

        while (k <= n)
        {
            arr[k] = f + s;
            f = s;
            s = arr[k];
            k++;
        }

        return arr[n];
    }
};