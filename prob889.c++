// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

// Time Complexity:-O(N^2).
// Space Complexity:-O(N).
    
// Approach:-
//     Initially we will store the index of all numbers of pot in a map. Now making pre[0] as root node we will going to  
// build the tree . For each next node if it's index is less than previous node than it will be it's child node otherwise we
// will go upward to tree and check the above condition. To go upward we are using stack. 

class Solution {
public:
TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) 
{
    unordered_map<int ,int> index;
        
    for(int i=0;i<post.size();i++)  //  Storing the index
        index[post[i]]=i;
        
    TreeNode * root= new TreeNode(pre[0]);  // Making pre[0] as root node
        
    stack<TreeNode *> prestore;
        
    prestore.push(root);  // Inserting root into the stack
        
    for(int i=1;i<pre.size();i++)
    {
        TreeNode * head= new TreeNode(pre[i]);
        TreeNode * temp=prestore.top();
            
        while(index[pre[i]]>index[temp->val])  // If the inde of head is less than temp->val's index than it will be it's child node 
        {
            temp=prestore.top();
            prestore.pop();   // if index is greater than we wre going upwards in the tree.
        }
            
        if(temp->left==NULL)  // Here head is the child node of the temp hence inserting it's address in right or left which one is empty.
            temp->left=head;
        else
            temp->right=head;
                
        prestore.push(temp);
        prestore.push(head);  // Inserting nodes so that their child nodes can be formed
    }
        
    return root;
        
}
};

// Method 2:-

// Time Complexity:-O(N^2).
// Space Complexity:-O(N).

// Approach:-
//     Using recurssion we going to build the tree now as we know that if root->val==post[postindex] than we had done with that
// node as root to build the tree. Now here we are going to do the same thing with each node , with each node we are going to
// build the sub tree first and than go for upper node.

class Solution {
public:
    
    int preindex=0,postindex=0;
    
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        TreeNode * root = new TreeNode (pre[preindex++]);
        if(root->val!=post[postindex])
            root->left=constructFromPrePost(pre,post);
        if(root->val!=post[postindex])
            root->right=constructFromPrePost(pre,post);
        
        postindex++;
        
        return root;
        
    }
};