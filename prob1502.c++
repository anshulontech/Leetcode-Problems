// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/description/

// Time Complexity:-O(N*log(N)).
// Space Complexity:-O(1).
    
// Approach:-
//     Initially we will sort the array and than compute the difference between second and first element and mark it 
// as diff. Now we will run through the arr and if found difference between any consecutive number not equal to diff 
// would directly say that these numbers can not form a AP hence we will retur false else if loop terminates by 
// checking all elements than we will return true.

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        
        int diff=arr[1]-arr[0];
        
        for(int i=1;i<arr.size();i++)
            if((arr[i]-arr[i-1])!=diff)
                return false;
        
        return true;
    }
};

// Time Complexity:-O(N).
// Space Complexity:-O(N).

// Approach:-
//     In this we are using  hash map to store the count of each number . Also during taking we will calculate the max
// and the min value in the list and than calculate the arithemetic difference of the sequence(Line 53).Now we itterate 
// the map starting from min val and check that is the val(initially min val) +diff exist or not. If it is than we will 
// make val equal to val+diff and than check for it, if at any step it fails or the count become more than 1 than we will
// return false except case when diff is 0.

class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        unordered_map<int, int> store;
        int min_val = INT_MAX, max_val = INT_MIN;
        int N = arr.size();

        for (int i = 0; i < N; i++)
        {
            store[arr[i]]++;
            min_val = min(min_val, arr[i]);
            max_val = max(max_val, arr[i]);
        }

        int diff = (max_val - min_val) / (N - 1);

        if (diff == 0 && store.size() == 1)
            return true;

        int val = min_val;

        while (val <= max_val)
        {
            if (store[val] != 1)
                return false;

            val += diff;
        }

        return true;
    }
};