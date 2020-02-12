// https://leetcode.com/problems/maximum-number-of-balloons/

class Solution {
public:
    int maxNumberOfBalloons(string A) {
        sort(A.begin(),A.end());
        int i=0;
        int mini=0;
        int temp=0;
        while(i<A.size()&&A[i]!='a')
            i++;
        while(A[i]=='a')
        {
            i++;
            mini++;
        }
        if(mini==0)
            return 0;
        while(i<A.size()&&A[i]!='b')
            i++;
        while(A[i]=='b')
        {
            i++;
            temp++;
        }
        mini=min(mini,temp);
        temp=0;
        if(mini==0)
            return 0;
        while(i<A.size()&&A[i]!='l')
            i++;
        while(A[i]=='l')
        {
            i++;
            temp++;
        }
        temp=temp/2;
        mini=min(mini,temp);
        temp=0;
        if(mini==0)
            return 0;
        while(i<A.size()&&A[i]!='n')
            i++;
        while(A[i]=='n')
        {
            i++;
            temp++;
        }
        mini=min(mini,temp);
        temp=0;
        if(mini==0)
            return 0;
        while(i<A.size()&&A[i]!='o')
            i++;
        while(A[i]=='o')
        {
            i++;
            temp++;
        }
        temp=temp/2;
        mini=min(mini,temp);
        temp=0;
        
        return mini;
    }
};