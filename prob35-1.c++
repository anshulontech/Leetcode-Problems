// https://leetcode.com/problems/search-insert-position/


int binarysearch(vector<int>& ,int ,int , int );
    
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        return binarysearch(nums,0,nums.size()-1,target);
    }
};

int binarysearch(vector<int>& nums,int start,int end, int target)
{
    if(start>end)
    {
        return end+1;
    }
    
    int mid=start+(end-start)/2;
    
    if(nums[mid]==target)
        return mid;
    else
        if(nums[mid]>target)
            return binarysearch(nums,start,mid-1,target);
        else
            return binarysearch(nums,mid+1,end,target);
    
    return -1;
}