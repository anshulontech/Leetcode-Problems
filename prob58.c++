// https://leetcode.com/problems/length-of-last-word/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     First we will reach at that point from last which is not a white space and after this we will find the first 
// white space character to the left of it and calculate the length from there.

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.size()-1;
        
        while(i>=0 && s[i]==' ')
            i--;
        
        int end=i;
        
        while(i>=0 && isalpha(s[i]))
            i--;
        
        return end-i;
    }
};