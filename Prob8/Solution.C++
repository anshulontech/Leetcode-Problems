// Problem Links:-
// https://leetcode.com/problems/string-to-integer-atoi/

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