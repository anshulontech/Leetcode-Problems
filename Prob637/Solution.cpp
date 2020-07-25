// Approach 1 :- (DFS).

class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<pair<long, long>> store;
        int depth = 0;

        dfs(root, store, depth);

        vector<double> res;

        for (int i = 0; i < store.size(); i++)
            res.push_back((double)(store[i].first) / (store[i].second));

        return res;
    }

    void dfs(TreeNode *root, vector<pair<long, long>> &store, int &depth)
    {
        if (root == NULL)
            return;

        if (store.size() > depth)
        {
            store[depth].first += root->val;
            store[depth].second++;
        }
        else
            store.push_back(make_pair(root->val, 1));

        depth++;

        dfs(root->left, store, depth);
        dfs(root->right, store, depth);

        depth--;
    }
};

// Approach 2 :-

class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<double> res;

        if (root)
            q.push(root);

        while (!q.empty())
        {
            int N = q.size();
            double sum = 0;

            for (int i = 0; i < N; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                sum += (double)temp->val;

                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }

            res.push_back((double)(sum) / N);
        }

        return res;
    }
};