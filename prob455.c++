// https://leetcode.com/problems/assign-cookies/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int i=0,j=0;
        
        while(j<s.size()&&i<g.size())
        {
            if(s[j]>=g[i])
                i++;
            
            j++;
        }
        
        return i;
            
    }
};