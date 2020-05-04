// https://leetcode.com/problems/excel-sheet-column-number/

// Time Complexity:-O(N).
// Space Complexity:-O(1).

// Approach:-
//     By observation it was clear that the number to which an alphaebat represents depands upon the poisition from last and 
// what value it contains. Like decimal form this problem can be solved. Let us assume that we are given a string of characters 
// having values between 0 and 9 and we have to change it into integer form. So to solve this what we are doing is to first 
// multiply last digit by 10^0 and previous by 10^1 than it's previous by 10^2 and so on. Similarely In this problem we are 
// changing the string into alphabatical form which has a base of 26. So in this what we are going to do is that multiply last 
// one by 26^0 than preious one by 26^1 than it's previous one by 26^2 and so on and hence on last the result obtain will be 
// final answer. 
    
class Solution {
public:
    int titleToNumber(string s) {
        int count=0;
        int n=s.size();
        for(int i=0;i<n;i++)
            count+=pow(26,i)*(s[n-i-1]-'A'+1);
        
        return count;
    }
};