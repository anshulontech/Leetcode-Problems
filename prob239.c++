// https://leetcode.com/problems/sliding-window-maximum/submissions/

// Time Complexity:-O(N).
// Space Complexity:-O(K).
    
// Approach:-
//     Deque is a special type of mixture of both queue and stack. So to solve this question we are going to use this one. 
// Initailly we make a deque and than start traverse the nums vector. Now if deque is not empty and have element more than k 
// than we will remove the front of the deque as this will not be longer our member of the window. ## Basic thing to note is 
// that in the deque we are not going to put the values  but we are going to store the index so that the length of window can 
// be estimated ##. Now after making window size equal to k we will find that if the vaue of nums[i] is greater then 
// nums[temp.back()] if yes than we will remove the elements from the back till the last element is not greater than nums[i]. 
// Here last element means number corresponding to that last value as index in vector nums. Now after that the last element is 
// inserted the elments present before that one in deque are greater than that one for a particular window and hence the at the 
// front represents the maximum element to the index hence we will add that number to the res vector and in last return that one.


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> temp;
        vector<int> res;
        
        for(int i=0;i<nums.size();i++)
        {
            if(!temp.empty()&&temp.front()==i-k)
                temp.pop_front();
            
            while(!temp.empty()&&nums[temp.back()]<nums[i])
                temp.pop_back();
            
            temp.push_back(i);
            
            if(i>=k-1)
                res.push_back(nums[temp.front()]);
        }
        
        return res;
    }
};
