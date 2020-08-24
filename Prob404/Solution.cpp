// Approach 1:-

class Solution
{
private:
    int sum = 0;

public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        traversal(root, false);

        return sum;
    }

    void traversal(TreeNode *root, bool isLeft)
    {
        if (root == NULL)
            return;

        if (isLeft && root->left == NULL && root->right == NULL)
        {
            sum += root->val;
            return;
        }

        traversal(root->left, true);
        traversal(root->right, false);
    }
};