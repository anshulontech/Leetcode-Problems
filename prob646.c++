// https://leetcode.com/problems/maximum-length-of-pair-chain/

// Time Complexity:-O(N*log(N)).
// Space Complexity:-O(N).  -- Just for sorting.
     
// Approach:-
//     In this what we are going to do is that we will first sort the vector on the basis of their 2nd element and 
// than taking 1st elemnt as root of the chain we will check that how many elements can be inserted using the property 
// that for (a,b) and (c,d) b<c and if this property holdes true than we update (a,b) with (c,d) and search for (c,d) 
// in the forward of the array and at last return the size of the new array formed. But we can do this lso without using 
// constant extra space by taking count that how many elements are there in the array and taking last_val of the array 
// formed .

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),comp);
        
        int last_val=INT_MIN,count=0;
        
        for(int i=0;i<pairs.size();i++)
            if(last_val<pairs[i][0]) {
                last_val=pairs[i][1];
                count++;
            }
        
        return count;
    }
    
private:
    static bool comp(vector<int>& a,vector<int>& b) {
        return a[1]<b[1];
    }
};

// Time Complexity:-O(N^2).
// Space Complexity:-O(N).

// Approach:-
//     In this what we are going to do us that first we will sort the array based on first index and than check for each
// index that how many previous elements can be used make longest chain till that element and store the max result obtained
// in a vector of array. After doing this what we can do is that we will calculate the max value in the dp array which 
// represents that what will be the max value of chain that can be formed.

class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end());

        int n = pairs.size();

        vector<int> dp(n, 1);

        for (int j = 1; j < n; j++)
            for (int i = 0; i < j; i++)
                if (pairs[i][1] < pairs[j][0])
                    dp[j] = max(dp[j], dp[i] + 1);

        int res = 0;

        for (int i = 0; i < dp.size(); i++)
            if (dp[i] > res)
                res = dp[i];

        return res;
    }
};