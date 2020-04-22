// https://leetcode.com/problems/binary-tree-inorder-traversal/

// Time Complxity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     Just using inorder traversal.(But not allowed to do so).

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> store;
        inorder(root,store);
        return store;
    }
    
    void inorder(TreeNode* root,vector<int> & store)
    {
        if(root==NULL)
            return ;
        
        inorder(root->left,store);
        store.push_back(root->val);
        inorder(root->right,store);
    }
};

// Method 2:- Iterative method using stack.

// Approach:-
//     We will start to traverse the tree and try to reach the left ost node of the tree. On reaching the left most node we 
// will push_back its value to res than go for it's right subtree. After travelling it's right tree we come to the it's previous 
// node and than insert it's value to res and than g for right one and by this we will traverse the whole tree.

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        
        stack<TreeNode *> temp;
        
        TreeNode* curr=root;
        
        while(curr!=NULL || !temp.empty())
        {
            while(curr!=NULL)
            {
                temp.push(curr);
                curr=curr->left;
            }
            
            curr=temp.top();
            temp.pop();
            res.push_back(curr->val);
            curr=curr->right;
        }
        
        return res;
    }
};

// Method 3 :- Using morris inorder traversal.--- No need of recursion or stack.

// Approach:-
//     In this we are going to make the tree as threaded binary tree and follow the operations as shown in code.

// Referance:-
// https://www.youtube.com/watch?v=wGXB9OWhPTg

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        
        TreeNode* curr=root;
        while(curr)
        {
            if(curr->left==NULL)
            {
                res.push_back(curr->val);
                curr=curr->right;
                continue;
            }
            
            TreeNode * pre=curr->left;
            while(pre->right!=NULL && pre->right!= curr)
                pre=pre->right;
            
            if(pre->right!=NULL)
            {
                pre->right=NULL;
                res.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                pre->right=curr;
                curr=curr->left;
            }
        }
        
        return res;
    }
};