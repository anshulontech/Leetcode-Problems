// https://leetcode.com/problems/sort-an-array/

// Time Complexity:-O(Nlog(N)).
// Space Complexity:-O(log(N)).

// Approach:-
// Same as that of Quick sort.
// First call quick sort function and in this function we call partition function where we choose a variable as pivot 
// and using partition function make pivot to it's correct poisition and than again calling quicksort function to sort 
// first left part of pivot and than the right part using recursion.


void quicksort(vector<int> & ,int ,int );
int partition(vector<int> & ,int ,int );
void swap(int * ,int* );

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
        quicksort(nums,0,nums.size()-1);
        
        return nums;
    }
};

void quicksort(vector<int> & nums,int start,int end)
{
    if(start>=end)
        return ;
    
    int Pindex=partition(nums,start,end);
    
    quicksort(nums,start,Pindex-1);
    quicksort(nums,Pindex+1,end);
}

int partition(vector<int> & nums,int start,int end)
{
    int pivot=nums[end];
    int i=start,j=start;
    
    while(i<end)
    {
        if(nums[i]<=pivot)
        {
            swap(&nums[i],&nums[j]);
            j++;
        }
        i++;
    }
    
    swap(&nums[j],&nums[end]);
    return j;
}

void swap(int * p,int* q)
{
    int temp=*p;
    *p=*q;
    *q=temp;
}