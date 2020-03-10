// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i=1;i<nums.size();i++)
        {
            int k=0;
            while(i<nums.size()&&nums[i-1]==nums[i])
            {
                i++;
                k++;
            }
            nums.erase(nums.begin()+i-k,nums.begin()+i);
            i=i-k;
        }
        
        return nums.size();
    }
};