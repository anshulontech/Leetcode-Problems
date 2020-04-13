// https://leetcode.com/problems/bulb-switcher-iii/submissions/

// Time Compleity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     We will make two variables named sum and total, where sum store the sum of the indexes while total store the sum 
// of indexes of lighted bulb. Now if all the bulbs previous to particluar one are lighted than the value of sum and total 
// till that index will remain same and hence when the value of sum and total remains same we will increase the count which 
// represents how many times the all glown bulb remains bule .

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int count=0;
        int sum=0;
        int total=0;
        
        for(int i=0;i<light.size();i++)
        {
            sum+=i+1;
            total+=light[i];
            
            if(total==sum)
                count++;
        }
        
        return count;
    }
};