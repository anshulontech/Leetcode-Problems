// Link To Problem:-
// https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/

// Solution:-

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string,int> map;
        
        int res=0;
        
        for(auto x:nums) map[x]++;
        
        for(auto x:nums) {
            if(x.size()>=target.size() || !isPrefix(target,x)) continue;
            
            string temp=target.substr(x.size(),target.size()-x.size());
            
            res+=map[temp];
            if(temp==x) res--;
        }
        
        return res;
    }
    
    bool isPrefix(string& txt,string& patt) {
        int i=0;
        
        while(i<patt.size())
            if(txt[i]!=patt[i]) return false;
            else i++;
        
        return true;
    }
};