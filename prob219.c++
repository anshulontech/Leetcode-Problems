// https://leetcode.com/problems/contains-duplicate-ii/

// Time Complexity:-O(N)
// Space Complexity:-O(N).

// Approach:-
//     In an unordered_map we will store the index f the numbers and if any number having more than 1 indxes than e will check 
// that is their absolute difference is less than or equal to k or not.If it will be than we will return true otherwise go for 
// next one. If condition reains false for all times than we will return false as final answer. 

class Solution {
    typedef vector<int> pi;
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,pi> store;
        for(int i=0;i<nums.size();i++)
            store[nums[i]].push_back(i);
        
        for(auto x: store)
            for(int i=0;i<x.second.size()-1;i++)
                if(abs(x.second[i]-x.second[i+1])<=k)
                    return true;
        
        return false;
    }
};