// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

// Time Complexity:-O(N).
// Space Complexity:-O(N). Just For Recurssion stack.

// Approach:-
//     In this what we are going to do is that we will do in order traversal but in reverse order that first right
// than mid than left . When we are going from right to mid we will update the sum with root->val as it represents
// that the sum contains the sum of all the elements greater than mid and hence we can add that to mid root and
// generate greater bst by upadting all nodes.


class Solution
{
public:
    TreeNode *bstToGst(TreeNode *root)
    {
        int sum = 0;

        postOrder(root, sum);

        return root;
    }

    void postOrder(TreeNode *root, int &sum)
    {
        if (root == NULL)
            return;

        postOrder(root->right, sum);
        sum += root->val;
        root->val = sum;
        postOrder(root->left, sum);
    }
};