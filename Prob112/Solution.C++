// Link To Problem:-
// https://leetcode.com/problems/path-sum/

// METHOD 1:-

inline bool helper(TreeNode *&, int, int);

class Solution
{
public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        return helper(root, sum, 0);
    }
};

inline bool helper(TreeNode *&root, int sum, int presum)
{
    if (root == NULL)
        return false;

    if ((root->val + presum) == sum && root->left == NULL && root->right == NULL)
        return true;

    return helper(root->left, sum, presum + root->val) || helper(root->right, sum, presum + root->val);
}