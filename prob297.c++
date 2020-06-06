// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     To serialize it we are using preorder traversal and than push the nodes in seperated with ',' and also for NULL 
// nodes we are inserting NULL also seperated with ','.
        
//     To deseralize it we are first inserting the nodes in preorder format into a queue and than we are going to build 
// the tree from it such that till we will not get NULL we will add the upcoming nodes into the left part and than change 
// it to right tree and so on.

class Codec {
public:

    string serialize(TreeNode* root) {
        if(!root) 
            return "NULL,";
        else
            return to_string(root->val)+","+serialize(root->left)+serialize(root->right);
    }

    TreeNode* deserialize(string data) {
        queue <string> q;
        string s="";
        for(int i=0;i<data.size();i++)
            if(data[i]==',') {
                q.push(s);
                s="";
            }
            else
                s+=data[i];
               
        return deserialize_helper(q);
    }
    
    TreeNode* deserialize_helper(queue <string> & q) {
        string s=q.front();
        q.pop();
        if(s=="NULL")
            return NULL;
        
        TreeNode* root=new TreeNode(stoi(s));
        root->left=deserialize_helper(q);
        root->right=deserialize_helper(q);
        
        return root;
        
    }
};