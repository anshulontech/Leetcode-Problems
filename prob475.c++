// https://leetcode.com/problems/heaters/description/

// Time Compleixty:-O(N*log(N)+N*log(M)).
// Space Complexity:-O(1).
    
// Approach:-
//     In this what we are going to do is that we will find the least dist of a house from the heater in left or right 
// and than check that is this dist id greater than the previous dist or not, if it is than we will update the max dist 
// to curr dist else just move forward.

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end()) ;
        
        int res = 0 ;
        
        for( int house : houses ) {
            auto index=lower_bound(heaters.begin(), heaters.end(), house)-heaters.begin();
            int dist;
            if(index>0 && index<heaters.size())
                dist=min(house-heaters[index-1],heaters[index]-house);
            else
                if(index==0) 
                    dist=heaters[index]-house;
                else
                    dist=house-heaters[index-1];
            
            res=max(res,dist);
            
        }
        
        return res;
    }
};