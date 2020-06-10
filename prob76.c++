// https://leetcode.com/problems/minimum-window-substring/

// Time Complexity:-O(N+M).
// Space Complexity:-O(N+M).
    

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> store;
        
        for(int i=0;i<t.size();i++)
            store[t[i]]++;
        
        int len=INT_MAX;
        int start=0,end=0;
        int counter=store.size();
        string res="";
        
        while(end<s.size()) {
            if(store.find(s[end])!=store.end()) {
                store[s[end]]--;
                if(store[s[end]]==0)
                    counter--;
            }
            
            end++;
            
            while(counter==0) {
                if(end-start < len) {
                    len=end-start;
                    res=s.substr(start,end-start);
                }
                
                if(store.count(s[start])==1) {
                    store[s[start]]++;
                    if(store[s[start]]>0)
                        counter++;
                }
                
                start++;
            }
        }
        
        return res;
    }
};