// https://leetcode.com/problems/maximum-sum-circular-subarray/

// Time Complexity:-O(N).
// Space Complexity:-O(1).

// Approach:-
//     In this what we are going to do is that use the concept of max contimues subarray sum problem in which what we 
// were doing that if the value of number is found to be greater than the previous max sum + value than we will start 
// the subarray from that one else continue the subarray. Similarly here we are doing the same for subarray in the 
// middle of the given array but what for the array having some part in start and some in last as it is circular than 
// in this what we are going to do is that we will remove the subaary which is present in the middle having minimum 
// sum among them possible and after removing that one from the whole it wil form a subbarray having maximum sum which 
// is circular.

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int total=0,curr_max=0,curr_min=0,max_sum=INT_MIN,min_sum=INT_MAX;
        
        for(int i=0;i<A.size();i++)
        {
            curr_max=max(curr_max+A[i],A[i]);
            max_sum=max(max_sum,curr_max);
            curr_min=min(curr_min+A[i],A[i]);
            min_sum=min(min_sum,curr_min);
            total+=A[i];
        }
        
        return max_sum > 0 ? max(max_sum,total-min_sum) : max_sum;
    }
};