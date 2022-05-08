// Link To The Problem:-
// https://leetcode.com/problems/largest-3-same-digit-number-in-string/

// Solution:-

class Solution {
public:
    string largestGoodInteger(string num) {
        string res="";
        int last =-1;
        
        int n=num.size();
        
        for(int i=0;i<n-2;i++)
            if(num[i]==num[i+1] && num[i+1]==num[i+2] && (num[i]-'0')>last) {
                res=num.substr(i,3);
                last=num[i]-'0';
            }
        
        return res;
    }
};