// https://leetcode.com/problems/number-complement/

// Time Complexity:-O(N).
// Space Coplexity:-O(N).  Where N is number of bits.
    
// Approach:-
//     We will first convert number into binary form than taking it's complement by changing 1 to 0 and 0 to 1 and than change 
// the complement form into it's decimal form.

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