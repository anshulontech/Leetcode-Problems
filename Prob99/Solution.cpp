// Approach 1:-

class Solution
{
private:
    vector<TreeNode *> inorder;

public:
    void recoverTree(TreeNode *root)
    {
        traversal(root);

        int first = -1, second = -1;

        for (int i = 0; i < inorder.size() - 1; i++)
            if (inorder[i]->val > inorder[i + 1]->val)
                if (first == -1)
                    first = i;
                else
                {
                    second = i + 1;
                    break;
                }

        if (second == -1)
            swap(inorder[first]->val, inorder[first + 1]->val);
        else
            swap(inorder[first]->val, inorder[second]->val);

        return;
    }

    void traversal(TreeNode *root)
    {
        if (root == NULL)
            return;

        traversal(root->left);
        inorder.push_back(root);
        traversal(root->right);
    }
};
// Approach 2:-

class Solution
{
private:
    TreeNode *first = NULL;
    TreeNode *second = NULL;
    TreeNode *prevElement = new TreeNode(INT_MIN);

public:
    void recoverTree(TreeNode *root)
    {
        traverse(root);

        swap(first->val, second->val);
    }

private:
    void traverse(TreeNode *root)
    {
        if (root == NULL)
            return;

        traverse(root->left);

        if (first == NULL && prevElement->val > root->val)
            first = prevElement;

        if (first != NULL && prevElement->val > root->val)
            second = root;

        prevElement = root;

        traverse(root->right);
    }
};