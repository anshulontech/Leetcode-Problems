// https://leetcode.com/problems/path-sum-iii/

// Time Complexity=O(N).
// Space Complexity=O(N).

// Approach:-
// First of all we make a unordered map or hash table in which key represents sum till that node and value represents 
// number of ways by which we can reach to that sum. We start traversing each node and update its value by making it equal
// to sum till that node and also on other hand adding values to the map. At each node we will check that is any value 
// equal to (root->val-sum) exist in the map or not , if yes than we add its corresponding value to output result otherwise 
// add 0.after this we pass root->left and root->right and just follow the recursion process.


int helper(TreeNode * ,int ,unordered_map<int,int> & ,int );
    
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int,int> A;
        return helper(root,sum,A,0);
    }
};

int helper(TreeNode * root,int sum,unordered_map<int,int> & A,int prefixsum)
{
    if(root==NULL)
        return 0;
    root->val+=prefixsum;
    int res= (root->val==sum) + (A.count(root->val-sum)? A[root->val-sum] : 0) ;
    A[root->val]++;
    
    res+=helper(root->left,sum,A,root->val)+helper(root->right,sum,A,root->val);
    A[root->val]--;
    return res;
}