// https://leetcode.com/problems/reverse-string/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     In this we are setting two pointers one from start and one from end and swapping their elements till start will 
// not become greateror equal to end using swap function.

class Solution {
public:
    void reverseString(vector<char>& s) {
        int start=0,end=s.size()-1;
        
        while(start<end) {
            swap(s[start],s[end]);
            start++;
            end--;
        }
        
        return;
    }
};