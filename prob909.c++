// https://leetcode.com/problems/snakes-and-ladders/description/

// Time Complexity:-O(N*M).
// Space Complexity:-O(N*M).
    
// Approach:-
//     Use BFS.

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int N=board.size();
        
        unordered_map<int,int> dist;
        dist.insert(make_pair(1,0));
        
        queue<int> helper;
        helper.push(1);
        
        while(!helper.empty()) {
            int s=helper.front();
            helper.pop();
            if(s==N*N)
                return dist[s];
            
            for(int s2=s+1;s2<=min(s+6,N*N);s2++) {
                int rc=get(s2,N);
                int r=rc/N,c=rc%N;
                int s2Final=board[r][c] ==-1 ? s2 : board[r][c];
                
                if(!dist.count(s2Final)) {
                    dist.insert(make_pair(s2Final,dist[s]+1));
                    helper.push(s2Final);
                }
            }
        }
        
        return -1;
    }
    
private:    
    int get(int s ,int N) {
        int quot=(s-1)/N;
        int rem=(s-1)%N;
        
        int row=N-1-quot;
        int col=(row%2)!=(N%2)? rem : N-1-rem;
        
        return row*N+col;
    }
};