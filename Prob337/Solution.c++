// Link To Problem:-
// https://leetcode.com/problems/house-robber-iii/description/

// METHOD 1:-

class Solution
{
public:
    int rob(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int val = 0;

        if (root->left)
            val += rob(root->left->left) + rob(root->left->right);

        if (root->right)
            val += rob(root->right->left) + rob(root->right->right);

        return max(val + root->val, rob(root->left) + rob(root->right));
    }
};

// METHOD 2:-

class Solution
{
private:
    unordered_map<TreeNode *, int> store;

public:
    int rob(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        if (store.find(root) != store.end())
            return store[root];

        int val = 0;
        if (root->left)
            val += rob(root->left->left) + rob(root->left->right);

        if (root->right)
            val += rob(root->right->left) + rob(root->right->right);

        val = max(val + root->val, rob(root->left) + rob(root->right));

        store.insert(make_pair(root, val));
        return val;
    }
};