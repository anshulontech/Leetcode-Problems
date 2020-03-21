// https://leetcode.com/problems/3sum-closest/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3)
            return 0;
        sort(nums.begin(),nums.end());
        int mini=nums[0]+nums[1]+nums[nums.size()-1];
        for(int i=0;i<nums.size()-2;i++)
        {
            int start=i+1,end=nums.size()-1;
            while(start<end)
            {
                int val=nums[i]+nums[start]+nums[end];
                if(abs(mini-target)>abs(val-target))
                    mini=val;
                if(val<target)
                    start++;
                else
                    if(val>target)
                        end--;
                    else
                        return mini;
            }
        }
        return mini;
    }
};