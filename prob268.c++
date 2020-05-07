// https://leetcode.com/problems/missing-number/

// Method 1:-
// Time Complexity:-O(N).
// Space Compexity:-O(1).
    
// Approach:-
//     As we know that a^b^b =a hence we are going to use the same idea here. A nuber will be eleminated with the help of it's 
// index like for 3 we ahve let x at some atsge than 3^x63 gives x hence when it will traversed the whole list it will have 
// either 0 element as all only last element is not present or it will have the element which is not present and number of 
// elements so when we will again applying operator with total number of digit than it will give us that which number is missing .

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res=0,i=0;
        for(;i<nums.size();i++)
            res=res^i^nums[i];
        
        return res^i;
    }
};


// Method 2:-
// Time Complexity:-O(N).
// Space Compexity:-O(1).
    
// Approach:-
//     We will first calculate the total sum of elements in the list and than we will get the total sum of elements with len+1
// elements atrting from 0 and than the missing number is the difference between total and sum.
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        int len=nums.size();
        for(int i=0;i<len;i++)
            sum+=nums[i];
        
        int total=(len+1)*len/2;
        
        return total-sum;
        
    }
};