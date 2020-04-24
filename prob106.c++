// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

// Time Complexity:-O(N^2).
// Space Complexity:-O(N).
    
// Approach:-
//     Initially we will store the index of all number of inorder in a map and run the loop. Now if the index of the node in 
// inorder is less than previous node value than it will on it's left otherwise on it's right. By doing so we will get our 
// final tree. Here we are going to itterate the postorder from back side.
        
        
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size()==0)
            return nullptr;
        unordered_map<int,int> index;
        
        for(int i=0;i<inorder.size();i++)
            index[inorder[i]]=i;
        
        TreeNode* root= new TreeNode(postorder[postorder.size()-1]);
        
        stack<TreeNode*> store;
        
        store.push(root);
        
        for(int i=postorder.size()-2;i>=0;--i)
        {
            TreeNode* head= new TreeNode(postorder[i]);
            
            if(index[head->val]>index[store.top()->val])
                store.top()->right=head;
            else
            {
                TreeNode* temp=nullptr;
                
                while(!store.empty() && index[head->val]<index[store.top()->val])
                {
                    temp=store.top();
                    store.pop();
                }
                
                temp->left=head;
            }
            
            store.push(head);
        }
        
        return root;
        
    }
};