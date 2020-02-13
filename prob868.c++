// https://leetcode.com/problems/binary-gap/

class Solution {
public:
    int binaryGap(int N) {
        int maxi=INT_MIN;
        int initial=0;
        vector<int> A;
        while(N>0)
        {
            A.push_back(N%2);
            N=N/2;
        }
        for(int i=0;i<A.size();i++)
            if(A[i]==1)
            {
                initial=i;
                break;
            }
        
        for(int i=initial+1;i<A.size();i++)
            if(A[i]==1)
            {
                maxi=max(maxi,i-initial);
                initial=i;
            }
            
        if(maxi!=INT_MIN)
            return maxi;
        else
            return 0;
    }
};