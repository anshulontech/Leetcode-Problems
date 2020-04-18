// https://leetcode.com/problems/substring-with-concatenation-of-all-words/

// Time Complexity:-O(N^2).
// Space Complexity:-O(N).
    
// Approach:-
//     Initially we will store the count of each word in map. Now we will start to itterate the string s and on going if we 
// will find any part of the words in the string than entered in the if body  and than by performing given operations calling a 
// check function for further words if all the words are find in continues way than we will insert i in the result and make map 
// as that of previous one and go on .

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(words.size()==0||s.size()==0)
            return res;
        int length=words[0].size();
        int words_length=words.size();
        
        if(s.size()+1<length)
            return res;
        
        
        unordered_map<string,int> store;
        for(int i=0;i<words.size();i++)
            store[words[i]]++;
        
        
        for(int i=0;i<s.size()-length*words_length+1;i++)
        {
            string temp=s.substr(i,length);
            if(store[temp]!=0)
            {
                int count=1;
                store[temp]--;
                check(store,s,i+length,count,res,words_length,length);
                store[temp]++;
            }
        }
        return res;
        
    }
    
    void check(unordered_map<string,int> & store,string & s,int i,int count,vector<int> & res,int words_length,int length)
    {
        if(count==words_length)
        {
            res.push_back(i-count*length);
            return;
        }
        
        string temp=s.substr(i,length);
        if(store[temp]!=0)
        {
            store[temp]--;
            check(store,s,i+length,count+1,res,words_length,length);
            store[temp]++;
        }
        
        return ;
    }
};