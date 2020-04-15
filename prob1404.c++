// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/submissions/

// Time Complexity:-O(N^2).
// Space Coplexity:-O(1).
    
// Approach:-
//     What is our final aim is to make the string s=="1". So to achive this goal what we are going to do is the set of following 
// operations on the behalf of the last character in the string:-

// 1.If last element of the string is '0' than it indicates that the number will be a multiple of 2 hence from the given operations 
// the required one is to divide it with 2. So what happens when it will be divided by 2 in binary representation is that the 0 
// at the end will be kicked out of the string. Hence what we are going to do is to kick out the last zero from the string.

// 2.If the last element is not '0' than it will be definately '1'. So according to given operations what we are going to do is 
// to add 1 to that number. To do so what happens in binary is that { 1+1 =1 carry and 0 assign to that poisition/character}. 
// So we will assign 0 to that character and than search for 0 before that one. If we are able to find that one than we will 
// change that character to 1 and all the characters after this one will be changed into 0. If we are not able to find zero 
// before the last index than we will add 1 at the beginning of the string and all other elements will be changed to 0.

//     At each step we will increase the value of count which stores that how many operations are required to change the number 
// into desired one and was initially assigned to 0.

class Solution {
public:
    int numSteps(string s) {
        int count=0;
        while(s!="1")
        {
            if(s=="0")
                return ++count;
            
            if(s[s.size()-1]=='0')
            {
                s.erase(s.size()-1,1);
                count++;
            }
            else
            {
                s[s.size()-1]='0';
                int i;
                for(i=s.size()-2;i>=0;i--)
                    if(s[i]=='0')
                        break;
                if(i<0)
                {
                    s.insert(0,"1");
                    for(int i=1;i<s.size();i++)
                        s[i]='0';
                    count++;
                }
                else
                {
                    s[i]='1';
                    for(i=i+1;i<s.size();i++)
                        s[i]='0';
                    count++;
                }
            }
        }
        
        return count;
        
    }
};