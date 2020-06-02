// https://leetcode.com/problems/merge-sorted-array/

// Time Complexity:-O(N+M).
// Space Complexity:-O(1).
    
// Approach:-
//     In this what we are going to do is that we are setting our pinters to the end of the vectors nums1(of length m) 
// and nums2 and another pointer to the end of the nums1 vector(of length m+n). Now the max value among these poiners 
// will be assigned to the last pointer and changing pointers will get one step back. So by doing this we can merge the 
// arrays so that they will be in increasing order.

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int first=m-1,second=n-1;
        int last=m+n-1;
        
        while(first>=0 && second>=0) {
            if(nums1[first]>nums2[second]) {
                swap(nums1[first],nums1[last]);
                first--;
                last--;
            }
            else {
                swap(nums2[second],nums1[last]);
                second--;
                last--;
            }
        }
        
        if(first<0) {
            while(second>=0) {
                swap(nums2[second],nums1[last]);
                second--;
                last--;
            }
        }
        
    }
};