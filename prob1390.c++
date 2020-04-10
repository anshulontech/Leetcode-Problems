// https://leetcode.com/problems/four-divisors/submissions/

// Time Complexity:-O(N*L).  ---Where L is avg of the sqrt of the numbers.
// Space Coplexity:-O(1).
    
// Approach:-
    // We will traverse all the elements in the list present with the idea that as 1 and the number itself both are the 
// divisor of this number. So the number to have exactly 4 divisors it should have 2 more numbers required. If the first one 
// is d than the other one will be n/d and they both should not be equal. So to check this we will run a loop from 2 to the 
// sqrt of the numberand check that if more than 2 or less than one sln divisor than it would not be included into the sln 
// and hence not sdded into the count. At the last we will return count as our final answer.


class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        cout<<nums.size();
        int count=0;
        for(auto x:nums)
        {
            auto previous=0;
            
            for(int i=2;i*i<=x;i++)
                if(x%i==0)
                    if(previous==0)
                        previous=i;
                    else
                    {
                        previous=0;
                        break;
                    }
            
            if(previous!=0&&previous!=x/previous)
                count+=1+x+previous+x/previous;
        }
        
        return count;
    }
};