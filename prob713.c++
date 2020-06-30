// https://leetcode.com/problems/subarray-product-less-than-k/description/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     Use the concept of sliding window such that we will increase our window if the product of window element is 
// less than k else if product is greater than we will reduce the window and also on each operation we will upadte 
// the result that how manysubarry can be formed using this .

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(k<=1)
            return 0;
        int prod=1;
        
        int start=0,res=0;
        
        for(int end=0;end<nums.size();end++) {
            prod*=nums[end];
            
            while(prod>=k)
                prod/=nums[start++];
            
            res+=(end-start+1);
        }
        
        return res;
    }
};