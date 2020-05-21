// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Time Complexity:-O(N^2)
// Space Complexity:-O(1).

// Approach:-
//     For each index we will check for all previous index that is they follow the rule or not and than update answer.


class Solution {
public:
    int lengthOfLongestSubstring(string A) {
        if(A.size()==1)
            return 1;
        if(A.size()==0)
            return 0;
        int max=INT_MIN;
        int prev=0;
        for(int i=1;i<A.size();i++)
        {
            int k=prev;
            while(k<i)
                if(A[i]!=A[k])
                {
                   k++;
                }
                else
                {
                    prev=k+1;
                    break;
                }
            
            if(abs(i-prev+1)>max)
                max=abs(i-prev)+1;
        }
        return max;
    }
};


// Time Complexity:-O(N)
// Space Complexity:-O(N).

// Approach:-
//     In this we are going to store the characters of a particluar window in a map and if the char is found in ap than 
// we are going to decrease the length of the window else we are going to increase the length of the window.
{
    
}


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0,end=0,len=s.size(),res=0;
        
        unordered_set<char> store;
        
        while(end<len)
            if(store.find(s[end])==store.end()) {
                store.insert(s[end]);
                end++;
                res=max(res,end-start);
            }
            else {
                store.erase(store.find(s[start]));
                start++;
            }
        
        return res;
    }
};