// https://leetcode.com/problems/longest-happy-prefix/

vector<int> lps(string );

class Solution {
public:
    string longestPrefix(string s) {
        vector<int> A=lps(s);
        
        return s.substr(0,A.back());
    }
};

vector<int> lps(string s)
{
    vector<int> A(s.size(),0);
    int index=0;
    for(int i=1;i<s.size();)
        if(s[i]==s[index])
        {
            index++;
            A[i]=index;
            i++;
        }
        else
            if(index!=0)
                index=A[index-1];
            else
                i++;
    
    return A;
}