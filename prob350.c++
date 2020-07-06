// https://leetcode.com/problems/intersection-of-two-arrays-ii/description/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     In this we aill store the count of each num in nums1 in a map and than traverse the nums and if any num there 
// having non zero count in map than we will initially push it to the result vector and than we will decrease it's 
// count by 1 and move forward.

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> store;
        
        for(int i=0;i<nums1.size();i++)
            store[nums1[i]]++;
        
        vector<int> res;
        
        for(int i=0;i<nums2.size();i++)
            if(store[nums2[i]]!=0) {
                store[nums2[i]]--;
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