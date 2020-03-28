// https://leetcode.com/problems/is-subsequence/

// Let s.size()=P,t.size()=Q;
// Time Complexity=O(P+Q).
// Space Complexity=O(1).

// Procedure:-
// First We store the index of all words of string S in a vector of vector of size 26 at respective index as (S[i]-97).
// Now taking a variable named k and set its value to be -1 .Than we found upper bound of the k in the A of index t[i]-97.
// If upper bound is equal to size of the A[t[i]-97] than we return false else set k=index of upper bound.
// If the value goes till last than it represents that this is a subsequece and we incerase ouptut by 1 and at last return output.


class Solution {
public:
    bool isSubsequence(string t, string s) {
        vector<vector<int>> A(26);
        
        for(int i=0;i<s.size();i++)
            A[s[i]-97].push_back(i);
        
        int k=-1;
        
        for(int i=0;i<t.size();i++)
        {
            int index=t[i]-97;
            int temp=upper_bound(A[index].begin(),A[index].end(),k)-A[index].begin();
            if(temp==A[index].size())
                return false;
            else
                k=A[index][temp];
        }
        
        return true;
            
    }
};
