// https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(long int x) {
        if(x<0)
            return 0;
        
        int run=0;
        int y=x;
        while(y>0) {
            run++;
            y=y/10;
        }
        run--;
        while(x>=10) {
            int p=pow(10,run);
            if(x%10!=x/p)
                return 0;
            x=x%p;
            x=x/10;
            run=run-2;
        }
        if(run>0&&x!=0)
            return 0;
        else
            return 1;
    }
};