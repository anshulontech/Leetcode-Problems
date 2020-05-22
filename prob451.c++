// https://leetcode.com/problems/sort-characters-by-frequency/

// Time Complexity:-O(N*log(N))
// Space Complexity:-O(M). -- M= no. of diff. alphaebats

// Approach:-
//     Initialluy we will store the count of each alphaebat in a map and than transfer that data into an array. Now we 
// will sort the array and itterate the array from the back and insert num times the temp char in the string at the rear 
// end.



class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>> store;
        unordered_map<char,int> count;
        
        for(int i=0;i<s.size();i++)
            count[s[i]]++;
        
        for(auto x: count)
            store.push_back(make_pair(x.second,x.first));
        
        s.clear();
        
        sort(store.begin(),store.end());
        
        for(int i=store.size()-1;i>=0;i--) {
            int num=store[i].first;
            char temp=store[i].second;
            
            while(num) {
                s+=temp;
                num--;
            }
        }
        
        return s;
    }
};