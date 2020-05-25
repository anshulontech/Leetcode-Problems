// https://leetcode.com/problems/max-consecutive-ones-iii/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     In this we are making a window using start and end pointer . If the element At end index is 1 than we will just 
// increase the lenght of the window by 1 else if the encountered element is 0 and if we have k greater than 0 than also 
// we can increase our window length by increasing end pointer else if k is equal to zero than we will increase the start 
// pointer till k will not become greater than 0 and at each step we will update the value of result.

class Solution {
public:
    int longestOnes(vector<int>& A, int k) {
        int start=0,end=0,res=0;
        int n=A.size();
        while(end<n) {
            if(A[end]==1)
                end++;
            else
                if(k>0) {
                    end++;
                    k--;
                }
                else {
                    if(A[start]==0)
                        k++;
                    
                    start++;
                }
            
            res=max(res,end-start);
        }
        
        return res;
    }
};