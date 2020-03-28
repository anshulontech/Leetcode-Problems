// https://leetcode.com/problems/number-of-matching-subsequences/

// Let words.size()=P & S.size()=Q & words[i].size()=R.
// Compexity
// time complexity =O(Q+P*R).
// space complexity is O(1).
// Procedure:-
// First We store the index of all words of string S in a vector of vector of size 26 at respective index as (S[i]-97).
// Now taking a variable named k and set its value to be -1 and a particular word at index i of words .Than we found upper bound of the k in the A of index words[i].
// If upper bound is equal to size of the A[i] than we return false else set k=index of upper bound.
// If the value goes till last than it represents that this is a subsequece and we incerase ouptut by 1 and at last return output.

bool isSubsequence(string & , vector<vector<int>> &);
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int output=0;
        vector<vector<int>> A(26);
        for(int i=0;i<S.size();i++)
            A[S[i]-97].push_back(i);
        
        for(int i=0;i<words.size();i++)
            if(isSubsequence(words[i],A))
                output++;
        
        return output;
    }
};

bool isSubsequence(string & t, vector<vector<int>> & A) {
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