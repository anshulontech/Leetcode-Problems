// https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& A) {
        vector<vector<int>> B;
        if(A.size()<3)
            return B;
        sort(A.begin(),A.end());
        
        for(int i=0;i<A.size()-1;i++) 
        {
            int start=i+1,end=A.size()-1;
            int sum=A[i]+A[start]+A[end];
            while(start<end)
            {
                sum=A[i]+A[start]+A[end];
                if(sum<0)
                    start++;
                else
                    if(sum>0)
                        end--;
                    else
                    {
                        B.push_back({A[i],A[start],A[end]});
                        while(start<end&&A[start]==A[start+1]) start++;
                        while(end>start&&A[end]==A[end-1]) end--;
                        
                        start++;
                        end--;
                    }
            }
            while(i<A.size()-1&&A[i]==A[i+1])
                i++;
        }
        return B;
    }
};