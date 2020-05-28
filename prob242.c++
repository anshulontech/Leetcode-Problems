// https://leetcode.com/problems/valid-anagram/

// Time Complexity:-O(N*log(N)).
// Space Complexity:-O(1).
    
// Approach:-
//     In this first we will sort both the string and if they are equal than we will freturn true else return false.

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        return s==t;
    }
};

// Time Complexity:-O(N).
// Space Complexity:-O(N).

// Approach:-
//     In this we are storeing the count of each char in a map of string s . Now on traversing the string t if anyone
// char have 0 count in map than it represents that this char does not exist in the s or the count of that char in t
// are greater than count in s hence we will return false. Also we will check initially that is their lemgts are same
// or not if they were not than it represents that they would never be the anagrams hence we will return false.this should
// be check because if they are substring than it the program will return true. Sso to avoid thta confussion we should 
// check this one.



class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        unordered_map<char,int> store;
        
        for(int i=0;i<s.size();i++)
            store[s[i]]++;
        
        for(int i=0;i<t.size();i++)
            if(store[t[i]]==0)
                return false;
            else
                store[t[i]]--;
        
        return true;
    }
};

// Time Complexity:-O(N).
// Space Complexity:-O(1).

// Approach:-
//     I this we are using an array of size 26 and than for each s[i] increase it's respective count in vector and for each
// t[i] decrease it's respective count in vector. Now we will traverse the vector again if at any point count is not 0 than we 
// will return false.

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        vector<int> store(26);

        for (int i = 0; i < s.size(); i++)
        {
            store[s[i] - 'a']++;
            store[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++)
            if (store[i])
                return false;

        return true;
    }
};