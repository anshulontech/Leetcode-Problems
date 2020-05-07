// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/


// Method 1:
// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     using preorder type traversal we are going to store the ancestors of the node p in a set and ancestors of node q in a 
// vector(So to mke an order). Now we will start to itterate the vector and check that is that node is present in the set or 
// not if it was than it represent that this is first node as we are traversing the map in specific order.

// Algorithm

// 1.Start traversing the tree from the root node.
// 2.If the current node itself is one of p or q, we would mark a variable mid as True and continue the search for the other 
// node in the left and right branches.
// 3.If either of the left or the right branch returns True, this means one of the two nodes was found below.
// 4.If at any point in the traversal, any two of the three flags left, right or mid become True, this means we have found the 
// lowest common ancestor for the nodes p and q.


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_set<TreeNode*> storep;
        vector<TreeNode*> storeq;
        
        int flagp=0,flagq=0;
        preorderp(root,p,storep,flagp);
        preorderq(root,q,storeq,flagq);
        
        
        
        for(int i=0;i<storeq.size();i++)
            if(storep.find(storeq[i])!=storep.end())
                return storeq[i];
        
        return root;
    }
    
    void preorderp(TreeNode* root,TreeNode* temp,unordered_set<TreeNode*> & store,int & flag)
    {
        if(root==NULL)
            return;
        
        if(root==temp)
        {
            store.insert(root);
            flag=1;
            return;
        }
        
        if(flag!=1)
            preorderp(root->left,temp,store,flag);
        
        if(flag==1)
        {
            store.insert(root);
            return;
        }
        
        if(flag!=1)
            preorderp(root->right,temp,store,flag);
        
        if(flag==1)
        {
            store.insert(root);
            return;
        }
    }
    
    void preorderq(TreeNode* root,TreeNode* temp,vector<TreeNode*> & store,int & flag)
    {
        if(root==NULL)
            return;
        
        if(root==temp)
        {
            store.push_back(root);
            flag=1;
            return;
        }
        
        if(flag!=1)
            preorderq(root->left,temp,store,flag);
        
        if(flag==1)
        {
            store.push_back(root);
            return;
        }
        
        if(flag!=1)
            preorderq(root->right,temp,store,flag);
        
        if(flag==1)
        {
            store.push_back(root);
            return;
        }
    }
};

// Method 2:
// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     In this what we are going to do is that if if we will encounter with either of p or q than we will flag variable as true
// and all preceding path to it are also going to show true to their path as they are representing their ancestors. Now after 
// this as we traverse for next node we will check that is the curr path or preceding path is true or not . While it will not 
// become true we will backtrack our path and on encounter with true we will return that node.

class Solution {

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool temp=recursiontree(root,p,q);
        return ans;
    }
private:
    TreeNode* ans=nullptr;
    
    bool recursiontree(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==NULL)
            return false;
        
        int left=recursiontree(root->left,p,q) ? 1 : 0;
        int right=recursiontree(root->right,p,q) ? 1 : 0;
        
        int mid=(root==p || root==q ) ? 1 : 0;
        
        if(mid+left+right>=2)
            ans=root;
        
        return mid+left+right>0;
    }
    
};