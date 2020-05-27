// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

// Time Complexity:-O(H) -- Where H is height of the binary tree.
// Space Complexity;-O(H) -- Use In Recurssion Stack.
    
// Approach:-
//     In this we are going to usr the property of binary search tree. Noe let us asume that what if the root val is 
// greater than p's val and less than q' val or vice versa than it repreesnts that to find the two node we should 
// diverge from that node hence we can say that this is the lowest common ancestor of these two nodes. But what if 
// both of then=m have greater value than we should do the same for right subtree else for left subtree. But what 
// anyone of the node is the lowest common ancestore than we will check that if root becomes equal to anynode than 
// we will retur that node.


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if((root->val-p->val)*(root->val-q->val)<=0)
            return root;
        else 
            if((root->val-p->val)<0)
                return lowestCommonAncestor(root->right,p,q);
            else
                return lowestCommonAncestor(root->left,p,q);
    }
};