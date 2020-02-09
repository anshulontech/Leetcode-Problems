// https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i;
        
        sort(nums.begin(),nums.end());
        for(i=1;i<nums.size();i=i+2)
            if(nums[i-1]!=nums[i])
                return nums[i-1];
        
        if(i=nums.size())
            return nums[i-1];
        
        return 0;
    }
};