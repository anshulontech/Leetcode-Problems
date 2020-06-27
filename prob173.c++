// https://leetcode.com/problems/binary-search-tree-iterator/

// Time Complexity:-O(N)-BSTIterator(),    O(1)-next(),    O(1)- hasNext.
// Space Complexity:-O(N)-BSTIterator(),    O(1)-next(),    O(1)- hasNext.
    
// Aapproach:-
//     In this we will first store the inorder traversal fo th ebinary search tree in the vector and than return the 
// answers for next and hasNext function based on that vecotr.

class BSTIterator
{
private:
    vector<int> res;
    int itr = 0;

public:
    BSTIterator(TreeNode *root)
    {
        inorder(root);
    }

    int next()
    {
        return res[itr++];
    }

    bool hasNext()
    {
        if (itr < res.size())
            return true;
        else
            return false;
    }

    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);
    }
};

// Time Complexity:-O(H)-BSTIterator(),    O(H)-next(),    O(1)- hasNext.
// Space Complexity:-O(H)-BSTIterator(),    O(H)-next(),    O(1)- hasNext.

class BSTIterator
{
private:
    stack<TreeNode *> store;

public:
    BSTIterator(TreeNode *root)
    {
        TreeNode *temp = root;
        while (temp != NULL)
        {
            store.push(temp);
            temp = temp->left;
        }
    }

    int next()
    {
        TreeNode *res = store.top();
        store.pop();
        TreeNode *temp = res ? res->right : NULL;

        while (temp)
        {
            store.push(temp);
            temp = temp->left;
        }

        return res->val;
    }

    bool hasNext()
    {
        if (store.empty())
            return false;
        else
            return true;
    }
};