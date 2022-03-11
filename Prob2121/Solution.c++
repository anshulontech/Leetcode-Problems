// Link To The Problem:-
// https://leetcode.com/problems/intervals-between-identical-elements/

// Solution:-

class Solution
{
public:
    vector<long long> getDistances(vector<int> &arr)
    {
        unordered_map<long long, vector<vector<long long>>> map;
        long long n = arr.size();

        for (long long i = 0; i < n; i++)
        {
            if (map.find(arr[i]) == map.end())
            {
                map[arr[i]].push_back({i, i});
            }
            else
            {
                auto &vec = map[arr[i]];
                vec.push_back({i, i + vec[vec.size() - 1][1]});
            }
        }

        vector<long long> res;

        for (long long i = 0; i < n; i++)
        {
            auto &vec = map[arr[i]];

            long long idx = lower_bound(vec.begin(), vec.end(), i, [](auto &vec, long long value)
                                        { return vec[0] < value; }) -
                            vec.begin();

            long long backSum = 0, forSum = 0;

            if (idx > 0)
            {
                backSum = (idx) * (i)-vec[idx - 1][1];
            }

            if (idx < vec.size() - 1)
            {
                forSum = vec[vec.size() - 1][1] - vec[idx][1] - (vec.size() - 1 - idx) * i;
            }

            res.push_back(backSum + forSum);
        }

        return res;
    }
};