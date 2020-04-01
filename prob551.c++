// https://leetcode.com/problems/student-attendance-record-i/

// Time Complexity:-O(N).
// Space Complexity:-O(1).

// Approach:-

// In this we are going to itterate the string ones and first check on encounter with A that is count is equal to 1 or not.
// If count is equal to one it represents taht in string one A is already preent before that A and hence string contains 
// more than 1 A hence student will not awarded else if countis equal to 0 than it represents that it is the 1 one in the 
// string hence we just increase the count.if the word in the string is L than we will check that is next two elements are 
// also L or not . if they are than we return false as given in the question otherwise just left them.

// At last if cursor move till end of the function than we just return true marking that student is able to get reward.


class Solution {
public:
    bool checkRecord(string s) {
        int count=0;
        for(int i=0;i<s.size();i++)
            if(s[i]=='A')
                if(count==1)
                    return false;
                else
                    count++;
            else
                if(s[i]=='L')
                    if((i+1)<s.size()&&(i+2)<s.size()&&s[i+1]=='L'&&s[i+2]=='L')
                        return false;
                
        return true;
        
    }
};