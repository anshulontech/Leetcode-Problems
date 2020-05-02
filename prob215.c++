// https://leetcode.com/problems/kth-largest-element-in-an-array/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     Quickselect algorithm:-
//         Accordign to this what we are going to do is to choose a pivot and trying to placre it to it's right poisition such 
//     that all elements lesser than pivot will be in left of pivot and greater than pivot will be towards right of the pivot. 
// Now if the pivot is at poisition size-k than it represents that the element is the kth largest element in the unsorted array.


class Solution {
private:
    int count;
public:
    int findKthLargest(vector<int>& nums, int k) {
        count=nums.size()-k;
        return quickselect(nums,0,nums.size()-1,k);
    }
    
    int quickselect(vector<int> & nums,int start,int end,int k)
    {
        int pivot=nums[end];
        
        int i=start,j=start;
        while(j<end)
            if(nums[j]<=pivot)
            {
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else
                j++;
        
        swap(nums[i],nums[end]);
        
        if(i==count)
            return nums[i];
        else
            if(i<count)
                return quickselect(nums,i+1,end,k);
            else
                return quickselect(nums,start,i-1,k);
            
    }
};