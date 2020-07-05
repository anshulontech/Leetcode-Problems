// https://leetcode.com/problems/house-robber-iii/description/

// Time Complexity:-O(N^2).
// Space Compleixty:-O(N^2). For recurssion stack.
    
// Approach:- ( This Approach gives time limit exceed for only 1 case that is on leetcode it passes 123/124 test cases)
//     In this what we are going to do is that we will check that is there more profit in including this house or not, 
// so for this we will run two loops first to include the current node and the other to exclude it and than we will 
// return the maximum of them . By doing the current node we will check it for the eft and right subtrees and so on.

class Solution
{
public:
    int rob(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int val = 0;

        if (root->left)
            val += rob(root->left->left) + rob(root->left->right);

        if (root->right)
            val += rob(root->right->left) + rob(root->right->right);

        return max(val + root->val, rob(root->left) + rob(root->right));
    }
};

// Time Complexity:-O(N).
// Space Compleixty:-O(N).

// Approach:-
//     In this approach we are doing the same thing but here what we are going to do is that for each node we will 
// store the max result for it subtree in a map so that if we want the value for this subtree than we have no need 
// to traverse it again.

class Solution
{
private:
    unordered_map<TreeNode *, int> store;

public:
    int rob(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        if (store.find(root) != store.end())
            return store[root];

        int val = 0;
        if (root->left)
            val += rob(root->left->left) + rob(root->left->right);

        if (root->right)
            val += rob(root->right->left) + rob(root->right->right);

        val = max(val + root->val, rob(root->left) + rob(root->right));

        store.insert(make_pair(root, val));
        return val;
    }
};