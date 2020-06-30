// https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/

// Time Complexity:-O(N).
// Space Complexity:-O(H). For Recurssion stack as well as to store the result.
    
// Approach:-
//     We will go for the preorder traversal with depth variable and we are going to store the max value in a vector. 
// Now let say we are traversing the tree and we are at d depth than we will check that is the vector size if less than 
// equal to d than it represents that this is the first element for that depth hence at d index we will insert that 
// depth but if size is greater than d than we know that there is already an element exist there so we will check that 
// is already existing value grater or the curreent and than set the answer on the basis which is greater. So by this 
// after traversing we can generate our result.
        
class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        int depth = 0;

        check(root, depth);

        return res;
    }

private:
    vector<int> res;

    void check(TreeNode *root, int &depth)
    {
        if (root == NULL)
            return;

        if (depth >= res.size())
            res.push_back(root->val);
        else if (res[depth] < root->val)
            res[depth] = root->val;

        depth++;
        check(root->left, depth);
        check(root->right, depth);

        depth--;
    }
};

// Approach:- Itterative Level Order Traversal.

class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        queue<TreeNode *> store;
        vector<int> res;

        if (root)
            store.push(root);

        while (!store.empty())
        {
            int ans = INT_MIN;
            int n = store.size();

            for (int i = 0; i < n; i++)
            {
                TreeNode *temp = store.front();
                ans = max(ans, temp->val);
                store.pop();
                if (temp->left)
                    store.push(temp->left);
                if (temp->right)
                    store.push(temp->right);
            }

            res.push_back(ans);
        }

        return res;
    }
};