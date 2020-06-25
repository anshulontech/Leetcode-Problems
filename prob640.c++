// https://leetcode.com/problems/solve-the-equation/

// Time Compleixity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     In this what we are going to do is that we will first calculate the poisition where '=' sign appers and divide 
// the string into 2 halfes called LHS and RHS. Now we will calculate the coefficient of x in LHS and taking their sign 
// as same as given as we have to put the x on LHS similarely we will calculate the coefficient of const term in the LHS 
// but with opposite sign as given. Similar operation is done with RHS but here sign of x is taken to opposite that was 
// given and taking same for constant as given. In last we will check the condition for no solution for infinite solution 
// and for unique solution and return the answer as suitable.

class Solution {
public:
    string solveEquation(string s) {
        int i=0;
        while(i<s.size() && s[i]!='=')
            i++;
        
        int coeff=0, val=0;
        
        int j=0;
        while(j<i && (s[j]=='+' || s[j]=='-'))
            j++;
        
        
        while(j<i) {
            int prev=j;
            int sign;
            if(j==0)
                sign=1;
            else
                if(s[j-1]=='-')
                    sign=-1;
                else
                    sign=1;
            while(j<i && s[j]!='+' && s[j]!='-')
                j++;
            
            string temp=s.substr(prev,j-prev);
            
            if(s[j-1]=='x')
                if(temp.size()==1)
                    coeff+=(1*sign);
                else {
                    temp=temp.substr(0,j-prev-1);
                    coeff+=(stoi(temp))*sign;
                }
            else
                val-=(stoi(temp)*sign);
            j++;
        }
        
        j=i+1;
        
        while(j<s.size() && (s[j]=='+' || s[j]=='-'))
            j++;
        
        while(j<s.size()) {
            int prev=j;
            int sign;
            if(j==i+1)
                sign=1;
            else
                if(s[j-1]=='-')
                    sign=-1;
                else
                    sign=1;
            while(j<s.size() && s[j]!='+' && s[j]!='-')
                j++;
            
            string temp=s.substr(prev,j-prev);
            
            
            if(s[j-1]=='x')
                if(temp.size()==1)
                    coeff-=(1*sign);
                else {
                    temp=temp.substr(0,j-prev-1);
                    coeff-=(stoi(temp))*sign;
                }   
            else
                val+=(stoi(temp))*sign;
            j++;
        }
        
        
        if(coeff==0)
            if(val==0)
                return "Infinite solutions";
            else
                return "No solution";
        
        val/=coeff;
        
        string res="x=";
        
        res+=to_string(val);
        
        return res;
                            
    }
};