// https://leetcode.com/problems/ransom-note/

// Time Complexity:-O(M+N).
// Space Complexity:-O(N).
    
// Approach:-
//     We will store the count of each char in a map of string magazine. Now we itterate the ransomNote sring and check that is 
// that character is present in map or not. If it will not than we will return fale as that represents that this character is 
// not present in magazine and hence you will not form ransomNote from magazine. If it will than we will decrease the count as 
// a character from magazine can only be used for single time . At last if condition remains true till last than we will return 
// true as we can make ransomeNote from magazine.

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> store;
        
        for(int i=0;i<magazine.size();i++)
            store[magazine[i]]++;
        
        for(int i=0;i<ransomNote.size();i++)
            if(store[ransomNote[i]]==0)
                return false;
            else
                store[ransomNote[i]]--;
        
        return true;
    }
};