// https://leetcode.com/problems/maximum-width-ramp/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     Initially we will make a decreasing stack using condition 1 auch that stack contains elements in decreasing order. 
// Now On itterating the vector from right if the value of A[i] is greater the A[store.top()] than we will update the length 
// of ramp represented by res. While condition 2 is correct we will continue otherise break the loop.

class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        stack<int> store;
        int res=0;
        
        for(int i=0;i<A.size();i++)
            if(store.empty() || A[store.top()]>A[i])  //condition 1.
                store.push(i);
        
        for(int i=A.size()-1;i>res;i--)
            while(!store.empty() && A[store.top()]<=A[i])  //condition 2.
            {
                res=max(res,i-store.top());
                store.pop();
            }
        
        return res;
    }
};