// Link To Problem:-
// https://leetcode.com/problems/sum-root-to-leaf-numbers/

// METHOD 1:-

class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        string s = "";
        int res = 0;

        preorder(root, s, res);

        return res;
    }

    void preorder(TreeNode *root, string &s, int &res)
    {
        if (root == NULL)
            return;

        s += to_string(root->val);

        if (root->left == NULL && root->right == NULL)
        {
            res += stoi(s);
        }
        preorder(root->left, s, res);
        preorder(root->right, s, res);

        s.pop_back();
    }
};

// METHOD  2:-

class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        int res = 0, curr = 0;
        preorder(root, curr, res);

        return res;
    }

    void preorder(TreeNode *root, int &curr, int &res)
    {
        if (root == NULL)
            return;

        curr = curr * 10 + root->val;

        if (root->left == NULL && root->right == NULL)
        {
            res += curr;
        }
        else
        {
            preorder(root->left, curr, res);
            preorder(root->right, curr, res);
        }

        curr = (curr - root->val) / 10;
    }
};