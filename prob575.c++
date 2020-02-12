// https://leetcode.com/problems/distribute-candies/

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        vector<int> sis;
        int i;
        sort(candies.begin(),candies.end());
        
        for(i=1;i<candies.size();i++)
            if(candies[i]!=candies[i-1])
                sis.push_back(candies[i-1]);
        
        sis.push_back(candies[i-1]);
        
        if(sis.size()<=candies.size()/2)
            return sis.size();
        else
            return candies.size()/2;
    }
};

