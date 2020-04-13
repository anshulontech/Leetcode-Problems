// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     We will traverse the whole tree and try to put the value of node in the vector A. as the vector reaches the leaf 
// node it will calculate the sum and than add it to the sum. As returning from the leaf it will lost its previous value and 
// go for the next node.After returning from all nodes it will automatically update the array to its pevious node by releasing 
// the last value and hence can go for further nodes.
        
        
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int sum=0;
        vector<int> A;
        
        treedepth(root,A,sum);
        return sum;
    }
    
    void treedepth(TreeNode * root,vector<int> & A,int & sum)
    {
        if(root==NULL)
            return ;
        else
            A.push_back(root->val);
        if(root->left==NULL&&root->right==NULL)
            sum+=change(A);
    
        treedepth(root->left,A,sum);
        treedepth(root->right,A,sum);
    
        A.pop_back();
        return;
    }
    
    int change(vector<int> A)
    {
        int total=0;
        int i=A.size()-1;
        int k=0;
        while(i>=0)
        {
            total+=A[i]*pow(2,k);
            i--;
            k++;
        }
        
        return total;
    }
};

