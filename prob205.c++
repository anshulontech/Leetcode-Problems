// https://leetcode.com/problems/isomorphic-strings/

// Time Complexity:-O(2*n).
// Space Complexity:-O(2*n).
    
// Approach:-
//     We will store the index of each char in a map for each string in different map. Now we will start to traverse 
// the map and check that if the corresponding char index vector are different than we will return false as it represents 
// that they both will become different as we will change them So we will return false else if both are not different 
// for all char pairs than we will return true as it represents that they can be changed.

class Solution
{
private:
    unordered_map<char, vector<int>> store1;
    unordered_map<char, vector<int>> store2;

public:
    bool isIsomorphic(string s, string t)
    {
        for (int i = 0; i < s.size(); i++)
            store1[s[i]].push_back(i), store2[t[i]].push_back(i);

        for (int i = 0; i < s.size(); i++)
            if (store1[s[i]] != store2[t[i]])
                return false;

        return true;
    }
};


// Time Complexity:-O(N).
// Space Complexity:-O(2*N).

// Approach:-
//     In this what we are going to do is that we will store the replacement of each string in a map and on encounter 
// with previousely occured character if the current replacement is same than we will move ahead else we will return 
// false.And this should be check for both the strings hence it is required to make two different strings.

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> interChange1;
        unordered_map<char, char> interChange2;
        for (int i = 0; i < s.size(); i++)
        {
            if (interChange1.find(s[i]) == interChange1.end())
                interChange1[s[i]] = t[i];
            else if (interChange1[s[i]] != t[i])
                return false;

            if (interChange2.find(t[i]) == interChange2.end())
                interChange2[t[i]] = s[i];
            else if (interChange2[t[i]] != s[i])
                return false;
        }

        return true;
    }
};