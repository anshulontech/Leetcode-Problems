// https://leetcode.com/problems/subarray-sums-divisible-by-k/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
    // Initially we will make an array of size K and assign 0 to all its poisition.Now we will run the loop which will 
// upgarde the sum and store that how many times sum hve same remainder when it will divided by the K. After storing the
// above data now a concept runs that if two numbers have same remainder when divisible by K than the substraction of
// these number is always divisible by K. Hence on itterating the array we will count how many such combinations can 
// occur like this and than store these combination value in a variable named total.At last the sums having ramainder 
// 0 can also be included alone in this total as this will also be a pat of the solution ,hence in the last we iclude 
// remaindersum[0] to the total and than return the value which comes.
    
    
    
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        
        int sum=0;
        int remainderstore[K];
        for(int i=0;i<K;i++)
            remainderstore[i]=0;
        for(int i=0;i<A.size();i++)
        {
            sum+=A[i];
            int remainder=sum%K;
            
            if(remainder<0)
                remainder+=K;
            
            remainderstore[remainder]++;
        }
        
        int total=0;
        for(int x : remainderstore)
            if(x>1)
                total+=(x*(x-1))/2;
        
        return total+remainderstore[0];
        
    }
};