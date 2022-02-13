// Link To Problem:-
// https://leetcode.com/problems/partition-array-according-to-given-pivot/

// Solution:-

class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        int less = 0, equal = 0, more = 0;

        for (auto x : nums)
            if (x < pivot)
                less++;
            else if (x == pivot)
                equal++;
            else
                more++;

        int n = less + equal + more;

        vector<int> res(n);

        int i = 0, j = less, k = less + equal;

        for (auto x : nums)
            if (x < pivot)
                res[i++] = x;
            else if (x == pivot)
                res[j++] = x;
            else
                res[k++] = x;

        return res;
    }
};