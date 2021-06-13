// Link To Problem:-
// https://leetcode.com/problems/binary-tree-level-order-traversal/

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;

        leveltraversal(root, res, 0);

        return res;
    }

    void leveltraversal(TreeNode *root, vector<vector<int>> &res, int depth)
    {
        if (root == NULL)
            return;

        if (depth >= res.size()) // Condition 1.
            res.push_back({root->val});
        else
            res[depth].push_back(root->val);

        leveltraversal(root->left, res, depth + 1);
        leveltraversal(root->right, res, depth + 1);
    }
};