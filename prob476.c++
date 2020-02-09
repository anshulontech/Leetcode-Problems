// https://leetcode.com/problems/number-complement/

class Solution {
public:
    int findComplement(int num) {
        if(num==0)
            return 1;
        vector<int> A;
        while(num>0)
        {
            A.push_back(num%2);
            num=num/2;
        }
        
        for(int i=0;i<A.size();i++)
            if(A[i]==0)
                A[i]=1;
            else
                A[i]=0;
        
        for(int i=0;i<A.size();i++)
            num=num+A[i]*pow(2,i);
        
        return num;
    }
};