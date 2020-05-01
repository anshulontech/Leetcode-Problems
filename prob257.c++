// https://leetcode.com/problems/binary-tree-paths/

// Time Complexity:-O(N).
// Space Complexity:-(N).
    
// Approach:-
//     We will simply use recurssion to traverse the tree. if we will encounter the leaf node than we will push the string at 
// that time to the store and after traversing the left and right child of the tree we will remove the part o that node from 
// the string.

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> store;
        if(root==NULL)
            return store;
        string s;
        
        checkpath(root,store,s);
        
        return store;
    }
    
    void checkpath(TreeNode* root, vector<string> & store,string & s)
    {
        s.insert(s.size(),to_string(root->val));
        if(root->left==NULL && root->right==NULL)
        {
            store.push_back(s);  // If leaf node than insreting s into store.
            int i=checklength(root->val);
            
            if(root->val<0)
                i++;
            while(i>0)  //  removing that part of node from the string
            {
                s.pop_back();
                i--;
            }
            return ;
        }
        
        s.insert(s.size(),"->");
        
        if(root->left)
            checkpath(root->left,store,s);  // checking for left part.
            
        if(root->right)
            checkpath(root->right,store,s);  // checking for right part
        
        int i=checklength(root->val);
        i+=2;
        
        if(root->val<0)
            i++;
        while(i>0)
        {
            s.pop_back();  //  removing that part of node from the string
            i--;
        }
    }
    
    int checklength(int n)  // Use to calculate length in string of root->val.
    {
        n=abs(n);
        int l=1;
        while(n/10>0)
        {
            l++;
            n/=10;
        }
        
        return l;
    }
};