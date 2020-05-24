// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

// Time Complexity:-O(N*log(N)).
// Space Complexity:-O(N).

// Approach:-
//     As we know that what is happening here is that for any node the right node of that node will become the right 
// node of rightmost node of it's left subtree . Hence here what we are going to do is that make the right child of a 
// node to it's left sub tree's rightmost right child. After this we will make left child to right child and make it's 
// left child NULL and so on.
    
    
    
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