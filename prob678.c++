// https://leetcode.com/problems/valid-parenthesis-string/submissions/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     Initially we will run a loop from the starting index and taking '*' as part of the '(' and count them as they increase 
// the count by 1 while ')' will decrease the count by 1. At each stage we will count that if count is less than 0 than string 
// will remain no more valid hence we will return false in that condition. In the last if count==0 that is all '*' when 
// converted into '(' supports the string hence we will return true in that conition. Similar thing should be done while moving 
// from back and takin ')' and '*' in a set. 


class Solution {
public:
    bool checkValidString(string s) {
        if(s.size()==0)
            return true;
        
        int balance=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==')')
                balance--;
            else
                balance++;
            
            if(balance<0)
                return false;
        }
        
        if(balance==0)
            return true;
        
        balance=0;
        
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='(')
                balance--;
            else
                balance++;
            
            if(balance<0)
                return false;
        }
        
        return true;
    }
};