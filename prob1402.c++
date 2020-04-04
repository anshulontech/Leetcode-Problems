// https://leetcode.com/problems/reducing-dishes/

// Time Complexity:-O(N^2).
// Space Complexity:-O(1).

// Approach:- 
// BRUTE FORCE APPROACH
// Initially we will sort the array and than from the first index will check the value of count and on next turn leaving 
// behind all the values which occurs before the previous one and also updating the value of max with the help of count.
// And at ;ast returns the value of max.

class Solution {
public:
    int maxSatisfaction(vector<int>& A) {
        
        sort(A.begin(),A.end());
        
        int max=INT_MIN;
        
        for(int i=0;i<A.size();i++)
        {
            int count=0;
            for(int j=i;j<A.size();j++)
                count+=(j-i+1)*A[j];
            
            if(count>max)
                max=count;
        }
        
        if(max<=0)
            return 0;
        else
            return max;
    }
};