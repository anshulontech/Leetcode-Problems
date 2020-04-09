// https://leetcode.com/problems/word-search-ii/submissions/

struct TrieNode
{
    TrieNode* index[26];
    string s=NULL;
    bool present=false;
    
    TrieNode() : s("") {
        for(int i=0;i<26;i++)
            index[i]=nullptr;
    }
};

void insert(string & ,TrieNode* &);
void search(vector<vector<char>>& ,int ,int ,TrieNode * ,vector<string> & );

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root=new TrieNode();
        vector<string> res;
        for(int i=0;i<words.size();i++)
                insert(words[i],root);
        
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[i].size();j++)
                search(board,i,j,root,res);
        
        return  res;
    }
};

void insert(string & word,TrieNode* &root)
{
    TrieNode *temp=root;
    int i=0;
    
    while(i<word.size()&&temp->index[word[i]-97]!=nullptr)
    {
        temp=temp->index[word[i]-97];
        i++;
    }
    
    while(i<word.size())
    {
        TrieNode* temp2=new TrieNode();
        temp->index[word[i]-97]=temp2;
        temp=temp2;
        i++;
    }
    
    temp->s=word;
    temp->present=true;
    
    return ;
    
}

void search(vector<vector<char>>& board,int i,int j,TrieNode * temp,vector<string> & res)
{
    char ch=board[i][j];
    if(ch=='$'||temp->index[ch-97]==nullptr)
        return;
    
    temp=temp->index[ch-97];
    
    if(temp->present==true)
    {
        temp->present=false;
        res.push_back(temp->s);
    }
    
    board[i][j]='$';
    if(i>0)
        search(board,i-1,j,temp,res);
    if(j>0)
        search(board,i,j-1,temp,res);
    if(i<board.size()-1)
        search(board,i+1,j,temp,res);
    if(j<board[0].size()-1)
        search(board,i,j+1,temp,res);
    
    board[i][j]=ch;
    
    return;
    
}