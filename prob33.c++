// https://leetcode.com/problems/search-in-rotated-sorted-array/

int binarysearch(vector<int> ,int ,int ,int );

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarysearch(nums,0,nums.size()-1,target);
    }
};

int binarysearch(vector<int> nums,int start,int end,int target)
{
    if(start>end)
        return -1;
    if(nums[0]==target)
            return 0;
    
    int mid=start+(end-start)/2;
    
    if(nums[mid]==target)
        return mid;
    else
        if(nums[0]>nums[mid]&&target<nums[mid])
            return binarysearch(nums,start,mid-1,target);
        else
            if(nums[0]>nums[mid]&&target>nums[mid]&&target<nums[0])
                return binarysearch(nums,mid+1,end,target);
            else
                if(nums[0]>nums[mid]&&target>nums[mid]&&target>nums[0])
                    return binarysearch(nums,start,mid-1,target);
                else
                    if(nums[0]<nums[mid]&&target>nums[mid])
                        return binarysearch(nums,mid+1,end,target);
                    else
                        if(nums[0]<nums[mid]&&target>nums[0]&&target<nums[mid])
                            return binarysearch(nums,start,mid-1,target);
                        else
                            return binarysearch(nums,mid+1,end,target);
    
}