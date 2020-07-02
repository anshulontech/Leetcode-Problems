// https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/description/

// Time Complexity:-O(N).
// Space Complexity:-O(N). For Recurssion stack.
    
// Approach:-
//     In this we are doing the preorder traversal of the the given tree and also taking a pointer to itterate the 
// voyage vector. Now we are traversing the tree and let we are on a node than we will first check that is the nodes 
// val is equal to pointer representing value . If it is than we will moe forward else return from there representing 
// that it is not possible to make tree for voyage, but if they are same than we will check that if next element of the 
// pointer in voyage is same as that of left child if it is that than we will go for the left child else go for the right 
// child taking the root val as one of the node to flip and do the same procdure for that node. Duirng traversing we wre 
// taking a variable check which will tell us that if at any moment node value and pointer value are not same than we will 
// change check value so that it represents it is not possible to form the tree according to voyage.
    
    
class Solution
{
private:
    vector<int> res;
    int check = 1;

public:
    vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage)
    {
        int index = 0;
        helper(root, voyage, index);

        if (check == 1)
            return res;
        else
            return {-1};
    }

    void helper(TreeNode *root, vector<int> &voyage, int &index)
    {
        if (root == NULL)
        {
            return;
        }

        if (voyage[index] != root->val)
        {
            check = 0;
            return;
        }
        index++;
        if (root->left && root->right)
        {
            if (root->left->val == voyage[index])
            {
                helper(root->left, voyage, index);
                helper(root->right, voyage, index);
                return;
            }
            else
            {
                res.push_back(root->val);
                helper(root->right, voyage, index);
                helper(root->left, voyage, index);

                return;
            }
        }

        helper(root->left, voyage, index);
        helper(root->right, voyage, index);
    }
};