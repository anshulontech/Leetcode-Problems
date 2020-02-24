// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string A) {
        if(A.size()==1)
            return 1;
        if(A.size()==0)
            return 0;
        int max=INT_MIN;
        int prev=0;
        for(int i=1;i<A.size();i++)
        {
            int k=prev;
            while(k<i)
                if(A[i]!=A[k])
                {
                   k++;
                }
                else
                {
                    prev=k+1;
                    break;
                }
            
            if(abs(i-prev+1)>max)
                max=abs(i-prev)+1;
        }
        return max;
    }
};