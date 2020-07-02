// https://leetcode.com/problems/smallest-range-ii/description/

// Time Complexity:-O(N*log(N)).
// Space Complexity:-O(1).

class Solution {
public:
    int smallestRangeII(vector<int>& A, int k) {
        int N=A.size();
        
        sort(A.begin(),A.end());
        
        int ans=A[N-1]-A[0];
        
        for(int i=0;i<N-1;i++) {
            int a=A[i],b=A[i+1];
            
            int high=max(A[N-1]-k,a+k);
            int low=min(A[0]+k,b-k);
            
            ans=min(ans,high-low);
        }
        
        return ans;
    }
};