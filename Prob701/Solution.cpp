// Approach 1:-

class Solution
{
private:
    TreeNode *prev = NULL;
    bool isDone = false;

public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        prev = NULL;
        TreeNode *node = new TreeNode(val);

        if (root == NULL)
            return node;
        helper(root, val);

        if (prev->val > val)
            prev->left = node;
        else
            prev->right = node;

        return root;
    }

    void helper(TreeNode *root, int &val)
    {
        if (!isDone && root->val > val)
            if (root->left != NULL)
                helper(root->left, val);
            else
            {
                prev = root;
                isDone = true;
            }
        else if (!isDone)
            if (root->right != NULL)
                helper(root->right, val);
            else
            {
                prev = root;
                isDone = true;
            }
    }
};