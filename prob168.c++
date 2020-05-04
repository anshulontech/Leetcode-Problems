// https://leetcode.com/problems/excel-sheet-column-title/

// Time Complexity:-O(N/26).
// Space Complexity:-O(1).

// Approach:-
//     Same approach as what we are doing while converting int into a string that is take remainder of first by 10 than by 100 
// and also dividing at same time and adding to string . Here all these are operations are done on the base of 26 . 
    
    
class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while(n)
        {
            n--;
            char temp='A'+n%26;
            n=n/26;
            s=temp+s;
        }
        
        return s;
    }
};