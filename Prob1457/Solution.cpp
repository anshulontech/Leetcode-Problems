// Approach 1:-

class Solution
{
private:
    vector<int> store;
    int res = 0;
    int even = 0, odd = 0;

public:
    int pseudoPalindromicPaths(TreeNode *root)
    {
        for (int i = 0; i < 9; i++)
            store.push_back(0);

        traversal(root);

        return res;
    }

    void traversal(TreeNode *root)
    {
        if (root == NULL)
            return;

        store[root->val - 1]++;

        if (store[root->val - 1] % 2 == 0)
        {
            even++;
            if (odd > 0)
                odd--;
        }
        else
        {
            odd++;
            if (even > 0)
                even--;
        }

        if (root->left == NULL && root->right == NULL)
        {
            if (odd < 2)
                res++;
        }
        else
        {
            traversal(root->left);
            traversal(root->right);
        }

        store[root->val - 1]--;

        if (store[root->val - 1] % 2 == 0)
            even++, odd--;
        else
            odd++, even--;
    }
};

// Approach 2:-

class Solution
{
private:
    vector<int> store;
    int res = 0;
    int odd = 0;

public:
    int pseudoPalindromicPaths(TreeNode *root)
    {
        for (int i = 0; i < 9; i++)
            store.push_back(0);

        traversal(root);

        return res;
    }

    void traversal(TreeNode *root)
    {
        if (root == NULL)
            return;

        store[root->val - 1]++;

        if (store[root->val - 1] % 2 == 0)
        {
            if (odd > 0)
                odd--;
        }
        else
            odd++;

        if (root->left == NULL && root->right == NULL)
        {
            if (odd < 2)
                res++;
        }
        else
        {
            traversal(root->left);
            traversal(root->right);
        }

        store[root->val - 1]--;

        if (store[root->val - 1] % 2 == 0)
            odd--;
        else
            odd++;
    }
};