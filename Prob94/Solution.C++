// Link To Problem:-
// https://leetcode.com/problems/binary-tree-inorder-traversal/

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> store;
        inorder(root, store);
        return store;
    }

    void inorder(TreeNode *root, vector<int> &store)
    {
        if (root == NULL)
            return;

        inorder(root->left, store);
        store.push_back(root->val);
        inorder(root->right, store);
    }
};

// METHOD 2:-

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;

        stack<TreeNode *> temp;

        TreeNode *curr = root;

        while (curr != NULL || !temp.empty())
        {
            while (curr != NULL)
            {
                temp.push(curr);
                curr = curr->left;
            }

            curr = temp.top();
            temp.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }

        return res;
    }
};

// METHOD 3:-

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;

        TreeNode *curr = root;
        while (curr)
        {
            if (curr->left == NULL)
            {
                res.push_back(curr->val);
                curr = curr->right;
                continue;
            }

            TreeNode *pre = curr->left;
            while (pre->right != NULL && pre->right != curr)
                pre = pre->right;

            if (pre->right != NULL)
            {
                pre->right = NULL;
                res.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                pre->right = curr;
                curr = curr->left;
            }
        }

        return res;
    }
};