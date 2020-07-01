// https://leetcode.com/problems/minimum-size-subarray-sum/description/

// Time Complelxity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     Here we are going to use the concept of sliding window. We will increase the length of the window by extending 
// end till the sum of window elements will not become equal or greater than s , after this we will contract the window 
// till the sum will not become less than s and change the min length if this one is minimum.

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start=0,end=0,curr_sum=0,res=INT_MAX;
        
        while(end<nums.size()) {
            if(curr_sum<s)
                curr_sum+=nums[end++];
            else {
                res=min(res,end-start);
                curr_sum-=nums[start++];
            }
        }
        
        while(curr_sum>=s) {
            res=min(res,end-start);
            curr_sum-=nums[start++];
        }
        if(res==INT_MAX)
            return 0;
        else
            return res;
    }
};

// Time Complelxity:-O(N*log(N)).
// Space Complexity:-O(N).

// Approach:-
//     Here we are storing the prefix sum and than for each element we are seeking for the upper bound and upadte the 
// min length .

class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        vector<int> store;
        int sum = 0, len = INT_MAX;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            store.push_back(sum);
        }

        for (int i = store.size() - 1; i >= 0 && store[i] >= s; i--)
        {
            int j = upper_bound(store.begin(), store.end(), store[i] - s) - store.begin();
            len = min(len, i - j + 1);
        }

        return len == INT_MAX ? 0 : len;
    }
};