// https://leetcode.com/problems/subtree-of-another-tree/

// Time Compleity:-O(M*N).
// Space Complexity:-O(M*N) - Just For recurssion stack.
    
// Approach:-
//     We will check for the both the trees that if their current root val are same than we will call a function 
// sameTree which will tell us that is the trees are same or not or if their root values are not same than we will 
// compare t tree will childs of s and so on till we will not traverse the whole tree.

class Solution
{
public:
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (s == NULL && t == NULL)
            return true;
        else if (s == NULL || t == NULL)
            return false;

        if (s->val == t->val)
            if (sameTree(s, t))
                return true;

        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }

    bool sameTree(TreeNode *s, TreeNode *t)
    {
        if (s == NULL && t == NULL)
            return true;
        else if (s == NULL || t == NULL)
            return false;

        if (s->val != t->val)
            return false;
        else
            return sameTree(s->left, t->left) && sameTree(s->right, t->right);
    }
};