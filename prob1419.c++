// https://leetcode.com/problems/minimum-number-of-frogs-croaking/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     We will traverse the string and on encounter of each character increase it's corresponding variable's count by 1.If 
// the character is 'c' than it represents the start of croak hence we will increase the value of in_use by 1 which represents 
// the number of frogs active in croaking while if the character is 'k' than decrease the value of in_use . At each step we 
// will check condition 1(in code) such that all letters are in a perfect seqence( of "croak")  and also updating the value of 
// res each timeWith conditio 2(in code) we will check that  if their is any character more or less than this will not 
// represent a perfect case hence return -1 else return res.

class Solution {
public:
    int minNumberOfFrogs(string words) {
        int c=0,r=0,o=0,a=0,k=0,in_use=0,res=0;
        for(char x : words)
        {
            switch(x)
            {
                case 'c':
                    {
                        c++;
                        in_use++;
                        break;
                    }
                case 'r':
                    {
                        r++;
                        break;
                    }
                case 'o':
                    {
                        o++;
                        break;
                    }
                case 'a':
                    {
                        a++;
                        break;
                    }
                case 'k':
                    {
                        k++;
                        in_use--;
                        break;
                    }
            }
            
            res=max(res,in_use);
            if( (c<r) || (r<o) || (o<a) || (a<k) )  //condition 1.
                return -1;
        } 
        
        if(in_use==0 && c==r && r==o && o==a &&a==k )  //condition 2.
            return res;
        
        return -1;
    }
};