// https://leetcode.com/problems/symmetric-tree/

// Time Complexity:-O(N).
// Space Complexity:-O(N). For recurssion stack.
    
// Approach:-
//     We will check for subtrees that is left subtree will be mirror to right subtree or not and so on.

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        return helper(root->left, root->right);
    }

    bool helper(TreeNode *left, TreeNode *right)
    {
        if (left == NULL && right == NULL)
            return true;
        if (left == NULL || right == NULL)
            return false;

        return (left->val == right->val) && helper(left->left, right->right) && helper(left->right, right->left);
    }
};