// https://leetcode.com/problems/flip-equivalent-binary-trees/description/

// Time Complexity:-O(N).
// Space Complexity:-O(N) -- For Recurssion stack.
    
// Approach:-
//     First We will check for the node on which we are standing if they are not same than we will return false of 
// these are same than we will check that is their left nodes are same or not if there left nodes are same then we 
// will not flip the tree at that poisition and check for downward without flipping but if they are not same then we 
// will check it by flipping. Some conditions are marked like if nodes are NULL than what we have to do so these are 
// commented in the code.

class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL || root2==NULL)
            if(root1==root2)  // If both are NULL 
                return true;
            else  // If anyone is NULL
                return false;
        
        if(root1->val!=root2->val)  // If nodes are different 
            return false;
        else
            if(root1->left && root2->left)  // Both left child exist 
                if(root1->left->val==root2->left->val)  // If left nodes are same than no need to flip.
                    return flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right);
                else  // If left childs are different than there is a need to flip.
                    return flipEquiv(root1->left,root2->right) && flipEquiv(root1->right,root2->left);
            else  // If one's or both's left child are NULL
                if(root1->left)  //  1t left exist
                    if(root1->right) // if it's right exist than it is false since for other one is NULL but here both exist for other.
                        return false;
                    else // if both have 1 NULL than there is need to flip
                        return flipEquiv(root1->left,root2->right);
                else  // If 1st left is NULL
                    if(root2->left)  // If second left exist
                        if(root2->right) // if it's right exist than it is false since for other one is NULL but here both exist for other.
                            return false;
                        else  // if both have 1 NULL than there is need to flip
                            return flipEquiv(root1->right,root2->left);
                    else  // If both left are NULL than no need to flip just check for right.
                        return flipEquiv(root1->right,root2->right);
                            
    }
};

// Time Complexity:-O(N^2).
// Space Complexity:-O(N^2) -- For Recurssion stack.

// Approach:-
//     In this what we are going to do is that we will first check without flipping if in that situation it comes out
// false than we will check by flipping and if it again comes false than we will return false else return true.


class Solution
{
public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 || !root2)
            return root1 == root2;

        return (root1->val == root2->val) && ((flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) || (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left)));
    }
};