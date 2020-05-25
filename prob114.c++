// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

// Time Complexity:-O(N*log(N)).
// Space Complexity:-O(N).

// Approach:-
//     In this Problem What we are going to do is to change the left child of a node to be it's right child and than making right child
// be the right child of rightmost node in left subtree. So here on first Node we will first find the rightmost node and than making
// right child of root to be the right child of rightmost node of left subtree. Now after this we will make left child to be it's right 
// child and make left child NULL and so on. Similarly we will follow the process for all nodes present in the tree. 
    
    
    
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;

        if (root->left != NULL)
        {
            TreeNode *temp = root->left;
            while (temp->right != NULL)
                temp = temp->right;

            temp->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }

        flatten(root->right);
    }
};

// Same as above one but easy code:-

class Solution {
private:
    TreeNode* prev=NULL;
public:
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        
        flatten(root->right);
        flatten(root->left);
        
        root->right=prev;
        root->left=NULL;
        
        prev=root;
    }
};
