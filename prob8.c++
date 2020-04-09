// https://leetcode.com/problems/string-to-integer-atoi/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     On itterating the string first we will overcome all the white spaces which are present their and than go for 
// checking it's sign. After this we will run the loop while the string contains numeric digits and change the string to the 
// integer number . At each step we will check that is the number having max or min limit acived or not. If it was not than 
// we simply just update the number else return INT_MAX or INT_MIN.In the last we will return the base as the final answer.

class Solution {
public:
    int myAtoi(string str) {
        int i=0,base=0;
        while(str[i]==' ')
            i++;
        int sign;
        if(str[i]=='-')
            sign=-1;
        else
            sign=1;
        if(str[i]=='-'||str[i]=='+')
            i++;
        
        while(str[i]>='0'&&str[i]<='9')
        {
            if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) 
			if (sign == 1) 
				return INT_MAX; 
			else
				return INT_MIN; 
                
            base=10*base+(str[i++]-'0');
        }
            
        return base*sign;
    }
};