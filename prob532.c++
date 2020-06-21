// https://leetcode.com/problems/k-diff-pairs-in-an-array/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     In this what we are going to do is that we will use one hash map to store the numbers which occureded and one 
// hash set to store the starting number which forms a pair. Now we will start to itterate the vector and if found 
// nums[i]-k or nums[i]+k than we will insert the lesser number to set representng that pair fomed by this number 
// as lesser has ocuured already and we will move on , in last the set represents all lesser elements from whom this 
// type of pair can form.

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k<0)
            return 0;
        
        unordered_set<int> starters;
        unordered_map<int,int> indices;
        
        for(int i=0;i<nums.size();i++) {
            
            if(indices.count(nums[i]-k))
                starters.insert(nums[i]-k);
            
            if(indices.count(nums[i]+k))
                starters.insert(nums[i]);
            
            indices[nums[i]]++;
        }
        
        return starters.size();
    }
};