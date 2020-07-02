// https://leetcode.com/problems/continuous-subarray-sum/description/

// Time Complexity:-O(N).
// Space Complexity:-O(K).
    
// Approach:-
//     We will iterate the vector and taking sum of all the previous elements ,now we will use a unordered map to 
// store the remainder at the index. Now let we are traversing and at any stage we found the already existing 
// remainder than it shows that at some steps back we encuntered a sum which is n*k time less than curent sum that 
// means fom that index to curr index the sum is multiple of k and depanding on the length we can return the answer 
// that is that can be formed or not.

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> store;
        
        store.insert(make_pair(0,-1));
        
        int sum=0;
        
        for(int i=0;i<nums.size();i++) {
            sum+=nums[i];
            
            if(k!=0)
                sum%=k;
            
            if(store.count(sum)) {
                if(i-store[sum]>1)
                    return true;
            }
            else
                store.insert(make_pair(sum,i));
        }
        
        return false;
    }
};