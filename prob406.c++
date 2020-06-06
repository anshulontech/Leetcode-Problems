// https://leetcode.com/problems/queue-reconstruction-by-height/

// Time Complexity:-O(N*log(N)).
// Space Complexity:-O(N).
    
// Approach:-
//     In this what we are going to do is that we will first sort the elements in the decreasing order and elements 
// having same heigt are sorted in ascending order. Now we will start to place the elements in the new order with 
// the condition that the current element is inserted at index equal to current element's second value +1 . So by 
// doing this we can generate the whole result.
        
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& A) {
        vector<vector<int>> res;
        
        sort(A.begin(),A.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[0]>b[0] || (a[0]==b[0] && a[1]<b[1]));
        });
        
        for(vector<int>& x : A) 
            res.insert(res.begin()+x[1],x);
        
        return res;
    }
};