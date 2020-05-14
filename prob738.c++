// https://leetcode.com/problems/monotone-increasing-digits/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     What wea re going to do is that if we will found any digit less than previous one than we will decrease that 
// by 1 than assign 9 to the further digits . Now in this problem we are doing to do the same but here we are going 
// from the back to start so that if any value is not find than it will change nothing and we have to bother about 
// same vales. We will first find the pair such that s[i]<s[i-1] forwhich i is mimimum and than decrease it by 1 and 
// than make further one's to 9.
    
    
    
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s=to_string(N);
        
        int marker=s.size();
        
        for(int i=s.size()-1;i>0;i--)
            if(s[i]<s[i-1])
            {
                marker=i;
                s[i-1]=s[i-1]-1;
            }
        
        for(int i=marker;i<s.size();i++)
            s[i]='9';
        
        return stoi(s);
    }
};

// Time Complexity:-O(N).
// Space Complexity:-O(N).

// Approach:-
//     Same Approach as that of above but here what we are going to do is to start from the beginning and traverse 
// till next element become less than the current one . Here what we have to note is that the loop moves forward till 
// value become less but it will itterate if the values are same . Now to change the number we will first move back till 
// the values are same and than decrease the curr by 1 and make forward 9.

class Solution
{
public:
    int monotoneIncreasingDigits(int N)
    {
        if (N < 10)
            return N;
        string s = to_string(N);
        int i = 0;
        for (; i < s.size() - 1; i++)
            if (s[i] > s[i + 1])
                break;

        while (i > 0 && s[i] == s[i - 1])
            i--;
        if (i == s.size() - 1 && s[i - 1] <= s[i])
            return N;

        s[i] = s[i] - 1;
        i++;
        for (; i < s.size(); i++)
            s[i] = '9';

        return stoi(s);
    }
};