// https://leetcode.com/problems/binary-tree-right-side-view/

// Time Complexity:-O(N).
// Space Complexity:-O(H).
    
// Aproach:-  (Recurssive)
//     Here we will use a vector to store the right most value of the tree which was visited yet at the index depth 
// respectively and after this we will return this as the final answer.

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;

        int depth = 0;
        preorder(root, depth, res);

        return res;
    }

    void preorder(TreeNode *root, int depth, vector<int> &store)
    {
        if (root == NULL)
            return;
        if (depth >= store.size())
            store.push_back(root->val);
        else
            store[depth] = root->val;

        preorder(root->left, depth + 1, store);
        preorder(root->right, depth + 1, store);
    }
};

// Approach:- (Iterative)
//     Same as that of above one.

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;

        if (root == NULL)
            return res;
        queue<TreeNode *> store;
        store.push(root);

        while (!store.empty())
        {
            int n = store.size();

            int temp;

            while (n)
            {
                temp = store.front()->val;
                if (store.front()->left != NULL)
                    store.push(store.front()->left);
                if (store.front()->right != NULL)
                    store.push(store.front()->right);

                store.pop();
                n--;
            }

            res.push_back(temp);
        }

        return res;
    }
};