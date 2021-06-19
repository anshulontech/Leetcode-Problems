// Link To Problem:-
// https://leetcode.com/problems/balanced-binary-tree/

// METHOD 1:-

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
            return true;
        return abs(depth(root->left, 0) - depth(root->right, 0)) < 2 && isBalanced(root->left) && isBalanced(root->right);
    }

    int depth(TreeNode *root, int isdepth)
    {
        if (root == NULL)
            return isdepth;

        return max(depth(root->left, isdepth + 1), depth(root->right, isdepth + 1));
    }
};

// METHOD 2:-

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        return checkdepth(root) != -1;
    }

    int checkdepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int left = checkdepth(root->left);
        if (left == -1)
            return -1;
        int right = checkdepth(root->right);
        if (right == -1)
            return -1;

        if (abs(left - right) > 1)
            return -1;
        else
            return max(left, right) + 1;
    }
};