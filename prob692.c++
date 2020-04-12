// https://leetcode.com/problems/top-k-frequent-words/submissions/

// Time Complexity:-O(3*N).
// Space Complexity:-O(N).
    
// Approach:-
//     Initialy we will store the count of each element in the map. After this we will make a vector of vector of string 
// where we will store the string at the index of their count that is their count repreents the index in bucket vector.After 
// this we will run a loop from last and than store first k elements in res vector and this represents the final answer.
    
// NOTE:- For alphabetical order of the words having same count the map will store them in alphabatical order directly , 
// so their is no need to do for this.

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> store;
        
        for(auto & w : words)
            ++store[w];
        
        vector<vector<string>> bucket(words.size());
        
        for(auto it : store)
            bucket[it.second].push_back(it.first);
        
        vector<string> res;
        
        for(int i=(int)bucket.size()-1;k>0&&i>=0;i--)
        {
            if(bucket[i].empty())
                continue;
            
            int n=min(k,(int)bucket[i].size());
            res.insert(res.end(),bucket[i].begin(),bucket[i].begin()+n);
            k-=n;
        }
        
        return res;
    }
};