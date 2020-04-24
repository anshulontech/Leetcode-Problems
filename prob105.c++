// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

// Time Complexity:-O(N^2).
// Space Complexity:-O(N).
   
// Approach:-
//     Initially we will store the index of all number of inorder in a map and run the loop. Now if the index of the node is 
// less than previous node value than it will on it's left otherwise on it's right. By doing so we will get our final tree.

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0)
            return nullptr;
        
        unordered_map<int,int> index;
        
        for(int i=0;i<inorder.size();i++)  // map storing indexes.
            index[inorder[i]]=i;
        
        TreeNode * root = new TreeNode(preorder[0]);  // Formation of root node.
        stack<TreeNode * > store;
        
        store.push(root);
        
        for(int i=1;i<preorder.size();i++)
        {
            TreeNode * head = new TreeNode(preorder[i]);
            
            if(index[head->val]<index[store.top()->val])  // If curr index is less than it will be on left.
                store.top()->left=head;
            else
            {
                TreeNode * parent=nullptr;
                
                while(!store.empty() && index[head->val]>index[store.top()->val])  // otherwise run loop untill index will not become equal or stackbecome empty.
                {
                    parent=store.top();
                    store.pop();
                }
                
                parent->right=head;
            }
            
            store.push(head);
        }
        
        return root;
    }
};

Method 2 :- Using recurssion.

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> store;
        for(int i=0;i<inorder.size();i++)
            store[inorder[i]]=i;
        
        return helper(preorder,inorder,store,0,preorder.size()-1,0,inorder.size()-1);
    }
    
    TreeNode * helper(vector<int>& preorder, vector<int>& inorder,unordered_map<int,int>& store,int ps ,int pe, int is ,int ie)
    {
        if(ps>pe)
            return nullptr;
        
        TreeNode* root= new TreeNode(preorder[ps]);
        
        int pos=store[preorder[ps]];
        
        root->left=helper(preorder,inorder,store,ps+1,ps+pos-is,is,pos-1);
        root->right=helper(preorder,inorder,store,pe-ie+pos+1,pe,pos+1,ie);
        return root;
    }
};