// https://leetcode.com/problems/valid-palindrome-ii/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     We will start to check from the starting and end that is characters are same or not. If they are same we move 1 step 
// ahead from start and take 1 step back from end. Now if the characters are not equal than we will call a funtion ispalindrome 
// which will check that is any of part of (start+1 to end) or (start to end-1) is a pallindrome or not if it will than we 
// return true otherwise return false.

class Solution {
public:
    bool validPalindrome(string s) {
        int start=0,end=s.size()-1;
        
        while(start<end)
            if(s[start]==s[end])
            {
                start++;
                end--;
            }
            else
                return ispalindrome(s,start+1,end) || ispalindrome(s,start,end-1);
                
        return true;
    }
    
    bool ispalindrome(string & s,int start,int end)
    {
        while(start<end)
            if(s[start]==s[end])
            {
                start++;
                end--;
            }
            else
                return false;
        
        return true;
    }
};