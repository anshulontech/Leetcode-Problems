// Link To Problem:-
// https://leetcode.com/problems/n-ary-tree-preorder-traversal/submissions/

// METHOD 1:-

class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        vector<int> store;

        pre(root, store);
        return store;
    }

    void pre(Node *root, vector<int> &store)
    {
        if (root == NULL)
            return;

        store.push_back(root->val);

        for (int i = 0; i < root->children.size(); i++)
            pre(root->children[i], store);

        return;
    }
};