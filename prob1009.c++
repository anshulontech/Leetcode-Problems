// https://leetcode.com/problems/complement-of-base-10-integer/

class Solution {
public:
    int bitwiseComplement(int N) {
        if(N==0)
            return 1;
        vector<int> A;
        while(N>0)
        {
            A.push_back(!(N%2));
            N=N/2;
        }
        
        for(int i=0;i<A.size();i++)
        {
            N=N+A[i]*pow(2,i);
        }
        
        return N;
    }
};