// https://leetcode.com/problems/word-search/

bool nearsearch(vector<vector<char>>& , string ,int ,int ,int ,vector<pair<int,int>>&);

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        vector<pair<int,int>> A;
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[i].size();j++)
                if(board[i][j]==word[0])
                {
                    A.push_back({i,j});
                    if(nearsearch(board,word,i,j,1,A))
                        return true;
                    
                    A.pop_back();
                }
                    
        
        return false;
    }
};

bool nearsearch(vector<vector<char>>& board, string word,int i,int j,int index,vector<pair<int,int>> &A)
{
    if(index>=word.size())
        return true;
    else
    {
        if((i-1)>=0&&board[i-1][j]==word[index])
        {
            int flag=0;
            for(int k=0;k<A.size();k++)
                if(A[k].first==i-1&&A[k].second==j)
                {
                    flag=1;
                    break;
                }
            if(flag==0)
            {
                A.push_back({i-1,j});
                if(nearsearch(board,word,i-1,j,index+1,A))
                    return true;
                A.pop_back();
            }
        }
        if((i+1)<board.size()&&board[i+1][j]==word[index])
        {
            int flag=0;
            for(int k=0;k<A.size();k++)
                if(A[k].first==i+1&&A[k].second==j)
                {
                    flag=1;
                    break;
                }
            if(flag==0)
            {
                A.push_back({i+1,j});
                if(nearsearch(board,word,i+1,j,index+1,A))
                    return true;
                A.pop_back();
            }
        }
        if((j-1)>=0&&board[i][j-1]==word[index])
        {
            int flag=0;
            for(int k=0;k<A.size();k++)
                if(A[k].first==i&&A[k].second==j-1)
                {
                    flag=1;
                    break;
                }
            if(flag==0)
            {
                A.push_back({i,j-1});
                if(nearsearch(board,word,i,j-1,index+1,A))
                    return true;
                A.pop_back();
            }
        }
        if((j+1)<board[i].size()&&board[i][j+1]==word[index])
        {
            int flag=0;
            for(int k=0;k<A.size();k++)
                if(A[k].first==i&&A[k].second==j+1)
                {
                    flag=1;
                    break;
                }
            if(flag==0)
            {
                A.push_back({i,j+1});
                if(nearsearch(board,word,i,j+1,index+1,A))
                    return true;
                A.pop_back();
            }
        }
    }
    
    
    return false;
}