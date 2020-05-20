// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

// Time Complexity:-O(N).
// Space Complexity:-O(N).  -- just for recursion buffer.
    
// Approach:-
//     In this what we are going to do is that first we will reach to the left ost node of the tree and assign count 
// equal to 1 as this will be the first smallest element in the tree. Now we will start to traverse as inorder and on 
// encounter with each node we will increase the value of count . At any node where the value of count will become 
// equal to k we will assign result to that and return from their.

class Solution {
private:
    int res;
    int pos;
public:
    int kthSmallest(TreeNode* root, int k) {
        
        int count=0;
        pos=k;
        inorder(root,count);
        
        return res;
    }
    
    void inorder(TreeNode* root,int & count)
    {
        if(root==NULL)
            return ;
        
        inorder(root->left,count);
        count++;
        
        if(count==pos)
        {
            res=root->val;
            return ;
        }
        
        if(count<pos)
            inorder(root->right,count);
        
    }
};

Same Approach using itteration : -

                                 class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        stack<TreeNode *> store;

        while (true)
        {
            while (root)
            {
                store.push(root);
                root = root->left;
            }

            root = store.top();
            store.pop();
            if (--k == 0)
                return root->val;

            root = root->right;
        }
    }
};
