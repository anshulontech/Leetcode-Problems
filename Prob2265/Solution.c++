// Link To The Problem:-
// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/

// Solution:-

class Solution
{
public:
    int averageOfSubtree(TreeNode *root)
    {
        int res = 0;

        vector<int> temp = dfs(root, res);

        return res;
    }

    vector<int> dfs(TreeNode *root, int &res)
    {
        int leftSum = 0, rightSum = 0, leftCount = 0, rightCount = 0;

        if (root == NULL)
            return {0, 0};

        vector<int> temp = dfs(root->left, res);

        leftSum = temp[0];
        leftCount = temp[1];

        temp = dfs(root->right, res);

        rightSum = temp[0];
        rightCount = temp[1];

        if ((leftSum + rightSum + root->val) / (leftCount + rightCount + 1) == root->val)
            res++;

        return {leftSum + rightSum + root->val, leftCount + rightCount + 1};
    }
};