// Link To Problem:-
// https://leetcode.com/problems/diameter-of-binary-tree/

// METHOD 1:-

class Solution
{
public:
    int diameter = 0;

    int diameterOfBinaryTree(TreeNode *root)
    {
        subheight(root);

        return diameter;
    }

    int subheight(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int left = subheight(root->left);
        int right = subheight(root->right);

        diameter = max(diameter, left + right);

        return max(left, right) + 1;
    }
};