// Link To Problem:-
// https://leetcode.com/problems/symmetric-tree/

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