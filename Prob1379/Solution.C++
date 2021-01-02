// Link To Problem :-
// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

// Solution:-

class Solution
{
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        if (original == NULL)
            return NULL;

        if (target == original)
            return cloned;

        TreeNode *res = NULL;
        res = getTargetCopy(original->left, cloned->left, target);

        if (res == NULL)
            res = getTargetCopy(original->right, cloned->right, target);

        return res;
    }
};