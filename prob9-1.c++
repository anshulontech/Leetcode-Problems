// https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> A;
        if(x<0)
            return 0;
        else {
            while(x>0) {
                A.push_back(x%10);
                x=x/10;
            }
        }
        
        for(int i=0;i<A.size()/2;i++)
            if(A[i]!=A[A.size()-1-i])
                return 0;
        
        return 1;
    }
};