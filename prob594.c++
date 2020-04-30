// https://leetcode.com/problems/longest-harmonious-subsequence/

// Time Complexity;-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     We will count the occurance of each number in a map. Now we will iterate the map and check that is x.first-1 exist or 
// not if it will than we will check that is sum of their count is greater than res or not if it will than they can form the 
// required subsequence hence we willupdate the value of res otherwise go for next one.

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res=0;
        unordered_map<int,int> count;
        for(int i=0;i<nums.size();i++)
            count[nums[i]]++;
        
        for(auto x : count)
            if(count.find(x.first-1)!=count.end())
                res=max(res,x.second+count[x.first-1]);
        
        return res;
        
    }
};

// In this Approach All Working can be Ddone in a single loop:-

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res=0;
        unordered_map<int,int> count;
        for(int i=0;i<nums.size();i++)
        {
            count[nums[i]]++;
            if(count.find(nums[i]-1)!=count.end())
                res=max(res,count[nums[i]]+count[nums[i]-1]);
            if(count.find(nums[i]+1)!=count.end())
                res=max(res,count[nums[i]]+count[nums[i]+1]);
        }
        return res;
        
    }
};