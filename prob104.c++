// https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/

// Time Complexity:-O(log(N)) Where N is total number of nodes.
// Space Complexity:-O(1).
    
// Approach:-
//     We are going to traverse the whole tree with each level one by one and chck that that what is its max length beneath
// that node by calling again the function maxDepth. The 1 in the return statement reresents that node to include in the 
// answer.
    
    
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};

// METHOD 2:- USING QUEUE->BFS.

// Time Complexity:-O(N)
// Space Complexity:-O(N).
// Approach:-
//     In breadth first approach we are going to traverse the whole tree with each node and than try to calculate the 
// length of tree by finding max of its children.

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int res=0;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty())
        {
            res++;
            for(int i=0,n=q.size();i<n;i++)
            {
                TreeNode*temp=q.front();
                q.pop();
                
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
            }
        }
        
        return res;
        
    }
};