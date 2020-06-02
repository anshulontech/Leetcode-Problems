// https://leetcode.com/problems/same-tree/

// Time Complexity:-O(N).
// Space Complexity:-o(N). For recursion stack.
    
// Approach:-
//     we will check at each step that is roots value are equla or not. If they were not than we will return false 
// else we will check for their child node and for both trees the passing of arguments are same so that it will return 
// true if they both are same else their traversal is different and hence will return false.

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {

        if (p == NULL && q == NULL)
            return true;

        if (q == NULL || p == NULL)
            return false;

        if (p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};