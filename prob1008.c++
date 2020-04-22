// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
    // Using a stack we will going to store the address of nodes in adecreasing sense in the stack. On encounter of a new 
// value in preorder we will check that if the value of top of stack is greater than this nodes will be it's left child while 
// if it is greater than than we will run a loop till stack is not empty or a larger value is not their. If larger value is 
// found than we will make the temp node to that one's right node and than push that node into the stack. At last return the 
// value of root as final answer.
    
    
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode * root= new TreeNode(preorder[0]);
        stack<TreeNode*> nodes;
        nodes.push(root);
        
        for(int i=1;i<preorder.size();i++)
        {
            TreeNode * temp= new TreeNode(preorder[i]);
            if(temp->val<nodes.top()->val)
                nodes.top()->left=temp;
            else
            {
                TreeNode * prev;
                while(!nodes.empty() && nodes.top()->val<temp->val)
                {
                    prev=nodes.top();
                    nodes.pop();
                }
                
                prev->right=temp;
            }
            
            nodes.push(temp);
        }
        
        return root;
    }
};