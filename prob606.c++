// https://leetcode.com/problems/construct-string-from-binary-tree/

// Time Complexity:-O(N).
// Space Comlexity:-O(N). To store the result.

// Approach:-
//     We will use preorder traversal of the tree and on oging to necxt depth we will first add '(' to string and 
// when we will come back from there to that node we will add ')' to string as a mark that this a subtree also on 
// encounter with node we will addd it's value to the string and go for it's child node. If a node has no left child 
// node but has right child than in this case before going to right child we will first add "()" to the string 
// representing that the tree has NULL left subtree but has right subtree.

class Solution
{
private:
    string res = "";

public:
    string tree2str(TreeNode *root)
    {
        if (root == NULL)
            return res;
        res += to_string(root->val);

        if (root->left == NULL && root->right != NULL)
            res += "()";
        else
            preorder(root->left);
        preorder(root->right);
        return res;
    }

    void preorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        res += '(';
        res += to_string(root->val);
        if (root->left == NULL && root->right != NULL)
            res += "()";
        else
            preorder(root->left);
        preorder(root->right);

        res += ')';
    }
};