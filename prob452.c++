// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

// Time Complexity:-O(N*log(N)).
// Space Complexity:-O(log(N)) for sorting.
    
// Approach:-
//     Initially we will sort thr entire array on the basis of second element . Now we are at first balloon , now we 
// think to burst tgis ballon so we will decide to burst it at the end point , so now all the ballons who have their 
// stating point at or before the end point will burst so with one fire these balloons will burst. Now we will go for 
// the next unburst ballon and do the same and so on, so here what we are goung to do is that for balloon we will find 
// all the balloons whose starting point is less or equal to end of thaat and make the in a single club, same thing we 
// will do for the rest of the balloon . Now at last we will calculate the number of clubs which will tell us the 
// minimum nuber of shorts required to burst all the balloons. Here we are not going to store the balloons in a club 
// else we will just the how many balloons will come in a club and just increase by 1 to the number which represents 
// the nuber of shots.

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int res=0;
        
        sort(points.begin(),points.end(),comp);
        
        int i=0;
        
        while(i<points.size()) {
            int j=i;
            while(i<points.size() && points[j][1]>=points[i][0])
                i++;
            
            res++;
        }
        
        return res; 
    }
    
private:
    static bool comp(vector<int>& a , vector<int>& b) {
        return a[1]==b[1] ? a[0]<b[0] : a[1]<b[1];
    }
};