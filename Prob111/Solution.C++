// Link To Problem:-
// https://leetcode.com/problems/minimum-depth-of-binary-tree/submissions/

// METHOD 1:-

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int min_depth = INT_MAX;
        int curr = 0;

        check_depth(root, curr, min_depth);

        return min_depth;
    }

    void check_depth(TreeNode *root, int &curr, int &min_depth)
    {
        if (root == NULL)
            return;
        curr++;
        if (root->left == NULL && root->right == NULL)
            min_depth = min(min_depth, curr);

        check_depth(root->left, curr, min_depth);
        check_depth(root->right, curr, min_depth);

        curr--;

        return;
    }
};