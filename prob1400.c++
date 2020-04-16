// https://leetcode.com/problems/construct-k-palindrome-strings/submissions/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     If the size of the string s is found to be less than that of k than it is not possible to make k pallindrome hence we 
// will return false in that condition. Otherwise we will first store the count of each character in the map and calculate the 
// number of characters having odd count.  If the number of characters having odd count are less than or equal to k than it is 
// possible to make k pallindrome from the string and hence will return true, otherwise if the number of characters having odd 
// count are greater than k than it is imposssible to perform the operation hence we will return false in that condition.

class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k)
            return false;
        
        unordered_map<char ,int> store;
        int no=0;
        
        for(int i=0;i<s.size();i++)
            store[s[i]]++;
        
        for(auto x : store)
            if(x.second%2!=0)
                no++;
        
        return no<=k;
        
    }
};