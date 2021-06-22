// Link To Problem :-
// https://leetcode.com/problems/path-sum-ii/

// METHOD 1:-

class Solution
{
private:
    vector<vector<int>> res;
    int ans;

public:
    vector<vector<int>> pathSum(TreeNode *root, int target)
    {
        int sum = 0;
        ans = target;
        vector<int> help;
        helper(root, sum, help);
        return res;
    }

    void helper(TreeNode *root, int sum, vector<int> &help)
    {
        if (root == NULL)
            return;
        sum += root->val;
        help.push_back(root->val);

        if (sum == ans && root->left == NULL && root->right == NULL)
        {
            res.push_back(help);
            help.pop_back();
            return;
        }

        helper(root->left, sum, help);
        helper(root->right, sum, help);

        help.pop_back();
    }
};