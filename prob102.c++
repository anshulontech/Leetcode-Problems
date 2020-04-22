// https://leetcode.com/problems/binary-tree-level-order-traversal/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     Like preorder traversal we will traverse the tree generally and we are going to pass the depth of each node also as 
// argument so that we can add that value to respective vector/list. Now on each pass we will check using condition 1 that is 
// any element of that level exist or not. If it will than we will just simply push root-val to that vector else we will make 
// a new vector insize main vector and push the value. After this using recursion we will go for left and right sub tree.


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        leveltraversal(root,res,0);
        
        return res;
    }
    
    void leveltraversal(TreeNode * root,vector<vector<int>> & res,int depth)
    {
        if(root==NULL)
            return;
        
        if(depth>=res.size())  // Condition 1.
            res.push_back({root->val});
        else
            res[depth].push_back(root->val);
        
        leveltraversal(root->left,res,depth+1);
        leveltraversal(root->right,res,depth+1);
    }
};