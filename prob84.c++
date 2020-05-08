// https://leetcode.com/problems/largest-rectangle-in-histogram/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     We will use a stack to store the index of the bars. If the value of bar i found to be greater than the stack's top bar's 
// value than it represents that the top of stack bar can spread it's areqa in next bar but uf it was not we have to check fot 
// top bar that till left where it can increase it's area . This can be done using the next top element of the stack . than using 
// this we can calculate the max area which is required
    
    
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> store;
        int res=0;
        
        for(int i=0;i<heights.size();i++)
        {
            while(!store.empty() && heights[store.top()]>heights[i])
            {
                int h=heights[store.top()];
                store.pop();
                int l=store.empty() ? -1 : store.top();
                
                res=max(res,(i-l-1)*h);
            }
            
            store.push(i);
        }
        
        return res;
    }
};