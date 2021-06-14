// Link To Problem:-
// https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/

// METHOD 1:-

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

// METHOD 2:-

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int res = 0;

        queue<TreeNode *> q;

        q.push(root);

        while (!q.empty())
        {
            res++;
            for (int i = 0, n = q.size(); i < n; i++)
            {
                TreeNode *temp = q.front();
                q.pop();

                if (temp->left != NULL)
                    q.push(temp->left);
                if (temp->right != NULL)
                    q.push(temp->right);
            }
        }

        return res;
    }
};