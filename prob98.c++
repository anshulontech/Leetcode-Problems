// https://leetcode.com/problems/validate-binary-search-tree/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     In this first we will store the inordered traversal of the BST in a vector. Now we traverse the vector and if 
// the ext value is found to be less than or equal to previous one than we will return false else will check till last 
// and if loop terminates itself than will return true.

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> store;
        makearray(root,store);
        
        for(int i=1;i<store.size();i++)
            if(store[i]<=store[i-1])
                return false;
        
        return true;
    }
    
    void makearray(TreeNode* root,vector<int> & store) {
        if(root==NULL)
            return ;
        
        makearray(root->left,store);
        store.push_back(root->val);
        makearray(root->right,store);
    }
};