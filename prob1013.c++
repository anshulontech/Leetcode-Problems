// https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/

// Time Complexity:-O(N).
// Space Complexity:-O(1).

// Approach:-
// Initially we will calculte the sum of whole array and check that is it divisible by 3 or not. If the totalsum is not
// divisible by 3 than we return false otherwise go further. Now we iterate the loop and find the first occurence of totalsum/3
// and go till it will nt appear for 2 times . When parts ill become equal to 2 or i will become equal to A.size() we terminate 
// the loop and check the conditions as given in code to get the desired output.

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int totalsum=0;
        int i=0;
        for(;i<A.size();i++)
            totalsum+=A[i];
        
        if(totalsum%3!=0) // If totalsum is not divisible by 3 so it can not be divided into 3 parts , hence return false.
            return false;
        
        int parts=0;
        int temp=0;
        for(i=0;i<A.size()&&parts<2;i++)
        {
            temp+=A[i];
            if(temp==totalsum/3)
            {
                temp=0;
                parts++;
            }
        }
        
        if(parts==2&&i!=A.size()) // If parts is equal to 2 and i is not equal to A.size() than it reresents that 2 parts are present somewhere before the end and third part is present after i hence we will return true.
            return true;
        else
            return false;
        
    }
};