// https://leetcode.com/problems/remove-k-digits/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     In this the characters are elemenated which have value greater than the next one. This can be done till k is 
// greater than 0 or we will not reach the end of the string. Now if k becomes 0 than we will first remove the first 
// i number from the string and than insert the number from stack to it else we remove top left k numbers from the 
// string and than return it. Also we will check that is starting characters are 0 or not if they were than we will 
// remove these first and then return string.

class Solution {
public:
    string removeKdigits(string num, int k) {
        cout<<num.size();
        stack<char> store;
        int i=0;
        while(i<num.size())
        {
            while(k>0 && !store.empty() && store.top()>num[i])
            {
                store.pop();
                k--;
            }
            
            store.push(num[i]);
            i++;
        }
        
        while(k>0)
        {
            store.pop();
            k--;
        }
        
        num.erase(0,i);
        while(!store.empty())
        {
            num.insert(0,to_string(store.top()-'0'));
            store.pop();
        }
        
        while(num.size()!=0 && num[0]=='0')
            num.erase(0,1);
        
        if(num.size()==0)
            return "0";
        else
            return num;
            
            
            
    }
};