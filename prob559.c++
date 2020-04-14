// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/submissions/

// Time Complexity:-O(N).
// Space Compleity:-O(1).
    
// Approach:-
//     The approach is same as that of to that of finding the depth of binary tree.We will start from the root node and 
// using check_depth function check the depth below it. If the node is a leaf node than we will upsate the depth if curr is 
// greater than max_depth till that point and on doing further same operations we can solve the problem. 

class Solution {
public:
    int maxDepth(Node* root) {
        int max_depth=0;
        int curr=0;
        
        check_depth(root,curr,max_depth);
        
        return max_depth;
    }
    
    void check_depth(Node * root,int & curr,int & max_depth)
    {
        if(root==NULL)
            return ;
        curr++;
        
        if(root->children.size()==0)
            max_depth=max(max_depth,curr);
        
        for(auto x: root->children)
            check_depth(x,curr,max_depth);
        
        curr--;
        return;
    }
};