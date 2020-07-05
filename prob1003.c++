// https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/description/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     In this we are using a stack to operate the string, in this what we are doing is that we will insert the element 
// in the stack if the character is not 'c' but if the character is 'c' than we will check that is the last two elements 
// are 'b' and 'a' respectively, if they were than we will remove these characters from the stack and move for the next 
// character, but if they are not then we will just insert the current character to stack and move for next one.

class Solution {
public:
    bool isValid(string s) {
        stack<char> store;
        
        for(int i=0;i<s.size();i++)
            if(s[i]!='c')
                store.push(s[i]);
            else
                if(!store.empty() && store.top()=='b') {
                    store.pop();
                    if(!store.empty() && store.top()=='a')
                        store.pop();
                    else {
                        store.push('b');
                        store.push('c');
                    }
                }
                else
                    store.push('c');
        
        return store.empty();
    }
};

// Faster than upper one because if the previous elements of c are not b and a respectively than they will never form 
// valid string hence we will return false at that time and there is no need to traverse the string further.

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> store;

        for (int i = 0; i < s.size(); i++)
            if (s[i] != 'c')
                store.push(s[i]);
            else if (!store.empty() && store.top() == 'b')
            {
                store.pop();
                if (!store.empty() && store.top() == 'a')
                    store.pop();
                else
                    return false;
            }
            else
                return false;

        return store.empty();
    }
};