// https://leetcode.com/problems/sum-root-to-leaf-numbers/

// Time Coplexity:-O(N).
// Space complexity:-O(N+H).
    
// Approach:-
//     We will traverse the whole tree and as we will move forward we will insert the value of the root to the helper 
// string and on reaching the leaf node we will add the value of string in integer to the result and move forward as 
// we do in the preorder traversal . At the last we are with the answer stored in res variable.

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        string s="";
        int res=0;
        
        preorder(root,s,res);
        
        return res;
    }
    
    void preorder(TreeNode* root, string& s, int& res) {
        if(root==NULL)
            return ;
        
        s+=to_string(root->val);
        
        if(root->left==NULL && root->right==NULL) {
            res+=stoi(s);
        }
        preorder(root->left,s,res);
        preorder(root->right,s,res);
        
        s.pop_back();
    }
};

// Time Complexity:O(N).
// Space Complexity:-O(N) -- For recurssion stack.

// Approach:-
//     Same as that of above one but here we are not going to use the string else we are going to store the result in
// an integer variable and on encounter with leaf node we can add that one to the final result.

class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        int res = 0, curr = 0;
        preorder(root, curr, res);

        return res;
    }

    void preorder(TreeNode *root, int &curr, int &res)
    {
        if (root == NULL)
            return;

        curr = curr * 10 + root->val;

        if (root->left == NULL && root->right == NULL)
        {
            res += curr;
        }
        else
        {
            preorder(root->left, curr, res);
            preorder(root->right, curr, res);
        }

        curr = (curr - root->val) / 10;
    }
};