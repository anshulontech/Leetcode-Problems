// https://leetcode.com/problems/linked-list-in-binary-tree/

// Time Complexity:-O(N^2).
// Space Complexity:-O(1).
    
// Apprach:-
//     For each node using check function we will check that is th linked list was found their or not , if it was than we return 
// true else check for the left node and than for right node using recurssion.


class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root==NULL)
            return false;
        
        return check(head,root) || isSubPath(head,root->left) || isSubPath(head,root->right);
    }
    
    bool check(ListNode* head, TreeNode* root)
    {
        if(head==NULL)
            return true;
        
        if(root==NULL)
            return false;
        
        if(head->val==root->val)
            return check(head->next,root->left) || check(head->next,root->right);
        else
            return false;
    }
};