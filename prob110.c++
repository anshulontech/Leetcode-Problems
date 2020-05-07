// https://leetcode.com/problems/balanced-binary-tree/

// Time Complexity:-O(N^2).
// Space Complexity:-O(N).
    
// Approach:- USING RECURSION.
//     In this approach what we are going to do is to check for each node that is it's left subtree and right subtree have 
// depth difference less than 2 or not . Using recurssion we are going to traverse the whole node and check for each node.

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        return abs(depth(root->left,0)-depth(root->right,0))<2 && isBalanced(root->left) && isBalanced(root->right); 
    }
    
    int depth(TreeNode* root, int isdepth)
    {
        if(root==NULL)
            return isdepth;
        
        return max(depth(root->left,isdepth+1),depth(root->right,isdepth+1));
    }
};


// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:- USING Down To top Approach.
//     In this what we are going to do is to first we will go down in the tree than using recurssion we are going to come upwards
// and after getting up we will check that is the left and right subtree form a balanced binary tree or not if they are not then 
// we will return false else go upwards and so on. At the top of the tree that is root node after checking we will return the 
// final answer.



class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return checkdepth(root)!=-1;
    }
    
    int checkdepth(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
        int left=checkdepth(root->left);
        if(left==-1)
            return -1;
        int right=checkdepth(root->right);
        if(right==-1)
            return -1;
        
        if(abs(left-right)>1)
            return -1;
        else
            return max(left,right)+1;
        
    }
    
    
    
};