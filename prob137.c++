// https://leetcode.com/problems/single-number-ii/

// Time Complexity:-O(N*32).
// Space Complexity:-O(1).
    
// Approach:-
//     For each bit poisition we will calculate the numbers having 1 at that bit. Now taking it's modulo will give 
// that what is the it of that single nhumber at that bit so we can generate the numeber using that one.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        
        for(int i=0;i<32;i++) {
            int sum=0;
            for(int j=0;j<nums.size();j++)
                if((nums[j]>>i) & 1 == 1)
                    sum++;
            
            sum=sum%3;
            
            if(sum!=0)
                res |= sum << i;
            
        }
        
        return res;
    }
};