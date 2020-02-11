// https://leetcode.com/problems/uncommon-words-from-two-sentences/

void insertvalue(vector<string>& ,vector<int>& ,string& );

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> temp;
        vector<int> temp2;
        vector<string> output;
        
        int initial=0;
        string D;
        
        for(int i=0;i<A.size();i++)
        {
            if(A[i]==' ')
            {
                D.clear();
                D=A.substr(initial,i-initial);
                initial=i+1;
                insertvalue(temp,temp2,D);
            }
            else
                if(i==A.size()-1)
                {
                    D.clear();
                    D=A.substr(initial,i-initial+1);
                    insertvalue(temp,temp2,D);
                }
        }

        initial=0;

        for(int i=0;i<B.size();i++)
        {
            if(B[i]==' ')
            {
                D.clear();
                D=B.substr(initial,i-initial);
                initial=i+1;
                insertvalue(temp,temp2,D);
            }
            else
                if(i==B.size()-1)
                {
                    D.clear();
                    D=B.substr(initial,i-initial+1);
                    insertvalue(temp,temp2,D);
                }
        }
        
        for(int i=0;i<temp2.size();i++)
        if(temp2[i]==1)
            output.push_back(temp[i]);
        
        return output;
    }
};

void insertvalue(vector<string>& temp,vector<int>& temp2,string& D)
{
    for(int i=0;i<temp.size();i++)
        if(temp[i]==D)
        {
            temp2[i]++;
            return ;
        }
    temp.push_back(D);
    temp2.push_back(1);
    return ;
    
}