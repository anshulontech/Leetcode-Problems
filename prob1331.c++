// https://leetcode.com/problems/rank-transform-of-an-array/

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> B(arr.size(),0);
        
        if(arr.size()==0)
            return B;
        if(arr.size()==1)
            {
                B[0]=1;
                return B;
            }
        
        vector<pair<int,int>> A;
        for(int i=0;i<arr.size();i++)
            A.push_back(make_pair(arr[i],i));
        
        sort(A.begin(),A.end());
        
        int k=1;
        int i;
        for(i=0;i<A.size()-1;i++)
            {
                B[A[i].second]=k;
                k++;
                if(A[i].first==A[i+1].first)
                    k--;
            }
        if(A[i].first==A[i-1].first)
            B[A[i].second]=k;
        else
            B[A[i].second]=k;
        
        return B;
    }
};