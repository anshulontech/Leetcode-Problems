// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& H) {
        if(H.size()==0||H.size()==1)
            return 0;
        int max=INT_MIN;
        for(int i=0;i<H.size()-1;i++)
            for(int j=i+1;j<H.size();j++)
                if((j-i)*min(H[i],H[j])>max)
                    max=(j-i)*min(H[i],H[j]);
                                  
        return max;
    }
};