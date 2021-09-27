// Link To Problem:-
// https://leetcode.com/problems/find-original-array-from-doubled-array/

// Solution:-

class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        unordered_map<int, int> map;

        for (auto x : changed)
            map[x]++;

        vector<int> res;
        sort(changed.begin(), changed.end());

        for (auto x : changed)
        {
            if (map[x] == 0)
                continue;

            map[x]--;

            if (map[2 * x] != 0)
            {
                map[2 * x]--;
                res.push_back(x);
            }
            else
                return {};
        }

        return res;
    }
};