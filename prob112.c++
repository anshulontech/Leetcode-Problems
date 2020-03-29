// https://leetcode.com/problems/path-sum/

// Time Complexity:-O(N).
// Space Complexity:-O(1).

// Approach:-
// Traversing all the nodes and getting sum till that node from the root and if sum is equal to target and node has no left
// and right child than return true.
// Approach is purely recursive.


inline bool helper(TreeNode * &,int ,int );

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return helper(root,sum,0);
    }
};

inline bool helper(TreeNode * &root,int sum,int presum)
{
    if(root==NULL)
        return false;
    
    if((root->val+presum)==sum&&root->left==NULL&&root->right==NULL)
        return true;
    
    return helper(root->left,sum,presum+root->val)||helper(root->right,sum,presum+root->val);
}