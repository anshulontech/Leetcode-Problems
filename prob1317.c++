// // https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/

// Time Complexity:-O(N*l). Where N represents the i^th number and l represents the avg lenght of i^th nuber and (n-i)^th number.
// Space Compleity:-O(1).
    
// Approach:-
//     We will start from 1 and check the is i and n-i follow the condition or not. If they will than we will return 
// them else go for next pair.

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> store;
        for(int i=1;i<n;i++)
            if(checkvalid(i) && checkvalid(n-i))
            {
                store.push_back(i);
                store.push_back(n-i);
                
                return store;
            }
                
        return store;
    }
    
    bool checkvalid(int num)
    {
        while(num)
        {
            if(num%10==0)
                return false;
            num/=10;
        }
        
        return true;
    }
};