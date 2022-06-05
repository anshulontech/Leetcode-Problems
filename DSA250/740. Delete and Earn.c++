// Link To The Problem:-
//  https://leetcode.com/problems/delete-and-earn/

// Solution:-

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        map<int, int> map;

        for (auto x : nums)
        {
            map[x] += x;
        }

        int res = 0, f = 0, s = 0, prev = -1;

        for (auto x : map)
        {
            if (x.first == (prev + 1))
            {
                int temp = x.second + f;
                f = max(f, s);
                s = temp;
            }
            else
            {
                int temp = x.second + max(f, s);
                f = max(f, s);
                s = temp;
            }

            prev = x.first;
        }

        return max(f, s);
    }
};