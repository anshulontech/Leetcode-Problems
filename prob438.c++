// https://leetcode.com/problems/find-all-anagrams-in-a-string/

// Time Complexity:-O(s.length+p.length).
// Space Complexity:-O(p.length).
    
// Approach:-
//     In this first we will store the count of each letter of p in a map. Now we will start to traverse the string s. 
// Till we will found the character of the string in map we will increase our window if at any stage the character is 
// not found the we will decrease the length of our window in this way our window works. Now at any stage if length of 
// window bwecomes equal to p.length than it represents that it is an anagram of p in s and hence we can add the index 
// to result.

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int start=0,end=0;
        int len1=s.size(),len2=p.size();
        unordered_map<char,int> store;
        
        for(int i=0;i<len2;i++)
            store[p[i]]++;
        
        int count=0;
        vector<int> res;
        
        while(end<len1)
        {
            if(store[s[end]]!=0)
            {
                store[s[end]]--;
                end++;
                count++;
            }
            else
            {
                store[s[start]]++;
                start++;
                count--;
            }
            
            if(count==len2)
                res.push_back(start);
        }
        
        return res;
    }
};