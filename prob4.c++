// https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> A;
        int i=0,j=0;
        while(i<nums1.size()&&j<nums2.size())
            if(nums1[i]<=nums2[j])
            {
                A.push_back(nums1[i]);
                i++;
            }
            else
            {
                A.push_back(nums2[j]);
                j++;
            }
        
        if(i==nums1.size())
            while(j<nums2.size())
            {
                A.push_back(nums2[j]);
                j++;
            }
        
        if(j==nums2.size())
            while(i<nums1.size())
            {
                A.push_back(nums1[i]);
                i++;
            }
        int mid=A.size()/2;
        if(A.size()%2==0)
            return (double)(A[mid]+A[mid-1])/2;
        else
            return (double)A[mid];
        
    }
};