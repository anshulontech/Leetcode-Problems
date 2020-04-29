// https://leetcode.com/problems/reverse-string-ii/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     In every interval of 2*k we will reverse first k elements, for the case when the cursor reaches last interval having 
// less than k items , So to solve that problem we will use min fuction so that if end apperas early than it will go for that 
// one and hence no error would occur.

class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i=0;i<s.size();i+=2*k)
            reverse(s.begin()+i,min(s.begin()+i+k,s.end()));
        
        return s;
    }
};

// Similar Approach But the difference is you do not have to use min function every time.

class Solution {
public:
    string reverseStr(string s, int k) {
        int i=0;
        int n=s.size()-k;
        for(;i<n;i+=2*k)
            reverse(s.begin()+i,s.begin()+i+k);
        
        if((s.begin()+i+k)<s.end())
            reverse(s.begin()+i,s.begin()+i+k);
        else
            reverse(s.begin()+i,s.end());
        
        return s;
    }
};