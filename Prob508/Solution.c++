// Link To Problem:-
// https://leetcode.com/problems/most-frequent-subtree-sum/

// METHOD 1:-

class Solution
{
private:
    unordered_map<int, int> store;

public:
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        vector<int> res;
        int max_freq = INT_MIN;
        ModifyTree(root);

        for (auto x : store)
            if (x.second == max_freq)
                res.push_back(x.first);
            else if (x.second > max_freq)
            {
                res.clear();
                max_freq = x.second;
                res.push_back(x.first);
            }

        return res;
    }

    void ModifyTree(TreeNode *root)
    {
        if (root == NULL)
            return;

        ModifyTree(root->left);
        ModifyTree(root->right);

        root->val += ((root->left ? root->left->val : 0) + (root->right ? root->right->val : 0));

        store[root->val]++;

        return;
    }
};

// METHOD 2:-

class Solution
{
private:
    unordered_map<int, int> store;

public:
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        vector<int> res;
        int max_freq = INT_MIN;
        ModifyTree(root);

        for (auto x : store)
            max_freq = max(max_freq, x.second);

        for (auto x : store)
            if (x.second == max_freq)
                res.push_back(x.first);

        return res;
    }

    void ModifyTree(TreeNode *root)
    {
        if (root == NULL)
            return;

        ModifyTree(root->left);
        ModifyTree(root->right);

        root->val += ((root->left ? root->left->val : 0) + (root->right ? root->right->val : 0));

        store[root->val]++;

        return;
    }
};

// METHOD 3:-

class Solution
{
private:
    unordered_map<int, int> store;
    int max_freq = INT_MIN;

public:
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        vector<int> res;
        ModifyTree(root);

        for (auto x : store)
            if (x.second == max_freq)
                res.push_back(x.first);

        return res;
    }

    void ModifyTree(TreeNode *root)
    {
        if (root == NULL)
            return;

        ModifyTree(root->left);
        ModifyTree(root->right);

        root->val += ((root->left ? root->left->val : 0) + (root->right ? root->right->val : 0));

        store[root->val]++;

        max_freq = max(max_freq, store[root->val]);

        return;
    }
};