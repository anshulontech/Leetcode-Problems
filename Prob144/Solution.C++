// Link To Problem:-
// https://leetcode.com/problems/binary-tree-preorder-traversal/

// METHOD 1:-

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;

        preorder(root, res);

        return res;
    }

    void preorder(TreeNode *root, vector<int> &res)
    {
        if (root == NULL)
            return;

        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }
};

// METHOD 2:-

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;

        stack<TreeNode *> store;

        if (root)
            store.push(root);

        while (!store.empty())
        {
            TreeNode *temp = store.top();
            store.pop();

            while (temp != NULL)
            {
                res.push_back(temp->val);
                if (temp->right)
                    store.push(temp->right);

                temp = temp->left;
            }
        }

        return res;
    }
};

// METHOD 3:-

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;

        while (root)
            if (root->left)
            {
                TreeNode *temp = root->left;
                while (temp->right != NULL && temp->right != root)
                    temp = temp->right;

                if (temp->right == NULL)
                {
                    res.push_back(root->val);
                    temp->right = root;
                    root = root->left;
                }
                else
                {
                    temp->right = NULL;
                    root = root->right;
                }
            }
            else
            {
                res.push_back(root->val);
                root = root->right;
            }
        return res;
    }
};