// https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()==0)
            return true;
        if(t.size()==0)
            return false;
        int j=0;
        int i=0;
        for(;i<s.size()&&j<t.size();i++)
        {
            for(;j<t.size();j++)
                if(t[j]==s[i])
                {
                    j++;
                    break;
                }
            
        }
        if(i==s.size()&&s[i-1]==t[j-1])
            return true;
        else
            return false;
    }
};