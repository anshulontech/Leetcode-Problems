// https://leetcode.com/problems/merge-two-binary-trees/submissions/

// Time Complexity:-O(N+M).
// Space Complexity:-O(N+M).
    
// Approach:-
//     if anyone of the tree is null than we will return the other tree. Now let us asume that we will change everything in the t1 than first we will change the top most value of the tree and than using recursion frst change it's left and than it's right node. At the last we will retuen t1 as final result.
        
// How does the code work:-
//     On the first pass it will change it's first top most value. Now on second pass it will sffect its left part. 
// If any one of them have no left partthan what it will do is to join the left part of other tree usinf NULL condition and 
// also will occur for right part but if any left part is not NULL than what will happen is same as that of top node and 
// hence the tree will be updated.

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL)
            return t2;
        if(t2==NULL)
            return t1;
        
        t1->val+=t2->val;
        t1->left=mergeTrees(t1->left,t2->left);
        t1->right=mergeTrees(t1->right,t2->right);
        
        return t1;
    }
};