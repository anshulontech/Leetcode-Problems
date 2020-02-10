// https://leetcode.com/problems/russian-doll-envelopes/

int longestnondec(vector<int> ,vector<int>);

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.size()==0)
            return 0;
        sort(envelopes.begin(),envelopes.end());
        
        vector<int> A;
        vector<int> B;
        for(int i=0;i<envelopes.size();i++)
            A.push_back(envelopes[i][1]);
        for(int i=0;i<envelopes.size();i++)
            B.push_back(envelopes[i][0]);
        
        int value=longestnondec(A,B);
             
        return value;
    }
};

int longestnondec(vector<int> A,vector<int> C)
{
    vector<int> B;
    for(int i=0;i<A.size();i++)
        B.push_back(1);

    for(int i=1;i<A.size();i++)
    {
        for(int j=0;j<i;j++)
            if(A[i]>A[j]&&C[i]>C[j])
            {
                B[j]++;
                if(B[j]>B[i])
                B[i]=B[j];
                B[j]--;
            }
    }

    int max=-1;
    for(int i=0;i<B.size();i++)
        if(B[i]>max)
            max=B[i];

    return max;
}