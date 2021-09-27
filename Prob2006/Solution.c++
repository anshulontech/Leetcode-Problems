// Link To Problem:-
// https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/

// Solution:-

class Solution
{
public:
    int countKDifference(vector<int> &nums, int k)
    {

        vector<int> map(201, 0);

        for (auto x : nums)
            map[x]++;

        int res = 0;

        for (int i = 1; i + k <= 200; i++)
        {
            int count1 = map[i];
            int count2 = map[i + k];

            res += (count1 * count2);
            // cout<<count1<<" "<<count2<<" "<<res<<endl;
        }

        return res;
    }
};