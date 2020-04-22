// https://leetcode.com/problems/linked-list-in-binary-tree/

// Method 1:-

// Time Complexity:-O(N^2).
// Space Complexity:-O(1).
    
// Apprach:-
//     For each node using check function we will check that is th linked list was found their or not , if it was than we return 
// true else check for the left node and than for right node using recurssion.


class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root==NULL)
            return false;
        
        return check(head,root) || isSubPath(head,root->left) || isSubPath(head,root->right);
    }
    
    bool check(ListNode* head, TreeNode* root)
    {
        if(head==NULL)
            return true;
        
        if(root==NULL)
            return false;
        
        if(head->val==root->val)
            return check(head->next,root->left) || check(head->next,root->right);
        else
            return false;
    }
};

// Time Complexity:-O(N).
// Space Complexity:-O(M).

// Method 2:-
//     In this problem we wre going to use the concept of KMP algorithm. As kmp works on array hence firt we will convert our 
// linked list to array. Now by using makelps function we will make the lps of the the list.After this we are going to traverse 
// the tree and on encounter with each node we will check that is the list element corresponding to j element matches the root
// val or not if it will than we will go for search for the next element in the adjacent child nodes and continue till no matche
// or end occur. In case of no match we will go for lps array which we help us to go back to subpattern present before.




class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<int> list;
        ListNode * temp=head;
        while(temp)
        {
            list.push_back(temp->val);
            temp=temp->next;
        }
        
        vector<int> lps(list.size());
        
        makelps(list,lps);
        
        return search(root,list,lps,0);
    }
    
    void makelps(vector<int> &list, vector<int> & lps)
    {
        for(int i=1,j=0;i<list.size();i++)
        {
            while(j>0 && list[i]!=list[j])
                j=lps[j-1];
            
            if(list[i]==list[j])
                lps[i]=++j;
        }
    }
    
    bool search(TreeNode * root, vector<int> & list,vector<int> & lps, int j)
    {
        if(j==list.size())
            return true;
        if(root==NULL)
            return false;
        
        while(j>0 && root->val!=list[j])
            j=lps[j-1];
        
        if(root->val==list[j])
            j++;
        
        return search(root->left,list,lps,j) || search(root->right,list,lps,j);
    }
    
};