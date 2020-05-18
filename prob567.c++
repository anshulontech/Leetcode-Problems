// https://leetcode.com/problems/permutation-in-string/

// Time Complexity:-O(s1.length+s2.length)
// Space Complexity:-O(s1.length).
    
// Approach:-
//     In this what we are trying to do is that first we will store the count of each char in a map of string 1. Now 
// we will start to traverse the s2 string and trying to make windoe in the s2 string , At time when the size of window 
// will become equal to we will return true. 
        
// How does window works:-
//     Window will expand it using with the end pointer . If the end pointer representing character is still in map than 
// it will expand it otherwise till thee value is not in map it will make window shorter and shorter by increasing the 
// start pointer.

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> store;
        
        for(int i=0;i<s1.size();i++)
            store[s1[i]]++;
        
        int start=0,end=0;
        
        int len=s1.size();
        int count=0;
        
        while(end<s2.size())
        {
            if(store[s2[end]]!=0)
            {
                store[s2[end]]--;
                count++;
                end++;
            }
            else
            {
                store[s2[start]]++;
                count--;
                start++;
            }
            
            if(count==len)
                return true;
        }
        
        return false;
        
    }
};