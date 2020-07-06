// https://leetcode.com/problems/elimination-game/description/

// Time Complexity:-O(log(N)).
// Space Complexity:-O(1).

class Solution {
public:
    int lastRemaining(int n) {
        int remaining=n,head=1,step=1;
        bool left=true;
        
        while(remaining>1) {
            if(left || remaining%2==1) 
                head+=step;
            
            remaining/=2;
            step*=2;
            left=!left;
        }
        
        return head;
    }
};