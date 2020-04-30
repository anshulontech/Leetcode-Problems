// https://leetcode.com/problems/push-dominoes/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Aproach:-
//     We will start to itterate the loop. If we will encouter with '.' than we will check what is type of next force applied. 
// If it will be towards left and till that poisition from earlier one will make all them to left otherwise leave them it no 
// force will be there or force towards right is there. Similar observations can be done if left and right force are applied 
// and their conditions are applied . So the basic thing is that in this question what we are doing is acting upon the type of 
// force applied.

class Solution {
public:
    string pushDominoes(string s) {
        for(int i=0;i<s.size();i++)
            if(s[i]=='.')
            {
                int temp=checknext(s,i+1);
                if(temp==s.size())
                    i=temp;
                else
                    if(s[temp]=='R')
                        i=temp-1;
                    else
                    {
                        while(i<=temp)
                        {
                            s[i]='L';
                            i++;
                        }
                        i=temp-1;
                    }
            }
            else
                if(s[i]=='L')
                {
                    int temp=checknext(s,i+1);
                    if(temp==s.size())
                        i=temp;
                    else
                        if(s[temp]=='L')
                        {
                            while(i<=temp)
                            {
                                s[i]='L';
                                i++;
                            }
                            i=temp-1;
                        }
                        else
                            i=temp-1;
                }
                else
                {
                    int temp=checknext(s,i+1);
                    if(temp==s.size() || s[temp]=='R')
                    {
                        while(i<temp)
                        {
                            s[i]='R';
                            i++;
                        }
                        i=temp-1;
                    }
                    else
                    {
                        int curr=temp;
                        while(i<temp)
                        {
                            s[i]='R';
                            s[temp]='L';
                            i++;
                            temp--;
                        }
                        
                        i=curr-1;
                    }
                    
                }
        return s;
        
    }
    
    int checknext(string & s,int i)
    {
        while(i<s.size() && s[i]=='.')
            i++;
        
        return i;
    }
};