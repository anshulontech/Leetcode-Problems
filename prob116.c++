// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

// Time Complexity:-O(N). 
// Space Complexity:-O(N).

// Approach:-
//     I this what we are going to do is to store all the nodes having same level in a vector in order from left to
// right and than on traversing the vector we will set next pointer to the next element to the vector. and hence we
// can generate the required tree.


class Solution {
private:
    unordered_map<int,vector<Node*>> store;
public:
    Node* connect(Node* root) {
        makemap(root,0);
        
        for(auto x: store)
            for(int i=0;i<x.second.size()-1;i++)
                x.second[i]->next=x.second[i+1];
        
        
        return root;
    }
    
    void makemap(Node* root, int depth) {
        if(root==NULL)
            return ;
        
        store[depth].push_back(root);
        makemap(root->left,depth+1);
        makemap(root->right,depth+1);
    }
};

// Time Complexity:-O(N).
// Space Complexity:-O(1).


class Solution {
public:
    Node* connect(Node* root) {
        Node* head=root;
        Node* curr=NULL;
        Node* prev=NULL;
        
        while(head!=NULL) {
            curr=head;
            head=NULL;
            prev=NULL;
            
            while(curr!=NULL) {
                if(curr->left!=NULL) {
                    if(prev!=NULL)
                        prev->next=curr->left;
                    else
                        head=curr->left;
                    prev=curr->left;
                }
                if(curr->right!=NULL) {
                    if(prev!=NULL) 
                        prev->next=curr->right;
                    else
                        head=curr->right;
                    
                    prev=curr->right;
                }
                
                curr=curr->next;
            }
        }
        
        return root;
    }
};