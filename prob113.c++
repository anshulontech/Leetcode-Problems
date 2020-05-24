// https://leetcode.com/problems/path-sum-ii/

// Time Complexity:-O(N).
// Space Complexity;-O(N) -- For recurssion Stack of tree traversal

// Approach:-
//     In this what we are going to do is to traverse the tree in preorder manner. Now we are taking help vector which 
// is used to store the previous nodes and sum as to calculate the sum of the nodes . Now if we reach a leaf node and 
// the sum would become equal to target than we will push that help vector to our result else just go back by removing 
// top element and so on.

class Solution {
private:
    vector<vector<int>> res;
    int ans;
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        int sum=0;
        ans=target;
        vector<int> help;
        helper(root,sum,help);
        return res;
    }
    
    void helper(TreeNode* root,int sum,vector<int> & help) {
        if(root==NULL)
            return ;
        sum+=root->val;
        help.push_back(root->val);
        
        if(sum==ans && root->left==NULL && root->right==NULL) {
            res.push_back(help);
            help.pop_back();
            return;
        }
        
        helper(root->left,sum,help);
        helper(root->right,sum,help);
        
        help.pop_back();
    }
};