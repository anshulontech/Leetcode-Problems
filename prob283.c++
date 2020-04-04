// https://leetcode.com/problems/move-zeroes/

// Time Complexity:-O(N).
// Space Complexity:-O(1).

// Approach:-
// We will define two variables named i and j and assign them with value 0. Now on iterating the loop we will check that
// is the value of nums[i] is equal to 0 or not . If the value of nums[i] is equal to 0 than we just increase the value of 
// i otherwise we will swap nums[i] and nums[j] and increase the value of j.This results in the shifting of all 0 in the 
// last without changing the order of the other elements in the list.



void swap(int  *,int* );

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();i++)
            if(nums[i]!=0)
            {
                swap(&nums[i],&nums[j]);
                j++;
            }
        return ;
    }
};

void swap(int  *p,int* q)
{
    int temp=*p;
    *p=*q;
    *q=temp;
}