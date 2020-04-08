// https://leetcode.com/problems/divide-two-integers/

// Time Complexity:-O(N).
// Spaace Complexity:-O(1).
    
// Approach:-
//     As we Know that what is meant by division is that how many times we can substract divisor from dividend.So in this
// problem we are ging to use this concept. Now The idea of Bit manipulation is going to be use here. Now let us suppose 
// dividend = 15 and divisor = 3, 15 - 3 > 0. We now try to subtract more by shifting 3 to the left by 1 bit (6). Since 
// 15 - 6 > 0, shift 6 again to 12. Now 15 - 12 > 0, shift 12 again to 24, which is larger than 15. So we can at most 
// subtract 12 from 15. Since 12 is obtained by shifting 3 to left twice, it is 1 << 2 = 4 times of 3. We add 4 to an answer 
// variable (initialized to be 0). The above process is like 15 = 3 * 4 + 3. We now get part of the quotient (4), with a 
// remaining dividend 3. Then we repeat the above process by subtracting divisor = 3 from the remaining dividend = 3 and 
// obtain 0. We are done. In this case, no shift happens. We simply add 1 << 0 = 1 to the answer variable. Now the end we 
// use to handel is that when divisor =-1 and dividend=INT_MIN than we should return INT_MAX;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1)
            return INT_MAX;
        
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        long dvd= labs (dividend) , div = labs (divisor) ;
        long res = 0;
        
        while ( dvd-div >=0)
        {
            long temp=div , m=1;
            while( temp<<1 <= dvd)
            {
                temp=temp<<1;
                m=m<<1;
            }
            
            dvd-=temp;
            res+=m;
        }
        
        return res*sign;
    }
};