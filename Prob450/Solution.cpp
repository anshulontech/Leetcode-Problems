// Approach 1 :-

class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
            return NULL;
        if (root->val == key)
        {
            return set_tree(root);
        }

        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);

        return root;
    }

    TreeNode *set_tree(TreeNode *root)
    {
        if (root->right)
        {
            TreeNode *head = root->right;
            TreeNode *temp = head;

            while (temp->left)
                temp = temp->left;

            temp->left = root->left;

            return head;
        }
        else
            return root->left;
    }
};