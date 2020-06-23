// https://leetcode.com/problems/count-complete-tree-nodes/

// Time complexity:-O(N).
// Space Complexity:-O(h). Where h is height and is used for recurssion stack.
    
// Approach:-
//     We will use preorder traversal to traverse the tree and on encounter with node that is not NULL we will increase 
// our count .

class Solution {
private:
    int count=0;
public:
    int countNodes(TreeNode* root) {
        helper(root);
        
        return count;
    }
    
    void helper(TreeNode* root) {
        if(root==NULL)
            return ;
        
        count++;
        helper(root->left);
        helper(root->right);
    }
};

// Time complexity:-O(h*h).
// Space Complexity:-O(h). Where h is height and is used for recurssion stack.

// Approach:-   
//     In this what we are going to do is that for node on which we are standing we will check that is it's left and right
// subtree height are same or not, if they are founf to be than we have no need to go downward to check toatla node as 
// we can calculate the total nodes from there but if they are not same than we will call function countNode to check 
// the number of nodes in left and right subtree and return there sum with +1 as to include that node and calculate their
// total nodes using recurssion .

class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int h_l = 0, h_r = 0;

        TreeNode *temp = root;
        while (temp)
        {
            temp = temp->left;
            h_l++;
        }

        temp = root;
        while (temp)
        {
            temp = temp->right;
            h_r++;
        }

        if (h_l == h_r)
            return pow(2, h_l) - 1;
        else
            return 1 + countNodes(root->left) + countNodes(root->right);
    }
};