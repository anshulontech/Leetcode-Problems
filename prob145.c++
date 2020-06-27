// https://leetcode.com/problems/binary-tree-postorder-traversal/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     Recurssive approach for post order traversal.

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;

        postOrder(root, res);

        return res;
    }

    void postOrder(TreeNode *root, vector<int> &res)
    {
        if (root == NULL)
            return;

        postOrder(root->left, res);
        postOrder(root->right, res);

        res.push_back(root->val);
    }
};

// Iterative Approach 1.

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        
        stack<TreeNode*> store;
        
        if(root)
            store.push(root);
        
        while(!store.empty()) {
            TreeNode* temp=store.top();
            store.pop();
            
            res.push_back(temp->val);
            if(temp->left)
                store.push(temp->left);
            if(temp->right)
                store.push(temp->right);
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};

// Iterative Approach 2.

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;

        stack<TreeNode *> store;
        TreeNode *last = NULL;

        while (root || !store.empty())
            if (root)
            {
                store.push(root);
                root = root->left;
            }
            else
            {
                TreeNode *curr = store.top();
                if (curr->right && curr->right != last)
                {
                    root = curr->right;
                }
                else
                {
                    res.push_back(curr->val);
                    last = curr;
                    store.pop();
                }
            }

        return res;
    }
};