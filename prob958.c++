// https://leetcode.com/problems/check-completeness-of-a-binary-tree/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     We are going to store the nodes in the queue and traverse it like level order traversal. At any step we will check 
// that is the fron node is NULL or not if it will than we will leave the traversing and check that is any further node is not 
// NULL than it will represent that it is not a complete binary tree and hence return false otherwise return true.

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> store;
        
        store.push(root);
        while(!store.empty())
        {
            TreeNode* temp=store.front();
            if(temp==NULL)
                break;
            store.push(temp->left);
            store.push(temp->right);
            
            store.pop();
        }
        
        if(store.empty())
            return true;
        else
        {
            while(!store.empty())
            {
                TreeNode* temp=store.front();
                if(temp!=NULL)
                    return false;
                else
                    store.pop();
            }
            
            return true;
        }
    }
};