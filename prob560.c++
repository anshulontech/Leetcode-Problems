// https://leetcode.com/problems/subarray-sum-equals-k/

// Time Complexity:-O(N).
// Space Complexity:-O(N).

// Approach:-
// Initially we make a unordered_map and initialize it with value(0,1).Now we will iterate the map and keep updating the 
// value of sum and also will check that is map contains value sum-k , if yes than we add A[sum-k] to res which represents 
// that by how much ways we can reach there and after checking this we will update the value of sum to the map with value
// (sum,1) and keep checking for next one. At last we return the value of res.


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res=0;
        
        unordered_map<int,int> A;
        A[0]++;
        
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(A.count(sum-k))
                res+=A[sum-k];
            A[sum]++;
        }
        
        return res;
    }
};