// https://leetcode.com/problems/two-sum/ 

// Time Complexity:-O(N^2).
// Space Complexity:-O(1).

// Approach:-
//     We will use brute force approach here to check for each element that is any element is found their to make the 
// sum equal to target.

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> temp;
        for(int i=0;i<nums.size()-1;i++)
            for(int j=i+1;j<nums.size();j++)
                if((nums[i]+nums[j])==target)
                {
                 temp.push_back(i);   
                 temp.push_back(j);
                 return temp;
                }
        
        
        return temp;
    }
};

// Time Complexity:-O(N).
// Space Complexity:-O(N).

// Approach:-
//     Here we are doing the same but here what we are trying to do is that we are not itterating the vector again 
// to find element , we are just checking for targert-nums[i] in the map that is it present their or not, if it was
// than we will return the index of the set of values otherwise add the current one to map and go for next one.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> store;
        
        unordered_map<int,int> indexes;
        
        for(int i=0;i<nums.size();i++)
            if(indexes.find(target-nums[i])!=indexes.end())
                return {indexes[target-nums[i]],i};
            else
                indexes.insert(make_pair(nums[i],i));
        
        return store;
    }
};