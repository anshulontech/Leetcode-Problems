// https://leetcode.com/problems/duplicate-zeros/description/

// Time Complexity:-O(N^2).
// Space Complexity:-O(1).
    
// Approach:-
//     For each encounter with 0 we will shift the whole array from ith index to the right. So by this there is no 
// requirment of extra space.

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        for(int i=0;i<arr.size();i++)
            if(arr[i]==0) {
                for(int j=arr.size()-1;j>i;j--)
                    arr[j]=arr[j-1];
                
                i++;
            }
        
        return ;
    }
};

// Time Complexity:-O(N).
// Space Complexity:-O(1).

// Approach:-
//     In this what we are doing is that we will initially count the number of zero in the vector and than we will 
// shift the array count times forward with consideration that for each zero we have to insert one more zero there.

class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        int n = arr.size(), count = n - 1;

        for (int i = 0; i < arr.size(); i++)
            if (arr[i] == 0)
                count++;

        int i = n - 1;

        while (i >= 0 && count >= 0)
        {
            if (arr[i] != 0)
            {
                if (count < n)
                    arr[count] = arr[i];
            }
            else
            {
                if (count < n)
                    arr[count] = arr[i];

                count--;
                if (count < n)
                    arr[count] = arr[i];
            }

            count--;
            i--;
        }
    }
};