// https://leetcode.com/problems/most-frequent-subtree-sum/

// Time Complexity:-O(N).
// Space Compleixty:-O(N).
    
// Approach:-  One Pass Hash Map
//     Initially we will use ModifyTree function to modify the tree such that the value of root node is the sum of 
// it's subtree and also store the sum into a hash map.
    
//     Now we will iterate the hash map and the sum's having max frequency are taken into a vector as final answer.

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

// Similar Approach:- Two Pass Hash Map.

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

// Approach:-
//     Similar that of above one but here to calculate the max_freq we are doing operations only when we are modifying
// the tree so that we have no more requirment of one more pass to the hash map.

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