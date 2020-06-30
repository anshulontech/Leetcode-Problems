// https://leetcode.com/problems/find-bottom-left-tree-value/description/

// Time Complexity:-O(N).
// Space Complexity:-O(H). For Recurssion stack.
     
// Approach:-  (Recursive preorder traversal).
//     We will just go for the preorder traversal of the tree and also taking the depth of the current node, now as 
// we are traversing the tree if the curr depth is found to be strictly greater than max_depth than it represents 
// that it is the first left element of the new depth as we are going for preorder traversal and upadte the result 
// and move for the next one.

class Solution
{
public:
    int findBottomLeftValue(TreeNode *root)
    {
        int depth = 0;

        check(root, depth);

        return res;
    }

private:
    int res, max_depth = -1;

    void check(TreeNode *root, int &depth)
    {
        if (root == NULL)
            return;

        if (depth > max_depth)
        {
            max_depth = depth;
            res = root->val;
        }

        depth++;
        check(root->left, depth);
        check(root->right, depth);

        depth--;
    }
};

// Approach : -Itterative Approach with Level order traversal

class Solution
{
public:
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> store;

        int res;

        store.push(root);

        while (!store.empty())
        {
            int n = store.size();

            res = store.front()->val;

            for (int i = 0; i < n; i++)
            {
                TreeNode *temp = store.front();
                store.pop();

                if (temp->left)
                    store.push(temp->left);

                if (temp->right)
                    store.push(temp->right);
            }
        }

        return res;
    }
};