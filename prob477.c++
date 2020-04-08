// https://leetcode.com/problems/total-hamming-distance/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     Initially we will make two variabls named one and zero which will store the number of integers having 1 as their
// last bit and number of integers having 0 as their last bit. Now if number have 0 as it's last bit than definately sure
// that it is divisible by 2 hence by cheking that is number divisible by 2 we can store their count in the onr and zero 
// variables.After each loop to check the number of pairs the pairs will be formed only when both will having different 
// bits hence number of ways are one*zero, hence we will add these numbers to the res and the functuion of the count 
// variable in the loop is to check the count of zero numbers in the list and in the last when all members will be zero 
// than the condititon count==nums.size() becomes true and the result function will return res as the final answer.



class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        if(nums.size()<2)
            return 0;
        
        int res=0;
     
        while(1)
        {
            int count=0; 
            int zero=0,one=0;
            
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]==0)
                    count++;
                if(nums[i]%2==0)
                    zero++;
                else
                    one++;
                nums[i] = nums[i] >> 1;
            }
            
            res+=one*zero;
            
            if(count==nums.size())
                return res;
        }
        
        return 0;
    }
};