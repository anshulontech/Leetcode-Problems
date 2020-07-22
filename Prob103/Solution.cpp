// Approach 1 :-

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        stack<TreeNode *> first_stack, second_stack;
        if (root)
            first_stack.push(root);
        vector<vector<int>> res;
        int depth = 0;

        while (!first_stack.empty())
        {
            res.push_back({});

            while (!first_stack.empty())
            {
                TreeNode *temp = first_stack.top();
                first_stack.pop();

                res[depth].push_back(temp->val);
                if (temp->left)
                    second_stack.push(temp->left);
                if (temp->right)
                    second_stack.push(temp->right);
            }

            depth++;
            if (!second_stack.empty())
                res.push_back({});

            while (!second_stack.empty())
            {
                TreeNode *temp = second_stack.top();
                second_stack.pop();

                res[depth].push_back(temp->val);
                if (temp->right)
                    first_stack.push(temp->right);
                if (temp->left)
                    first_stack.push(temp->left);
            }

            depth++;
        }

        return res;
    }
};