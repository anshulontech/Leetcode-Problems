// https://leetcode.com/problems/longest-repeating-character-replacement/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     We are going to use a window here , and taking the help of a vector which is used to store the count of each char in the 
// window. Now at the end of the window we will note that is the number of characters different from s[end] have count greater 
// than k r not . If they were than we decreament their count by reducing our window . We wil mke it till their count does not 
// become less than k. After this we check the condition for max_length and than increament the window size by 1 and so on.

class Solution {
public:
    int characterReplacement(string s, int k) {
        int start=0;
        vector<int> store(26);
        int max_length=0;
        int max_count=0;
        
        for(int end=0;end<s.size();end++)
        {
            store[s[end]-'A']++;
            int curr_count=store[s[end]-'A'];
            max_count=max(max_count,curr_count);
            
            while(end-start-max_count+1>k)
            {
                store[s[start]-'A']--;
                start++;
            }
            
            max_length=max(max_length,end-start+1);
        }
        
        return max_length;
    }
};