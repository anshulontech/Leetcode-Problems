// https://leetcode.com/problems/most-common-word/submissions/

// Time Complexity:-O(N).
// Space Coplexity:-O(N).
    
// Approach:-
//     Initially we will make a map and on manipulation on string store the count of words in the map using word as key.
    
// Manipulations to store word:-
//     We will start to traverse the string fro the begineening. for each start of the loop we will makae a empty string s. 
// Now from that index till we will not rezh an no alphabatical number we will push the alphabat to the string in lowercase 
// letter and form a word. After this we will  search for the next alphabatical word and as we reach there we will leave it 
// and than add the string to map if it was not there or if it was than update its count by 1.
        
//     After all these we will first remove the baanned words from the map and than traverse the map and find that which word 
// comes maximum times and than return that word.
        

class Solution {
public:
    string mostCommonWord(string para, vector<string>& banned) {
        unordered_map<string,int> store;
        
        for(int i=0;i<para.size();)
        {
            string s="";
            while(i<para.size()&&isalpha(para[i]))
                s.push_back(tolower(para[i++]));
            while(i<para.size()&&!isalpha(para[i]))
                i++;
            
            store[s]++;
        }
        
        for(auto x : banned )
            store[x]=0;
        
        string res="";
        
        int count=0;
        for(auto x: store)
            if(x.second>count)
            {
                res=x.first;
                count=x.second;
            }
        
        return res;
    } 
};