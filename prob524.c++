// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/

// Time Complexity:-O(n*l). where n is d length nd l is avg length of d[i].
// Space Complexity:-O(n).

// Approach:-
//     From the fisrt element in the d we will check that is this is a subsequence or not if it was than we check that 
// is the length is greater than previous one or not . If it was than we update the answer and similar for same length 
// and smaller lexicographical one. 
        
//     To check isSubsequence we will set one pointer for beginning of s and one for d[i] than we will just increament 
// the pointer of s and if it will found match with pointer of d[i] than we will increase both pointer otherwise increase 
// only s pointer .If the pointer of d[i] crosses length than it represents that it is a valid subsequence lese it is not.
    
class Solution {
private:
    string res="";
public:
    string findLongestWord(string s, vector<string>& d) {
        for(int i=0;i<d.size();i++)
            if(isSubsequence(s,d[i]))
                if(d[i].size()>res.size() || (d[i].size()==res.size() && d[i]<res))
                    res=d[i];
        
        return res;
    }
    
    bool isSubsequence(string & s, string & temp)
    {
        int j=0;
        for(int i=0;i<s.size() && j<temp.size();i++)
            if(s[i]==temp[j])
                j++;
        
        return j==temp.size();
    }
};