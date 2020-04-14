// https://leetcode.com/problems/n-ary-tree-preorder-traversal/submissions/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     Same as that of preorder traversal of binary tree. Here first we call the first child of the node than next one than 
// next and so on. And store all their value in the vector and in last return that one.
    
    
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> store;
        
        pre(root,store);
        return store;
    }
    
    void pre(Node* root,vector<int> & store)
    {
        if(root==NULL)
            return;
        
        store.push_back(root->val);
        
        for(int i=0;i<root->children.size();i++)
            pre(root->children[i],store);
        
        return;
    }
};