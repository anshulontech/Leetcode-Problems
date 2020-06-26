// https://leetcode.com/problems/complex-number-multiplication/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     Here what we are going to do is that we will first store the real and imaginary coefficients of both the string 
// in sepearte variables and than just doing there multiplication in format as that of complex number and than insert 
// them into a string as real and imaginary coefficients.

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int i=0;
        if(a[i]=='-' || a[i]=='+')
            i++;
        
        while(i<a.size() && isdigit(a[i]))
            i++;
        
        int a_first=stoi(a.substr(0,i));
        i++;
        int a_second=stoi(a.substr(i,a.size()-i-1));
        
        i=0;
        if(b[i]=='-' || b[i]=='+')
            i++;
        
        while(i<b.size() && isdigit(b[i]))
            i++;
        
        int b_first=stoi(b.substr(0,i));
        i++;
        int b_second=stoi(b.substr(i,b.size()-i-1));
        
        string res=to_string(a_first*b_first-a_second*b_second);
        res+="+";
        res+=to_string(a_first*b_second +a_second*b_first);
        res+="i";
        
        return res;
    }
};