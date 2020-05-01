// https://leetcode.com/problems/trim-a-binary-search-tree/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     If a node is not satisfing the condition of L and R than according to that condition we will call for the child subtree 
// which will be suitable for that> if the value is more than R than right tree would no longer be part hence we will go for 
// left one and vice versa for value less than L. If both conditions are false than we will go for both child trees and a last 
// return that node.

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int & L, int & R) {
        if(root==NULL)
            return nullptr;
        if(root->val>R)
            return trimBST(root->left,L,R);
        if(root->val<L)
            return trimBST(root->right,L,R);
        
        root->left=trimBST(root->left,L,R);
        root->right=trimBST(root->right,L,R);
        
        return root;
    }
};