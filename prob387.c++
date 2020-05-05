// https://leetcode.com/problems/first-unique-character-in-a-string/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     In an unordered_map we will store the count of each character and the index where it is present . For characters having 
// more than 1 count index would be of last poisition. Now we start to itterate the map and check that is count for char is 1 or 
// not if it was than we will check that is the index corresponding to it is less than previous one or not if it was than we will 
// update the value of index and at last return index value . If the value of index still remain INT_MAX than it represents that 
// their is no character having unique occurance hence we will return false in that condition.

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,pair<int,int>> store;
        for(int i=0;i<s.size();i++)
        {
            store[s[i]].first++;
            store[s[i]].second=i;
        }
        int mini=INT_MAX;
        for(auto x : store)
            if(x.second.first==1)
                mini=min(mini,x.second.second);
        
        if(mini==INT_MAX)
            return -1;
        else
            return mini;
    }
};