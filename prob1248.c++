// https://leetcode.com/problems/count-number-of-nice-subarrays/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     Starting from the first index we will calculate the number of odd terms in the array and store count of number 
// of subsets starting from first element to a particlular poisition having that number of odd number in the map. Now 
// we will start to traverse the map and if the value it correspond is greater than or equal to k than we will go in 
// the loop . The loop will calculate the total number of combinations of subsets it can form eithrr by elemenating 
// another subset or by not(In case when val is equal to k) and store the number in a res variable.

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> store;
        
        int num=0;
        for(int i=0;i<nums.size();i++)
            if(nums[i]%2!=0)
                store[++num]++;
            else
                store[num]++;
        
        
        int res=0;
        for(auto x: store)
        {
            if(x.first<k)
                continue;
            
            if(x.first==k)
                res+=x.second;
            
            if(store.find(x.first-k)!=store.end())
                res+=x.second*store[x.first-k];
        }
        
        return res;
    }
};