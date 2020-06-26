// https://leetcode.com/problems/minimum-absolute-difference-in-bst/

// Time Complexity:-O(N*H).
// Space Coplexity:-O(N). For recurssion stack.
    
// Approach:-
//     In this what we are going to do is that for each node the pair which gives min difference occurs either with 
// rightmost node of left subtree or leftmost node of right subtree. So we will check for them and upadte the answer 
// as required.

class Solution
{
private:
    int res = INT_MAX;

public:
    int getMinimumDifference(TreeNode *root)
    {
        traverse(root);

        return res;
    }

    void traverse(TreeNode *root)
    {
        if (root == NULL)
            return;

        getMax(root);
        traverse(root->left);
        traverse(root->right);
    }

    void getMax(TreeNode *root)
    {
        if (root->right)
        {
            TreeNode *temp = root->right;

            while (temp->left)
                temp = temp->left;

            res = min(res, abs(temp->val - root->val));
        }

        if (root->left)
        {
            TreeNode *temp = root->left;

            while (temp->right)
                temp = temp->right;

            res = min(res, abs(root->val - temp->val));
        }
    }
};

// Another Approach is that we will make the inorder traversal of the tree and store the values in a vector and than 
// check from them that is suitable.


class Solution
{
public:
    int getMinimumDifference(TreeNode *root)
    {
        vector<int> res;

        inorder(root, res);

        int ans = INT_MAX;

        for (int i = 0; i < res.size() - 1; i++)
            ans = min(ans, res[i + 1] - res[i]);

        return ans;
    }

    void inorder(TreeNode *root, vector<int> &res)
    {
        if (root == NULL)
            return;

        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
};