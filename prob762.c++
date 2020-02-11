// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/

int dectobin(int );
int primecheck(int );

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int count=0;
        for(int i=L;i<=R;i++)
        {
            int x=dectobin(i);
            
            if(primecheck(x)==0&&x!=1)
                count++;
        }
        return count;
    }
};


int dectobin(int num)
{
    int count=0;
    vector<int> A;
    while(num>0)
    {
        A.push_back(num%2);
        num=num/2;
    }
    for(int i=0;i<A.size();i++)
        if(A[i]==1)
            count++;
    
    return count;
}

int primecheck(int x)
{
    for(int i=2;i<=sqrt(x);i++)
        if(x%i==0)
            return -1;
    
    return 0;
}
