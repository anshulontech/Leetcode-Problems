// https://leetcode.com/problems/reverse-only-letters/description/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     Using two pointer approach. One pointer is set to 0th index and one to last if both the letters represented by 
// these pointers are alphabet than we will swap them and incresae start pointer and decrease end pointer, but if they 
// are not than if letter represented by start is not alphabet than we will just increase start pointer lese decrease 
// end pointer. At last we will return that string as we have made changes to that string and not use other string to 
// store result.

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int start=0,end=s.size()-1;
        
        while(start<end)
            if(!isalpha(s[start]))
                start++;
            else
                if(!isalpha(s[end]))
                    end--;
                else {
                    swap(s[start],s[end]);
                    start++;
                    end--;
                }
                   
        return s;
    }
};