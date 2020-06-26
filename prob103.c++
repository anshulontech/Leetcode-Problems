// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     In this we are going to use two stack approach the first stack store the node in left to right order of even 
// depth nodes while the second stack store the nodes of od depth in right to left depth and from them we can generate 
// the zig zag level order traversal of the tree.

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> first_stack,second_stack;
        if(root)
            first_stack.push(root);
        vector<vector<int>> res;
        int depth=0;
        
        while(!first_stack.empty()) {
            res.push_back({});
            
            while(!first_stack.empty()) {
                TreeNode* temp=first_stack.top();
                first_stack.pop();
                
                res[depth].push_back(temp->val);
                if(temp->left)
                    second_stack.push(temp->left);
                if(temp->right)
                    second_stack.push(temp->right);
            }
            
            depth++;
            if(!second_stack.empty())
                res.push_back({});
            
            while(!second_stack.empty()) {
                TreeNode* temp=second_stack.top();
                second_stack.pop();
                
                res[depth].push_back(temp->val);
                if(temp->right)
                    first_stack.push(temp->right);
                if(temp->left)
                    first_stack.push(temp->left);
            }
            
            depth++;
        }
        
        return res;
    }
};