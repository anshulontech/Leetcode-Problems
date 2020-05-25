// https://leetcode.com/problems/uncrossed-lines/


// Time Complexity;-O(N*M).
// Space Complexity:-O(N*M).
    
// Approach:-
//     We are using the same approach as that of longest common subsequence Where we will form a dp table and used to 
// store the count of common elements at the poisition. 
    
//     The first row and first column will remain 0 for the entire movement as they represents that their are 0 elements 
// common in "" string and any other string. Now we will start to traverse from (1,1) poisition setting i=1 and j=1, now 
// if i and j th reprsenting numbers are same than it repreents that they can make the pair so we will join them by 
// increasing the counter of store[i-1][j-1] by 1 and setting it to store[i][j]. Now what if they are not same than 
// we will check that is counter will greater for substring from top or from left that is continum=inig from 2nd list 
// or from 1st list respectively and than set the value according to that. At last the store[A.size()][B.size()] 
// reprsents the max number of elements in the list.

class Solution
{
public:
    int maxUncrossedLines(vector<int> &A, vector<int> &B)
    {
        int n = A.size(), m = B.size();
        vector<vector<int>> store(n + 1, vector<int>(m + 1));

        for (int i = 1; i < n + 1; i++)
            for (int j = 1; j < m + 1; j++)
                if (A[i - 1] == B[j - 1])
                    store[i][j] = store[i - 1][j - 1] + 1;
                else
                    store[i][j] = max(store[i - 1][j], store[i][j - 1]);

        return store[n][m];
    }
};

// Time Complexity;-O(N*M).
// Space Complexity:-O(M).

// Approach:-
//     Same As that of above one but here we are making only two rows as we need only the current row and the previous one.
// Not rows before the previous one .

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int n=A.size(),m=B.size();
        vector<vector<int>> store(2,vector<int> (m+1));
        
        for(int i=1;i<n+1;i++)
            for(int j=1;j<m+1;j++)
                if(A[i-1]==B[j-1])
                    store[i%2][j]=store[(i-1)%2][j-1]+1;
                else
                    store[i%2][j]=max(store[(i-1)%2][j],store[i%2][j-1]);
        
        return store[n%2][m];
    }
};