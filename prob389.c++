// https://leetcode.com/problems/find-the-difference/description/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:- (Using map).
//     In this initially we will store the count of each character of s into hash map and than traverse the string t 
// and if found any character whose count is greater than that in map or is not present in map than in that situation 
// we will return that character.

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> store;
        
        for(int i=0;i<s.size();i++)
            store[s[i]]++;
        
        for(int i=0;i<t.size();i++)
            if(store[t[i]]==0)
                return t[i];
            else
                store[t[i]]--;
        
        return 'a';
    }
};

// Time Complexity:-O(N).
// Space Complexity:-O(1).

// Approach:- 
    // Using bit manipulation.

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        int n = t.size() - 1;

        char c = t[n];

        for (int i = 0; i < n; i++)
        {
            c ^= s[i];
            c ^= t[i];
        }

        return c;
    }
};