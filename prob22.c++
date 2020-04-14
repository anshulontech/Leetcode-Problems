// https://leetcode.com/problems/generate-parentheses/

// Hint:-
    // https://www.youtube.com/watch?v=qBbZ3tS0McI
    // https://www.youtube.com/watch?v=sz1qaKt0KGQ

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> store;
        backtrack(store,"",0,0,n);
        return store;
    }
    
    void backtrack(vector<string> & store,string s,int open,int close,int max)
    {
        if(s.size()==max*2)
        {
            store.push_back(s);
            return;
        }
        
        if(open<max)
            backtrack(store,s+"(",open+1,close,max);
        if(close<open)
            backtrack(store,s+")",open,close+1,max);
        
        return;
    }
};