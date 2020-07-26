// Approach 1 : -

class Solution
{
private:
    int res = 0;
    int min_dist;

public:
    int countPairs(TreeNode *root, int distance)
    {
        vector<int> dist;
        min_dist = distance;

        preorder(root, dist);

        return res;
    }

    void preorder(TreeNode *root, vector<int> &dist)
    {
        if (root == NULL)
            return;

        int N = dist.size();

        for (int i = 0; i < N; i++)
            dist[i]++;

        if (root->left == NULL && root->right == NULL)
        {
            check(dist);
            dist.push_back(0);
        }

        preorder(root->left, dist);
        preorder(root->right, dist);

        for (int i = 0; i < N; i++)
            dist[i]--;
        for (int i = N; i < dist.size(); i++)
            dist[i]++;
    }

    void check(vector<int> &dist)
    {
        for (int i = 0; i < dist.size(); i++)
            if (dist[i] <= min_dist)
                res++;
    }
};