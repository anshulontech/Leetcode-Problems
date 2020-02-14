// https://leetcode.com/problems/goat-latin/

class Solution {
public:
    string toGoatLatin(string S)
{
    int initial=0;
    while(S[initial]==' ')
    {
        S.erase(initial,1);
    }
    while(S[S.size()-1]==' ')
    {
        S.erase(S.size()-1,1);
    }
    
    
    int i;
    int run=1;
    string ch;
    while(initial<S.size())
    {
        for(i=initial;i<S.size()&&S[i]!=' ';i++)
        {}
        if(S[initial]!='a'&&S[initial]!='e'&&S[initial]!='i'&&S[initial]!='o'&&S[initial]!='u'&&S[initial]!='A'&&S[initial]!='E'&&S[initial]!='I'&&S[initial]!='O'&&S[initial]!='U')
        {
            ch=S[initial];
            S.erase(initial,1);
            S.insert(i-1,ch);
            S.insert(i,"ma");
            for(int j=0;j<run;j++)
            S.insert(i+1,"a");
            initial=i+2+run; 
            run++;
        }
        else 
                {
                    S.insert(i,"ma");
                    for(int j=0;j<run;j++)
                    S.insert(i+1,"a");
                    initial=i+2+run; 
                    run++;
                }
        initial++;
    }
        
    return S;
}
};