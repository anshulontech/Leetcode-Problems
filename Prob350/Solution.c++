// Link To Problem:-
// https://leetcode.com/problems/intersection-of-two-arrays-ii/description/

// METHOD 1:-

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> store;

        for (int i = 0; i < nums1.size(); i++)
            store[nums1[i]]++;

        vector<int> res;

        for (int i = 0; i < nums2.size(); i++)
            if (store[nums2[i]] != 0)
            {
                store[nums2[i]]--;
                res.push_back(nums2[i]);
            }

        return res;
    }
};

// METHOD 2:-

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;

        vector<int> res;

        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] == nums2[j])
            {
                res.push_back(nums1[i]);

                int val = nums1[i];
                i++, j++;
            }
            else if (nums1[i] > nums2[j])
                j++;
            else
                i++;
        }

        return res;
    }
};