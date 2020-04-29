// https://leetcode.com/problems/binary-tree-maximum-path-sum/

// Time Complexity:-O(N^2).
// Space Complexity:-O(N).
    
// Approach:-
//     For each node we will calculate that what is max sum to it's left and to it's right and based on this approach we 
// will get the max sum. Otherwise the code is clear and easy to understand.

class Solution {
private:
    int maxsum;
public:
    int maxPathSum(TreeNode* root) {
        maxsum=INT_MIN;
        maxsumdown(root);
        
        return maxsum;
    }
    
    int maxsumdown(TreeNode* & root)
    {
        if(root==NULL)
            return 0 ;
        
        int left=max(0,maxsumdown(root->left)); // Checking that is left sum is greater than 0 or not. If it will be than we will add this as a part of our solution.
        int right=max(0,maxsumdown(root->right));// Checking that is right sum is greater than 0 or not. If it will be than we will add this as a part of our solution.
        
        maxsum=max(maxsum,left+right+root->val); // If the maxsum is lass than the current node maxsum than we will update it.
        
        return max(left,right)+root->val; // Return max sum to that side.It can be from nodes left or right,but only from 1 side hence max is used. 
    }
};