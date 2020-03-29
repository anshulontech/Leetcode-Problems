// https://leetcode.com/problems/path-sum-iii/

// Time Complexity=O(N^2).
// Space Complexity=O(1).

// Approach:-
// In this we use recursion .In first by calling the pathSum function we will check that is sum of nodes equal to target
// exist including first node or not. On agai calling pathSum with root->left represents that is sum exist starting with 
// 2nd node and so on . So we can say that in this approch we will check that is their sum exist by checking each node.

int helper(TreeNode * &, int , int );

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return 0;
        
        return helper(root,0,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
    }
};

int helper(TreeNode * &root, int prefixsum, int target)
{
    if(root==NULL)
        return 0;
    
    prefixsum+=root->val;
    
    return (prefixsum==target)+helper(root->left,prefixsum,target)+helper(root->right,prefixsum,target);
}