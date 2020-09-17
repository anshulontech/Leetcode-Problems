// Approach 1:-

class Solution {
    public boolean isRobotBounded(String instructions) {
        int[] dire = new int[4];
        int idx=0;
        int dist=0;
        
        for(int i=0;i<instructions.length();i++) {
            char c=instructions.charAt(i);
            
            if(c=='G') {
                dire[idx]++;
                dist++;
            }
            else 
                if(c=='L') {
                    idx--;
                    idx+=4;
                    idx%=4;
                }
                else {
                    idx++;
                    idx%=4;
                }
        }
        
        return dist==0 || idx!=0 || (dire[0]==dire[2] && dire[0]!=0);
    }
}