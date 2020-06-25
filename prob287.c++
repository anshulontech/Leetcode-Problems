// https://leetcode.com/problems/find-the-duplicate-number/

// Time Complexity:-O(N*log(n)).
// Space Complexity:-O(1).

// Approach:-
//     In this we will first sort the array and than check for consecutive elements that is they are same or not if 
// hey will than we get our answer else we will move forward.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
            if(nums[i]==nums[i-1])
                return nums[i];
        
        return -1;
    }
};

// Time Complexity:-O(N).
// Space Complexity:-O(N).

// Approach:-
//     In this We are using a set to store the occured elements in the array. Now on encounter with new element if we 
// found it in set than it represents it occured already hence we got the answer else we will just insert that element
// to the set and check for next one.

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        unordered_set<int> store;

        for (int i = 0; i < nums.size(); i++)
            if (store.find(nums[i]) != store.end())
                return nums[i];
            else
                store.insert(nums[i]);

        return -1;
    }
};

// Time Complexity:-O(N).
// Space Complexity:-O(N).

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int fast = nums[0];
        int slow = nums[0];

        do
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (fast != slow);

        slow = nums[0];

        while (fast != slow)
        {
            fast = nums[fast];
            slow = nums[slow];
        }

        return fast;
    }
};