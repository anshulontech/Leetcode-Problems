// https://leetcode.com/problems/find-duplicate-file-in-system/description/

// Time Complexity:-O(N).
// Space Complexity:-o(N).
    
// Approach:-
//     In this what we are going to do is that we will store the path of each filename in a hash map hence we can say 
// that in hash map the key is filename and the value is vector of string which represents the path of the file. After 
// storing this what we will do is that we will traverse the map and if any key has more than one element in the map 
// than we will add that one to the store and hence at last we are with result in our hand.

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> files;
        vector<vector<string>> res;
        
        for(auto path:paths) {
            stringstream ss(path);
            string root;
            string s;
            getline(ss,root,' ');
            
            while(getline(ss,s,' ')) {
                string fileName = root +'/'+s.substr(0,s.find('('));
                string fileContent = s.substr(s.find('(')+1,s.find(')')-s.find('(')-1);
                files[fileContent].push_back(fileName);
            }
        }
        
        for(auto file:files) 
            if(file.second.size()>1)
                res.push_back(file.second);
        
        return res;
    }
};