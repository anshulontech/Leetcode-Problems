// https://leetcode.com/problems/intersection-of-two-arrays/description/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     Initially we will store the elements of nums1 in a set and than go for the nums2 and if found any integer in 
// nums2 that is in set than we will first remove that element from the set and than add that one to the result 
// vector and finally return the result vector.

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> store;

        for (int i = 0; i < nums1.size(); i++)
            store.insert(nums1[i]);

        vector<int> res;

        for (int i = 0; i < nums2.size(); i++)
            if (store.find(nums2[i]) != store.end())
            {
                store.erase(store.find(nums2[i]));
                res.push_back(nums2[i]);
            }

        return res;
    }
};

// Time Complexity:-O(log(N)).
// Space Complexity:-O(1).

// Approach:-
// First we will sort the array and than use two pointer concept to store the numbers which occures in both
// the vectors.

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
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
                while (i < nums1.size() && nums1[i] == val)
                    i++;
                while (j < nums2.size() && nums2[j] == val)
                    j++;
            }
            else if (nums1[i] > nums2[j])
                j++;
            else
                i++;
        }

        return res;
    }
};