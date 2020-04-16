// https://leetcode.com/problems/count-and-say/submissions/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     Starting from 1 we will run the loop while the number temp1 will not become equal to n. Initially we will make a string 
// and initialize it with "1". Now we will follow the operations given in the question to the string s and than store the 
// desired result in a local string named temp and made all changes to that temp string. In the last of each loop we will 
// change s string to temo and hence will obtain the final result as string s .

class Solution {
public:
    string countAndSay(int n) {
        int temp1=1;
        string s="1";
        
        while(temp1!=n)
        {
            string temp="";
            for(int i=0;i<s.size();i++)
            {
                int count=1;
                int k=i+1;
                while(i<s.size()&&s[i]==s[k])
                {
                    count++;
                    k++;
                }
                
                temp.insert(temp.size(),to_string(count));
                temp.insert(temp.size(),s.substr(i,1));
                i=k-1;
            }
            
            s=temp;
            temp1++;
        }
        
        return s;
    }
};