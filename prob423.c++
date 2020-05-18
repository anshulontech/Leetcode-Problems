// https://leetcode.com/problems/reconstruct-original-digits-from-english/

// Time Coplexity:-O(N).
// Space complexity:-O(1).
    
// Approach:-
//     we will first store the count of each char in the map and now we will use the property that some digits contain 
// unique character in their english word henc we will get the count of these words using this . After this we will remove 
// the count of other chars of that word than search for next one and hence in a fixed order we can deterine their count.

class Solution {
public:
    string originalDigits(string s) {
        vector<int> store(10);
        
        unordered_map<char,int> help;
        
        for(int i=0;i<s.size();i++)
            help[s[i]]++;
        
        
        checkunique(help,store);
        checknext(help,store);
        
        
        string res="";
        
        
        for(int i=0;i<10;i++)
            while(store[i]!=0)
            {
                res.insert(res.size(),to_string(i));
                store[i]--;
            }
        
        return res;
    }
    
    void checkunique(unordered_map<char,int> & help,vector<int> & store)
    {
        store[0]=help['z'];
        if(store[0]!=0)
        help['z']-=store[0],help['e']-=store[0],help['r']-=store[0],help['o']-=store[0];
        store[2]=help['w'];
        if(store[2]!=0)
        help['t']-=store[2],help['w']-=store[2],help['o']-=store[2];
        store[4]=help['u'];
        if(store[4]!=0)
        help['f']-=store[4],help['o']-=store[4],help['u']-=store[4],help['r']-=store[4];
        store[6]=help['x'];
        if(store[6]!=0)
        help['s']-=store[6],help['i']-=store[6],help['x']-=store[6];
        store[8]=help['g'];
        if(store[8]!=0)
        help['e']-=store[8],help['i']-=store[8],help['g']-=store[8],help['h']-=store[8],help['t']-=store[8];
        
    }
    
    void checknext(unordered_map<char,int> & help,vector<int> & store)
    {
        store[5]=help['f'];
        if(store[5]!=0)
        help['f']-=store[5],help['i']-=store[5],help['v']-=store[5],help['e']-=store[5];
        store[7]=help['s'];
        if(store[7]!=0)
        help['s']-=store[7],help['e']-=store[7],help['v']-=store[7],help['e']-=store[7],help['n']-=store[7];
        store[3]=help['t'];
        if(store[3]!=0)
        help['t']-=store[3],help['h']-=store[3],help['r']-=store[3],help['e']-=store[5]*2;
        store[1]=help['o'];
        if(store[1]!=0)
        help['o']-=store[1],help['n']-=store[1],help['e']-=store[1];
        store[9]=help['i'];
        if(store[9]!=0)
        help['n']-=store[9]*2,help['i']-=store[9],help['e']-=store[9];
    }
};

// Similar Approach As Above : -

                            class Solution
{
public:
    string originalDigits(string s)
    {
        vector<int> store(10);

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (c == 'z')
                store[0]++;
            else if (c == 'w')
                store[2]++;
            else if (c == 'x')
                store[6]++;
            else if (c == 'g')
                store[8]++;
            else if (c == 'u')
                store[4]++;
            else if (c == 's')
                store[7]++;
            else if (c == 'f')
                store[5]++;
            else if (c == 'h')
                store[3]++;
            else if (c == 'i')
                store[9]++;
            else if (c == 'o')
                store[1]++;
        }

        store[7] -= store[6];
        store[5] -= store[4];
        store[3] -= store[8];
        store[9] = store[9] - store[8] - store[5] - store[6];
        store[1] = store[1] - store[0] - store[2] - store[4];

        string res = "";

        for (int i = 0; i < 10; i++)
            while (store[i] != 0)
            {
                res.insert(res.size(), to_string(i));
                store[i]--;
            }

        return res;
    }
};