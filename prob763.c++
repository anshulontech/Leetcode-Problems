// https://leetcode.com/problems/partition-labels/


int searchfromend(string & S,int index,int end );

class Solution {
public:
    vector<int> partitionLabels(string S) {
        cout<<S.size();
        vector<int> A;
        for(int i=0;i<S.size();i++)
        {
            int end=searchfromend(S,i,i);
            for(int j=i+1;j<end;j++)
                end=searchfromend(S,j,end);
            
            A.push_back(end-i+1);
            i=end;
        }
        
        return A;
    }
};

int searchfromend(string & S,int index,int end )
{
    int i=S.size()-1;
    while(i>end&&S[index]!=S[i])
        i--;
    
    if(i>end)
        end=i;
    
    return end;
}