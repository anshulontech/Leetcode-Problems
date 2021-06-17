// Link To Problem:-
// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> store;

        queue<TreeNode *> helper;
        if (root)
            helper.push(root);

        while (!helper.empty())
        {
            int n = helper.size();

            store.push_back({});
            int m = store.size();

            for (int i = 0; i < n; i++)
            {
                TreeNode *temp = helper.front();
                helper.pop();

                store[m - 1].push_back(temp->val);
                if (temp->left)
                    helper.push(temp->left);
                if (temp->right)
                    helper.push(temp->right);
            }
        }

        reverse(store.begin(), store.end());
        return store;
    }
};