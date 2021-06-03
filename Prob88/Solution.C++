// Link To Problem:-
// https://leetcode.com/problems/merge-sorted-array/

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int first = m - 1, second = n - 1;
        int last = m + n - 1;

        while (first >= 0 && second >= 0)
        {
            if (nums1[first] > nums2[second])
            {
                swap(nums1[first], nums1[last]);
                first--;
                last--;
            }
            else
            {
                swap(nums2[second], nums1[last]);
                second--;
                last--;
            }
        }

        if (first < 0)
        {
            while (second >= 0)
            {
                swap(nums2[second], nums1[last]);
                second--;
                last--;
            }
        }
    }
};