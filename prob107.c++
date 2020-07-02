// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     Just Do the simple level order traversal with each level in different vector and than reverse the whole vector 
// of vector to get the bottom - top traversal.

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> store;
        
        queue<TreeNode*> helper;
        if(root)
        helper.push(root);
        
        while(!helper.empty()) {
            int n=helper.size();
            
            store.push_back({});
            int m=store.size();
            
            for(int i=0;i<n;i++) {
                TreeNode* temp=helper.front();
                helper.pop();
                
                store[m-1].push_back(temp->val);
                if(temp->left)
                    helper.push(temp->left);
                if(temp->right)
                    helper.push(temp->right);
            }
        }
        
        reverse(store.begin(),store.end());
        return store;
    }
};