// https://leetcode.com/problems/invert-binary-tree/

// Time Complexity:-O(N).
// Space Complexity:-O(N).

// Approach:-
//     In this what we are doing is that we will interchange right subtree with left subtree and do it recursively 
// for both right and left subtree.

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
            return NULL;

        TreeNode *right = invertTree(root->right);
        TreeNode *left = invertTree(root->left);
        root->left = right;
        root->right = left;

        return root;
    }
};