// Link To Problem:-
// https://leetcode.com/problems/validate-binary-search-tree/

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        vector<int> store;
        makearray(root, store);

        for (int i = 1; i < store.size(); i++)
            if (store[i] <= store[i - 1])
                return false;

        return true;
    }

    void makearray(TreeNode *root, vector<int> &store)
    {
        if (root == NULL)
            return;

        makearray(root->left, store);
        store.push_back(root->val);
        makearray(root->right, store);
    }
};