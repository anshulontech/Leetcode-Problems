// https://leetcode.com/problems/third-maximum-number/

// Time Complexity:-O(N).   ---Actual time is N*log(3).
// Space Complexity:-O(1).  --- Requires 4 unit of extra space.

// Approach:-
//     in this we are using set of maximum size 3. As in a set elements are taversed into ascending order hence this will be 
// very useful for us and also their is a property of set that it does not contains duplicates elements hence it will be very 
// helpful. Now the step is that if set size becomes more than 3 i.e, 4 than we will remove top element as it is smallest among 
// those in set.In last if set has size equal to 3 than it represents that it contains at least 3 elements hence we will return 
// the first one in set as final answer otherwise return last one.

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> store;
        for(int i=0;i<nums.size();i++)
        {
            store.insert(nums[i]);
            if(store.size()>3)
                store.erase(store.begin());
        }
        
        return store.size()==3 ? *store.begin() : *store.rbegin();
    }
};