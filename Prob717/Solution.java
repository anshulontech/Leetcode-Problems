// Approach 1:-

class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int pointer=0;
        
        while(pointer< bits.length-1) {
            if(bits[pointer]==1)
                pointer+=2;
            else
                pointer++;
        }
        
        return pointer==(bits.length-1);
    }
}