// https://leetcode.com/problems/cousins-in-binary-tree/

// Method 1:

// Time Complexity:-O(N).
// Space Compleity:-O(N).
    
// Approach:-
//     Initially we will store all the ancestores of a node in a vector for both he nodes and than check if the size of both of 
// the are equal and having different first value(that is parents are different) than we will return true else return false.

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        vector<int > storex;
        vector<int > storey;
        
        int flag=0;
        preorder(root,x,storex,flag);
        flag=0;
        preorder(root,y,storey,flag);
        
        if(storex.size()==storey.size() && storex[0]!=storey[0])
            return true;
        else
            return false;
    }
    
    void preorder(TreeNode* root, int temp,vector<int> & store,int & flag)
    {
        if(root==NULL)
            return;
        
        if(root->val==temp)
        {
            flag=1;
            return;
        }
        
        if(flag!=1)
            preorder(root->left,temp,store,flag);
        if(flag==1)
        {
            store.push_back(root->val);
            return;
        }
        else
            preorder(root->right,temp,store,flag);
        
        if(flag==1)
        {
            store.push_back(root->val);
            return;
        }
    }
};

// Method 2:

// Time Complexity:-O(N).
// Space Compleity:-O(1).
    
// Approach:-
//     In this approach what we are goig to do is to travserse the tree and on encounter of either node x or y we will update 
// their depth in thier depth variable and also return from that path as their is no need to search for below level. At last 
// we will check that is their depth are equal or not if they are than check that is parents are different or not. If they are 
// than we will return true else return false.
class Solution {
private:
    int x_depth=0;
    int y_depth=0;
    TreeNode* x_parent;
    TreeNode* y_parent;
public:
    bool isCousins(TreeNode* root, int x, int y) {
        preorder(root,x,y,0,nullptr);
        
        if(x_depth==y_depth && x_parent!=y_parent)
            return true;
        else
            return false;
    }
    
    void preorder(TreeNode* root, int x, int y,int depth,TreeNode* pre)
    {
        if(root==NULL)
            return;
        
        if(root->val==x)
        {
            x_depth=depth;
            x_parent=pre;
            return ;
        }
        if(root->val==y)
        {
            y_depth=depth;
            y_parent=pre;
            return;
        }
        
        preorder(root->left,x,y,depth+1,root);
        preorder(root->right,x,y,depth+1,root);
    }
};