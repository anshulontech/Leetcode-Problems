// Approach 1:-

class Solution
{
private:
    vector<int> res;
    int max_count = 0;
    int count = 0;
    TreeNode *prev = nullptr;

public:
    vector<int> findMode(TreeNode *root)
    {
        traverse(root);
        return res;
    }

    void traverse(TreeNode *root)
    {
        if (root == NULL)
            return;

        traverse(root->left);
        if (prev && prev->val == root->val)
            count++;
        else
            count = 1;

        if (count > max_count)
        {
            res.clear();
            max_count = count;
            res.push_back(root->val);
        }
        else if (count == max_count)
            res.push_back(root->val);

        prev = root;
        traverse(root->right);
        return;
    }
};