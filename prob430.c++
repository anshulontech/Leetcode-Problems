// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* root=head;
        stack<Node*> store;
        Node* prev=NULL;
        
        while(root || !store.empty()) {
            if(root)
                if(root->child==NULL) {
                    prev=root;
                    root=root->next;
                } 
                else
                    if(root->next==NULL) {
                        root->next=root->child;
                        root->child=NULL;
                        root->next->prev=root;
                        prev=root;
                        root=root->next;
                    }
                    else {
                        Node* temp=root->next;
                        temp->prev=NULL;
                        root->next=root->child;
                        root->child=NULL;
                        root->next->prev=root;
                        prev=root;
                        root=root->next;
                        store.push(temp);
                    }
            else {
                Node* temp=store.top();
                store.pop();
                prev->next=temp;
                temp->prev=prev;
                root=temp;
                prev->child=NULL;
            }
        }
        
        return head;
    }
};

class Solution
{
public:
    Node *flatten(Node *head)
    {
        Node *root = head;

        while (root)
            if (!root->child)
                root = root->next;
            else
            {
                if (root->next)
                {
                    Node *temp = root->child;
                    while (temp->next)
                        temp = temp->next;

                    temp->next = root->next;
                    temp->next->prev = temp;
                    root->next = root->child;
                    root->next->prev = root;
                    root->child = NULL;
                    root = root->next;
                }
                else
                {
                    root->next = root->child;
                    root->child->prev = root;
                    root->child = NULL;
                    root = root->next;
                }
            }

        return head;
    }
};