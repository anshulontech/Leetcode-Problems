// Link To Problem:-
// https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/

// METHOD 1:-

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> store;

        queue<Node *> q;
        if (root)
            q.push(root);

        while (!q.empty())
        {
            int N = q.size();
            int M = store.size();
            store.push_back({});

            for (int i = 0; i < N; i++)
            {
                Node *temp = q.front();
                q.pop();
                store[M].push_back(temp->val);

                for (int j = 0; j < temp->children.size(); j++)
                    q.push(temp->children[j]);
            }
        }

        return store;
    }
};

// METHOD 2:-
// Recurssive Vesion of above Approach.

class Solution
{
private:
    vector<vector<int>> res;

public:
    vector<vector<int>> levelOrder(Node *root)
    {

        int depth = 0;

        levelOrder(root, depth);

        return res;
    }

    void levelOrder(Node *root, int &depth)
    {
        if (root == NULL)
            return;

        if (res.size() > depth)
            res[depth].push_back(root->val);
        else
            res.push_back({root->val});

        depth++;

        for (int i = 0; i < root->children.size(); i++)
            levelOrder(root->children[i], depth);

        depth--;
    }
};