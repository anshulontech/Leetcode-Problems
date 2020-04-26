// https://leetcode.com/problems/longest-common-subsequence/

// Time Complexity:-O(N*M).
// Space Complexity:-O(N*M).
    
// Approach:-
//     Here what we are going to do is to break the problem into subproblems using dp table.
// Hint:-
//     https://www.youtube.com/watch?v=ASoaQq66foQ

class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        vector<vector<int>> store(a.size()+1,vector<int>(b.size()+1));
        
        for(int i=1;i<a.size()+1;i++)
            for(int j=1;j<b.size()+1;j++)
                if(a[i-1]==b[j-1])
                    store[i][j]=1+store[i-1][j-1];
                else
                    store[i][j]=max(store[i-1][j],store[i][j-1]);
        
        return store[a.size()][b.size()];
    }
};

// Approach 2:-
//     Same as earlier but using lesser memory as we need only two rows to manipulate.

class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        vector<vector<int>> store(2,vector<int>(b.size()+1));
        
        for(int i=1;i<a.size()+1;i++)
            for(int j=1;j<b.size()+1;j++)
                if(a[i-1]==b[j-1])
                    store[i%2][j]=store[(i-1)%2][j-1]+1;
                else
                    store[i%2][j]=max(store[i%2][j-1],store[(i-1)%2][j]);
        
        return store[a.size()%2][b.size()];
    }
};