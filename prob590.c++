// https://leetcode.com/problems/n-ary-tree-postorder-traversal/submissions/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     Same as that of postorder traversal of binary tree. Here first we call the first child of the node than next one than 
// next and so on. And store all their value in the vector and in last return that one.
  

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> store;
        
        post(root,store);
        return store;
    }
    
    void post(Node* root,vector<int> & store)
    {
        if(root==NULL)
            return;
        
        for(int i=0;i<root->children.size();i++)
            post(root->children[i],store);
        
        store.push_back(root->val);
        
        return;
    }
};