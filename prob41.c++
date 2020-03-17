// https://leetcode.com/problems/first-missing-positive/

void swap(int *,int *);

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
            if(nums[i]<=0||nums[i]>nums.size())
            {
                nums.erase(nums.begin()+i);
                i--;
            }
        
        sort(nums.begin(),nums.end());
        
        int i,run=0;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]!=(i+1-run))
                return i+1-run;
            
            while(i<nums.size()-1&&nums[i]==nums[i+1])
                {
                    i++;
                    run++;
                }
        }
    
        
        return i+1-run;
    }
};

void swap(int *p,int *q)
{
    int temp=*p;
    *p=*q;
    *q=temp;
}