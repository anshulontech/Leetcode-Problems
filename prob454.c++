// https://leetcode.com/problems/4sum-ii/

// Time Complexity:-O(N^2).
// Space Complexity:-O(N^2).

// Approach:-
//     We will use the property that A+B+C+D=0 can be written as A+B=-(C+D). So we will first calculate the sum of all 
// combiantions in A and B vector and store their sum in a map with their count. After this we will find all combinaations 
// from C and D and if any sum found with -ve value in map then we will increase our count with the sum count and return 
// answer.
    
    
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> store;
        
        int N=A.size();
        int res=0;
        
        for(int i=0;i<N;i++) 
            for(int j=0;j<N;j++)
                store[A[i]+B[j]]++;
        
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                res+=store[-(C[i]+D[j])];
        
        return res;
    }
};