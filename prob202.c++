// https://leetcode.com/problems/happy-number/

Space Complexity:-O(1).

// Approach:-
// In this question we made 2 different variables named slow and fast and initilize them with n. Now on  running the loop
// we change the values of slow and fast using change function and fast is going for double change as it moves fast. If 
// nuer is not a happy nuber than it would run a cycle(or a loop ) which can be determined same as linked list cycle .
// If any cycle is found than we return false or if value of fast becomes 1 than we return true as it represents that 
// th given number is a happy number.

inline int change(int );

class Solution {
public:
    bool isHappy(int n) {
        
        int slow=n,fast=n;
        
        do{
            slow=change(slow);
            fast=change(fast);
            fast=change(fast);
            if(fast==1)
                return true;
        }while(fast!=slow);
            
        return false;
    }
};

inline int change(int n)
{
    int result=0;
    while(n!=0)
    {
        result+=(n%10)*(n%10);
        n/=10;
    }
    
    return result;
}