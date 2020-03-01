// https://leetcode.com/problems/zigzag-conversion/

class Solution {
public:
    string convert(string s, int row) {
        if(row==1||row==0)
            return s;
        vector<vector<string>> A(row);
        int k=0,run=1;;
        for(int i=0;i<s.size();i++)
        {
            A[k].push_back(s.substr(i,1));
            if(run%2==1)
                if(k==row-1)
                {
                    run=2;
                    k--;
                }
                else
                    k++;
            else if(run%2==0)
                if(k==0)
                {
                    run=1;
                    k++;
                }
                else
                    k--;
        }
        
        s.clear();
        
        
        for(int i=0;i<A.size();i++)
            for(int j=0;j<A[i].size();j++)
                s.insert(s.size(),A[i][j]);
        
        return s;
    }
};