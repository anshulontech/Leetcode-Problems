// https://leetcode.com/problems/longest-valid-parentheses/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     We will scan the tring from the beginning to the end. If the current character is'(' than put it's index inthe string 
// otherwise if the character is ')' than if top index's character is '(' than pop up that otherwise push the index of ')' to 
// the stack .After the scan is done, the stack will only contain the indices of characters which cannot be matched.Then let's 
// use the opposite side - substring between adjacent indices should be valid parentheses. If the stack is empty, the whole 
// inputmstring is valid. Otherwise, we can scan the stack to get longest valid substring

class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size(),longest=0;
        
        stack<int> store;
        
        for(int i=0;i<s.size();i++)
            if(s[i]=='(')
                store.push(i);
            else
                if(!store.empty())
                    if(s[store.top()]=='(')
                        store.pop();
                    else
                        store.push(i);
                else
                    store.push(i);
        
        if(store.empty())
            return n;
        else
        {
            int a=n,b=0;
            while(!store.empty())
            {
                b=store.top();
                store.pop();
                longest=max(longest,a-b-1);
                a=b;
            }
            
            longest=max(longest,a);
        }
        
        return longest;
    }
};