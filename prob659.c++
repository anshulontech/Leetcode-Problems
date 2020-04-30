// https://leetcode.com/problems/split-array-into-consecutive-subsequences/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     In ceateNewSequence we will store the count of each number in nums. In the another map named existingSequence we will 
// use to store the number which can be stored in future to a pre existing sequence, if the count of number is greater than 0 
// in this map than it represents that this number can be added as a part of existing sequence. Now on the traversing the array 
// again we will first check that is the number is available to staart or join sequence. If it will than we will check that is 
// number can be formed as a part or any preexisting sequence or not. If it will than we will add that number to that sequence 
// and add the next consequtive number to the existingSqeuence map for future. If it will not be a part of existing Sequence 
// that we will start a new sequence from that one hence check next two consecutive numbers occurs in the array not if they 
// will than we will make a new sequence and as usual add the third consecutive to existingSequence map and if net 2 consecutive 
// numbers are not present than we return false. if the cursor reaches end that it represents that we can split it into 1 or 
// more subsequences hence return true in that situation.

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> createNewSequence;
        unordered_map<int,int> existingSequence;
        
        for(int i=0;i<nums.size();i++)
            createNewSequence[nums[i]]++;
        
        for(int i=0;i<nums.size();i++)
        {
            if(createNewSequence[nums[i]]==0)
                continue;
            if(existingSequence[nums[i]]>0)
            {
                existingSequence[nums[i]]--;
                existingSequence[nums[i]+1]++;
                createNewSequence[nums[i]]--;
            }
            else
                if(createNewSequence[nums[i]]>0 && createNewSequence[nums[i]+1]>0 && createNewSequence[nums[i]+2] >0)
                {
                    createNewSequence[nums[i]]--;
                    createNewSequence[nums[i]+1]--;
                    createNewSequence[nums[i]+2]--;
                    existingSequence[nums[i]+3]++;
                    
                }
                else
                    return false;
        }
        
        return true;
        
    }
};