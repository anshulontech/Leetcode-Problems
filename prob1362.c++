// https://leetcode.com/problems/closest-divisors/

// Time Complexity:-O(sqrt(N)).
// Space Complexity:-O(1).
    
// Approach:-
//     Starting from 1 we will check that the number which is a factor of num+1 or num+2 an if it was than we will 
// check that is the absolute difference founf=d to be less than the existing one or not . if it was than we update 
// the answer. To minimise the time first we will check that is anyone of num+1 or num+2 is a perfect square or not . 
// If it was than the minimum difference would always be and the numbers are found to be sqrt of either num+1 or num+2.

class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> store(2);
        int min_diff=INT_MAX;
        
        if(checkit(num+1))
        {
            store[0]=sqrt(num+1);
            store[1]=sqrt(num+1);
            
            return store;
        }
        
        if(checkit(num+2))
        {
            store[0]=sqrt(num+2);
            store[1]=sqrt(num+2);
            
            return store;
        }
        
        for(int i=1;i<=sqrt(num+2);i++)
        {
            if((num+1)%i==0)
            {
                int other=(num+1)/i;
                if(abs(other-i)<min_diff)
                {
                    min_diff=abs(other-i);
                    store[0]=i;
                    store[1]=other;
                }
            }
            if((num+2)%i==0)
            {
                int other=(num+2)/i;
                if(abs(other-i)<min_diff)
                {
                    min_diff=abs(other-i);
                    store[0]=i;
                    store[1]=other;
                }
            }
        }
        return store;
        
    }
    
    inline bool checkit(int num)
    {
        int temp=sqrt(num);
        return temp*temp==num;
    }
};


// Time Complexity:-O(sqrt(N)).
// Space Complexity:-O(1).
    
// Approach:-
//     Same as that of above one but here what we are doing is that we will start from the sqrt(num+1) and sqrt(num+2)
// as the minimum difference will occur only for larger factors hence if start from the sqrt and if we found any factor
// than we can break it that time without any problem and hence go for num+2 and check for it.


class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> store(2);
        int min_diff=INT_MAX;
        
        for(int i=sqrt(num+1);i>0;i--)
            if((num+1)%i==0)
            {
                int other=(num+1)/i;
                min_diff=abs(i-other);
                store[0]=i;
                store[1]=other;
                break;
            }
        
        for(int i=sqrt(num+2);i>0;i--)
            if((num+2)%i==0)
            {
                int other=(num+2)/i;
                if(abs(i-other)<min_diff)
                {
                    store[0]=i;
                    store[1]=other;
                }
                
                break;
            }
        
        return store;
    }
};