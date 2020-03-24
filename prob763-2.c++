// https://leetcode.com/problems/partition-labels/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> B;
        vector<pair<int,int>> A(26,{-1,-1});
        for(int i=0;i<S.size();i++)
        {
            if(A[S[i]-97].first==-1)
                A[S[i]-97].first=i;
            
            A[S[i]-97].second=i;
        }
        sort(A.begin(),A.end());
        int j=0;
        while(A[j].first==-1)
            j++;
        
        for(int i=j;i<A.size();i++)
        {
            int max=A[i].second;
            int k=i+1;
            for(;k<A.size();k++)
            {
                if(A[k].first>max)
                    break;
                if(A[k].second>max)
                    max=A[k].second;
            }
            
            B.push_back(max+1-A[i].first);
            i=k-1;
        }
        
        return B;
    }
};