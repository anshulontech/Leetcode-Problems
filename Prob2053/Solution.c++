// Link To Problem:-
// https://leetcode.com/problems/kth-distinct-string-in-an-array/

// Solution:-

class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {
        unordered_map<string, int> map;

        for (auto x : arr)
            map[x]++;

        for (auto x : arr)
            if (map[x] == 1)
            {
                k--;
                if (k == 0)
                    return x;
            }

        return "";
    }
};