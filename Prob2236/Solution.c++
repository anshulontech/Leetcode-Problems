// Link To The Problem:-
// https://leetcode.com/problems/root-equals-sum-of-children/

// Solution:-

class Solution
{
public:
    bool checkTree(TreeNode *root)
    {
        return !(root->val - root->left->val - root->right->val);
    }
};