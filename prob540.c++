// https://leetcode.com/problems/single-element-in-a-sorted-array/

// Time Complexity:-O(N).
// Space Complexity:-O(1).

// Approach:-
//     We will traverse the vector from starting and find the number which not occurs twice.In this we will move
// itterator twice forward so that a number can be checked only ones.


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i;
        for(i=0;i<nums.size()-1;i+=2)
            if(nums[i]!=nums[i+1])
                return nums[i];
        
        return nums[nums.size()-1];
    }
};

// Time Complexity:-O(log(N)).
// Space Complexity:-O(1).

// Approach:-
//     In this we are going to use binary search in which we will first make mid representing poisition with odd place 
// now if the single number is in left than the mid and mid +1 element will not be same hence we will go to left otherwise 
// we will go to right. At the end of the loop start represents the singlr number. 
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int start = 0, end = nums.size() - 1;

        while (start < end)
        {
            int mid = start + (end - start) / 2;

            if (mid % 2 == 1)
                mid--;

            if (nums[mid] != nums[mid + 1])
                end = mid;
            else
                start = mid + 2;
        }

        return nums[start];
    }
};