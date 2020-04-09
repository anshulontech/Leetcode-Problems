// https://leetcode.com/problems/backspace-string-compare/submissions/

// Time COmplexity:-O(N+M).
// Space Complexity:-O(1).
    
// Approach:-
    // We will start to itterate the whole string fom the back side and check that if nay element has '#' as its character 
// or not. If it is than we first remove that element and increase the count value to 1. Than a loop will be executed untill 
// count!=0 and try to elemenate the elements untill count!=0 or the elements of the loop become empty. Similar thing cn be 
// done for the T and at last will check that is S and T are equal or not.

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int count=1;
        for(int i=S.size()-1;i>0;i--)
            if(S[i]=='#')
            {
                S.erase(i,1);
                count=1;
                int temp=i-1;
                while(temp>=0&&count>0)
                    if(S[temp]=='#')
                    {
                        count++;
                        S.erase(temp,1);
                        temp--;
                    }
                    else
                    {
                        S.erase(temp,1);
                        temp--;
                        count--;
                    }
            }
        
        if(S[0]=='#')
            S.erase(0,1);
        
        for(int i=T.size()-1;i>0;i--)
            if(T[i]=='#')
            {
                T.erase(i,1);
                count=1;
                int temp=i-1;
                while(temp>=0&&count>0)
                    if(T[temp]=='#')
                    {
                        count++;
                        T.erase(temp,1);
                        temp--;
                    }
                    else
                    {
                        T.erase(temp,1);
                        temp--;
                        count--;
                    }
            }
        
        if(T[0]=='#')
            T.erase(0,1);
        
        
        if(S==T)
            return true;
        else
            return false;
    }
};