// Solution:-

class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int res = 0;

        traverse(root->left, res, true);
        traverse(root->right, res, false);

        return res;
    }

private:
    void traverse(TreeNode *root, int &res, bool isLeft)
    {
        if (root == NULL)
            return;

        if (isLeft && root->left == NULL && root->right == NULL)
            res += root->val;
        else
        {
            traverse(root->left, res, true);
            traverse(root->right, res, false);
        }
    }
};