// https://leetcode.com/problems/group-anagrams/

// Let N be number of words and L be the average length of the words. Than 

// METHOD:-1.
// Time Complexity:-O(N*L*log(L))
// space Complexity:-O(N).
    
// Approach:-
// Initially we will make a unordered map named temp. 
// Now we used to itterate the str and storing the string into a temporary variable named curr and go for its soring .
// After sorting we will check that is the curr was initially present in the map or not. If it was than we will add that
// string str[i] to the map of the key curr else if it was not than we will make a new key named curr and add the string 
// as it's value. After all these we will push back all the string with same key into the same vector and hence will push
// whole map into a vector of vector of string named res and at last will return res giving us final result.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        unordered_map<string,vector<string>> temp;
        for(int i=0;i<str.size();i++)
        {
            string curr=str[i];
            sort(curr.begin(),curr.end());
            
            if(temp.find(curr)==temp.end())
                temp[curr].push_back(str[i]);
            else
                temp[curr].push_back(str[i]);
        }
        
        vector<vector<string>> res;
        
        for(auto x : temp)
            res.push_back(x.second);
        
        
        return res;
    }
};

// METHOD:-2

// Approach:-
// Same as that of above one but the difference is present only when we are sorting the number than for this time it's
// complexity will be O(L).

// Hence Time Complexity:- O(N*L).

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        unordered_map<string,vector<string>> temp;
        for(int i=0;i<str.size();i++)
        {
            string curr=str[i];
            StrSort(curr);
            
            temp[curr].push_back(str[i]);
        }
        
        vector<vector<string>> res;
        
        for(auto x : temp)
            res.push_back(x.second);
        
        
        return res;
    }
    
private:
    void StrSort(string & s)
    {
        char store[26]={0};
        for(int i=0;i<s.size();i++)
            store[s[i]-97]++;
        
        s.clear();
        for(int i=0;i<26;i++)
            s+=string(store[i],i+97);
        
        return ;
    }
};