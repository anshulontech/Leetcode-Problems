// https://leetcode.com/problems/increasing-order-search-tree/submissions/

// Time Complexity:-  O(2*N) ~~ O(N) .
// Space Complexity:-O(N).
    
// Approach:-
//     Initially we will make a vector of treenode pointer type and than store the indexes of all node in inorder format in 
// the vector. After this we will traverse the vector and as node's values are in increasing order in it due to inorder traversal 
// hence we will assign node's left to NULL and right to the point the next node. For the last node both left and right should 
// be NULL hence we will assign NULL to it and in last return the store[0] which represents head of the tree.
    
    
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode *> store;
        
        inorder(store,root);
        int i=0;
        for(;i<store.size()-1;i++)
        {
            store[i]->left=NULL;
            store[i]->right=store[i+1];
        }
        
        store[i]->left=NULL;
        store[i]->right=NULL;
        
        return store[0];
        
        
    }
    
    void inorder(vector<TreeNode*> & store,TreeNode * root)
    {
        if(root==NULL)
            return ;
        inorder(store,root->left);
        store.push_back(root);
        inorder(store,root->right);
    }
};