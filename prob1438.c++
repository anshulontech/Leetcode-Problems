// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

// Method 1:

// Time Complexity:-O(N*Log(N)).
// Space Complexity:-O(N).
    
// Approach:-
//     Using multiset we are going to store the maximum and minimum value in a subaaray. A subarray will satisg=fy the given 
// condtion of abs diff if min and max satisfy. Now we are taking two pointers one is front(j in code) and the other one is 
// back(i in code). Now as front will move forward we will check the condition if it is true than we will move forward else if 
// it will be false than we move back aheaduntill condition becomes true .At each step we will check that is length will be 
// greater than the previous one or not . If it will than we will update it.

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> store;
        
        int i=0;
        int len=0;
        
        for(int j=0;j<nums.size();j++)
        {
            store.insert(nums[j]);
            while(!store.empty() && (*store.rbegin()-*store.begin())>limit)
            {
                store.erase(store.find(nums[i]));
                i++;
            }
            
            if(j-i+1>len)
                len=j-i+1;
        }
        
        return len;
        
    }
};