// https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/


// METHOD 1:-
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

// METHOD 2:-

// Time Complexity:- O(N).
// Space Complexity:- O(1).

// Approach:-
// Initially we will calculte the sum of whole array and check that is it divisible by 3 or not. If the totalsum is not
// divisible by 3 than we return false otherwise go further. Now we will make two variables locating start and end and than 
// try to capture target sum(totalsum/3) from start and end and if we will found that on condition that start<=end than 
// return true otherwise return false.


class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int totalsum=0;
        int i=0;
        for(;i<A.size();i++)
            totalsum+=A[i];
        
        if(totalsum%3!=0)
            return false;
        
        int start=0,end=A.size()-1;
        int sumstart=A[start++],sumlast=A[end--];
        do
        {
            if(sumstart!=totalsum/3)
                sumstart+=A[start++];
            if(sumlast!=totalsum/3)
                sumlast+=A[end--];
            if(start<=end&&sumstart==totalsum/3&&sumlast==totalsum/3)
                return true;
        }while(start<end);
        
        return false;
    }
};