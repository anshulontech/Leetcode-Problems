// https://leetcode.com/problems/add-one-row-to-tree/description/

// Time COmplexity:-O(N).
// Space Complexity:-O(N). For Recurssion Stack.
    
// Approach:-
//     In this what we are going to do is that we will traverse the tree with taking the depth of the current node. 
// If at any instance the curr depht if found to be equal to d-1 than we will add a row there and than will not go 
// forward and than go back.

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        int curr_depth=1;
        if(d==1) {
            TreeNode* temp = new TreeNode( v );
            temp->left=root;
            
            return temp;
        }
        helper(root,v,d,curr_depth);
        
        return root;
    }
    
    void helper(TreeNode* root, int& v ,int & d ,int & curr_depth) {
        if(root==NULL)
            return ;
        
        if(curr_depth<d-1) {
            curr_depth++;
            helper(root->left,v,d,curr_depth);
            helper(root->right,v,d,curr_depth);
            curr_depth--;
        }
        
        if(curr_depth==(d-1)) {
            TreeNode* temp_left=new TreeNode(v);
            TreeNode* temp_right=new TreeNode(v);
            
            temp_left->left=root->left;
            temp_right->right=root->right;
            
            root->left=temp_left;
            root->right=temp_right;
            
        }
    }
};