// https://leetcode.com/problems/binary-tree-postorder-traversal/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     Recurssive approach for post order traversal.

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;

        postOrder(root, res);

        return res;
    }

    void postOrder(TreeNode *root, vector<int> &res)
    {
        if (root == NULL)
            return;

        postOrder(root->left, res);
        postOrder(root->right, res);

        res.push_back(root->val);
    }
};