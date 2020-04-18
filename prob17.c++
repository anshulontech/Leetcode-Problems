// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

// Time Complexity:-O(3^N)
// Space Complexity:-O(N).
    
// Approach:-
//     Let us assume we have made different stations for each character of a string and these stations are also subdivided 
// into different platforms (number of platforms depands upon number of alphabets the number will have on it's telephone number). 
// The order of appearance of the platform is based on the character poisition in digit string. Now we will start from the 1st 
// platform of 1st sattion. Insert the character to a helper string s than for next station's platform which should arrise in 
// order. As on last station as no stationis present after that one so we will insert s in res vector and than come back to 
// previous station than go for the next platform of next station such that all combinations can be counted.  


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> res;
        
        if(digits.size()==0)
            return res;
        vector<string> store={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        for(int i=0;i<store[digits[0]-'0'].size();i++)
        {
            string s;
            s.push_back(store[digits[0]-'0'][i]);
            combination(store,digits,res,s,1);
            s.erase(s.size()-1,1);
        }
        
        return res;
        
    }
    
    void combination(vector<string> & store,string & digits, vector<string> & res, string & s, int poisition)
    {
        if(poisition==digits.size())
        {
            res.push_back(s);
            return ;
        }
        
        for(int i=0;i<store[digits[poisition]-'0'].size();i++)
        {
            s.push_back(store[digits[poisition]-'0'][i]);
            combination(store,digits,res,s,poisition+1);
            s.erase(s.size()-1,1);
        }
        
        return ;
    }
};