// Approach 1:-

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> store;
        
        int n=A.size();
        
        for(int i=0;i<n && store.size()<=2;i++) {
            store[A[i]]++;
            store[B[i]]++;
        }
        
        int change_val,count=0;
        
        for(auto x : store) 
            if(count<x.second)
                change_val=x.first,count=x.second;
        
        int resA=0,resB=0;
        
        for(int i=0;i<n;i++) {
            if(A[i]!=change_val && B[i]!=change_val)
                return -1;
            
            if(A[i]!=change_val)
                resA++;
            else
                if(B[i]!=change_val)
                    resB++;
        }
        
        return min(resA,resB);
    }
};