// https://leetcode.com/problems/longest-palindromic-substring/

int check(string & ,int ,int );

class Solution {
public:
    string longestPalindrome(string s) {
        string A;
        if(s.size()==0)
            return A;

        for(int i=0;i<s.size()-1;i++)
        {
            int start=0,end=s.size()-1-i;
            while(end<s.size()&&start<=end)
                if(check(s,start,end))
                {
                    A=s.substr(start,end-start+1);
                    return A;
                }
                else
                {
                    start++;
                    end++;
                }
        } 
        
        if(A.empty())
            A=s.substr(0,1);
        return A;
    }
};

int check(string & s,int start,int end)
{
    if(start>=end)
        return 1;
    else
        if(s[start]==s[end])
            return check(s,++start,--end);
        else 
            return 0;
}