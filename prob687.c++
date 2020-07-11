// https://leetcode.com/problems/longest-univalue-path/description/

// Time Complexity:-O(N).
// Space Complexity:-O(H).

class Solution {
private:
    int ans=0;
public:
    int longestUnivaluePath(TreeNode* root) {
        ans=0;
        helper(root);
        
        return ans;
    }
private:
    int helper(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        int left=helper(root->left);
        int right=helper(root->right);
        
        int left_val=0,right_val=0;
        
        if(root->left && root->val==root->left->val)
            left_val+=left+1;
        
        if(root->right && root->val==root->right->val)
            right_val+=right+1;
        
        ans=max(ans,left_val+right_val);
        return max(left_val,right_val);
    }
};