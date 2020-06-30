// https://leetcode.com/problems/maximum-product-of-word-lengths/description/

// Time Complexity:-O(N^2).
// Space Complexity:-O(N).
    
// Approach:- (Brute Force).
//     In this what we are going to do is that we will check for all the elements that is there any string exist such 
// that both of them different characters and if they we will than is there product of length is more than that of 
// previous pair or not and update the answer on this basis. To check that is strings contains different character 
// we will use a hash set so that we have no need to traverse it again and again.

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res=0;
        
        for(int i=0;i<words.size();i++) {
            
            unordered_set<char> store;
            
            for(int k=0;k<words[i].size();k++)
                store.insert(words[i][k]);
            
            for(int j=i+1;j<words.size();j++)
                if(check(words[j],store)) {
                    int curr=words[i].size()*words[j].size();
                    res=max(res,curr);
                }
        }
        
        return res;
    }
    
    bool check(string& B,unordered_set<char>& store) {
        for(int i=0;i<B.size();i++)
            if(store.find(B[i])!=store.end())
                return false;
        
        return true;
    }
};

// Time Complexity:-O(N^2).
// Space Complexity:-O(N).

// Approach:- (Bit Manipulation)

class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        int res = 0;
        int n = words.size();
        vector<int> checker(n);

        for (int i = 0; i < n; i++)
        {

            int num = 0;

            for (int j = 0; j < words[i].size(); j++)
                num |= 1 << (words[i][j] - 'a');

            checker[i] = num;
        }

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if ((checker[i] & checker[j]) == 0)
                {
                    int val = words[i].size() * words[j].size();
                    res = max(res, val);
                }

        return res;
    }
};