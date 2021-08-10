// Link To Problem:-
// https://leetcode.com/problems/path-sum-iii/

// METHOD 1:-

class Solution
{
public:
    int pathSum(TreeNode *root, int sum)
    {
        unordered_map<int, int> A;
        return helper(root, sum, A, 0);
    }

    int helper(TreeNode *root, int sum, unordered_map<int, int> &A, int prefixsum)
    {
        if (root == NULL)
            return 0;
        root->val += prefixsum;
        int res = (root->val == sum) + (A.count(root->val - sum) ? A[root->val - sum] : 0);
        A[root->val]++;

        res += helper(root->left, sum, A, root->val) + helper(root->right, sum, A, root->val);
        A[root->val]--;
        return res;
    }
};

// METHOD 2:-

class Solution
{
public:
    int pathSum(TreeNode *root, int sum)
    {
        if (root == NULL)
            return 0;

        return helper(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int helper(TreeNode *&root, int prefixsum, int target)
    {
        if (root == NULL)
            return 0;

        prefixsum += root->val;

        return (prefixsum == target) + helper(root->left, prefixsum, target) + helper(root->right, prefixsum, target);
    }
};
