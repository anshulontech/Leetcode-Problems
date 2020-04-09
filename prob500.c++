// https://leetcode.com/problems/keyboard-row/

// Assumption:- Size of words is N and avg length of words[i] be l than:-
    
// Time Complexity:-O(N*l).
// Space Complexity:-O(1).

// Approach:-
    // Initially we will make a vector of size 26 and than at the respective places of the integers of the keyboard we 
// will asssign values to them. Now we will start to itterate the vector words and will check if any any of these words[i] 
// is empty or not if it will be empty than this will be a part of the solution. If the word is not empty than with first 
// element we will check the index of the first letter in keyboard and than start to check for all words if at ny poisition 
// it will be different than we will assign temp with -1 nd beak the loop, else if its not than push the word to the output 
// and at last return the output as final result.

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        
        vector<string> output;
        vector<int> store(26);
        vector<string> rows = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
        
        for(int i=0;i<rows.size();i++)
            for(int j=0;j<rows[i].size();j++)
                store[toupper(rows[i][j])-65]=i+1;
        
        for(int i=0;i<words.size();i++)
        {
            if(words[i].size()==0)
                {
                    output.push_back(words[i]);
                    continue;
                }
            int temp=store[toupper(words[i][0])-65];
            
            for(int j=1;j<words[i].size();j++)
                if(store[toupper(words[i][j])-65]!=temp)
                {
                    temp=-1;
                    break;
                }
            
            if(temp!=-1)
                output.push_back(words[i]);
        }
        
        return output;
    }
};