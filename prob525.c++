// https://leetcode.com/problems/contiguous-array/submissions/

// Time Complexity:=O(N).
// Space Complexity:-O(N).
    
// Approach:-
    // Initially we will make an unordered map and store (0,-1) to it. The key represents sum in the map and value represents 
// the index of that sum in array. As we are traversing the array we update the sum and index to the map. Sum is updated by 
// the scheme that for zer it will decrease by 1 and for 1 it will increase. As the sum is zero represents the total nubet of 
// zeroes and 1 are equal in the same way equal amount of su represents equal number of 1 and 0 in the subarray.So using this 
// scheme we are updating the max_length variable by checkig that is the new difference between index is greater than previous 
// length or not.

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> store;
        store.insert(make_pair(0,-1));
        
        int count=0;
        int max_length=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                count--;
            else
                count++;
            
            if(store.find(count)!=store.end())
                max_length=max(max_length,i-store[count]);
            else
                store.insert(make_pair(count,i));
        }
        
        return max_length;
    }
};