// https://leetcode.com/problems/diameter-of-binary-tree/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     To find the diametre of the tree with respect to node we requires two things i.e; max height of it's left subtree 
// and it's right subtree and the diameter of the tree with respect to that node is sub of both heights +1. So Using this 
// approach we are going to solve the problem and calculate the max height for both sides of each node and than compare this 
// with the previous diameter. If it will be greater than the previous one than than we will update it's value and in last 
// return that one.


class Solution {
public:
    
    int diameter=0;
    
    int diameterOfBinaryTree(TreeNode* root) {
        subheight(root);
        
        return diameter;
    }
    
    int subheight(TreeNode * root)
    {
        if(root==NULL)
            return 0;
        
        int left=subheight(root->left);
        int right=subheight(root->right);
        
        diameter=max(diameter,left+right);
        
        return max(left,right)+1;
    }
};