// https://leetcode.com/problems/valid-palindrome/

// Time Complexity:-O(N).
// Space Complexity:-O*(1).

// Approach:-
//     We will set a itterator for 0th and last index and check that is both these characters are alphanumeric or not. 
// If they will than we will check that is s[start]==s[end] or not . If they were not than return false else take 1 
// step forwar in respective directions and if they were not alphanumeric than we will again move forward in respective 
// directions . If we will terminate the loop than it represents that it is a pallindrome else 

class Solution
{
public:
    bool isPalindrome(string s)
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int start = 0, end = s.size() - 1;
        while (start < end)
            if ((s[start] <= 'z' && s[start] >= 'a') || (s[start] <= '9' && s[start] >= '0'))
                if ((s[end] <= 'z' && s[end] >= 'a') || (s[end] <= '9' && s[end] >= '0'))
                    if (s[start] == s[end])
                    {
                        start++;
                        end--;
                    }
                    else
                        return false;
                else
                    end--;
            else
                start++;

        return true;
    }
};