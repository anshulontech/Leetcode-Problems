// https://leetcode.com/problems/minimum-increment-to-make-array-unique/

// Time Complexity:-O(N*log(N)).
// Space Complexity:-O(N).
    
// Approach:-
//     In this first we will stre the count of each number in a map not unordered map as we have to traverse the map 
// in increasing order. Now after this we are going to traverse the map now if the count of the number is more than 1 
// than we have to change it else not . now if the count is turned out to be more than 1 than we will update count-1 
// objects with 1 and store them in map . now in next step we will traverse them and do the same process till all 
// numbers will not become unique.

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        map<int,int> store;
        
        for(int i=0;i<A.size();i++)
            store[A[i]]++;
        
        map<int, int>::iterator itr; 
        int res=0;
        for(itr=store.begin();itr!=store.end();itr++)
            if(itr->second!=0) {
                int temp=itr->first;
                int val=itr->second;
            
                store[temp+1]+=val-1;
                res+=val-1;
            }
        
        
        return res;
    }
};

// Time Complexity:-O(N*log(N)).
// Space Complexity:-O(N).  -- To sort the vector.

// Approach:-
//     Initially we will sort the and now we are going to travesre the array . Now on traverseing the array if we will 
// encounter a situation that A[i]<=A[i-1] tha we will make  the A[i] by A[i-1]+1 and and increase res with their new diff.
// And by doing this we can generate the answer.

class Solution
{
public:
    int minIncrementForUnique(vector<int> &A)
    {
        sort(A.begin(), A.end());

        int res = 0;

        for (int i = 1; i < A.size(); i++)
            if (A[i] <= A[i - 1])
            {
                res += A[i - 1] + 1 - A[i];
                A[i] = A[i - 1] + 1;
            }

        return res;
    }
};