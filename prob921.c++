// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

class Solution {
public:
    int minAddToMakeValid(string S) {
        int count=0;
        stack<char> A;
        for(int i=0;i<S.size();i++)
            if(S[i]=='(')
                A.push(S[i]);
            else
                if(A.empty()||A.top()!='(')
                    count++;
                else
                    A.pop();
        
        while(!A.empty())
        {
            count++;
            A.pop();
        }
        
        return count;
    }
};