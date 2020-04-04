// https://leetcode.com/problems/count-largest-group/

// Time Complexity:- O(3*N) ~~ O(N).
// Space Complexity:-O(N).
    
// Approach:-
// Initially we will store all values with thier digit sum in a map where first represents the sum while second 
// represents the number of number of digits having that number. Now we will iterate the whole map and find out the value 
// having the maximum value of second item.Again we will iterate the whole map and than count how many elements will have 
// this maximun value and return that count.

int sumofdigit(int );

class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> A;
        for(int i=1;i<=n;i++)
        {
            int value=sumofdigit(i);
            if(A.find(value)!=A.end())
                A[value]++;
            else
                A.insert(make_pair(value,1));
        }
        
        int maxi=INT_MIN;
        for(auto x: A)
            if(x.second>=maxi)
                maxi=x.second;
        
        int count=0;
        for(auto x: A)
            if(x.second==maxi)
                count++;
        
        return count;
        
    }
        
};

int sumofdigit(int n)
{
    int temp=0;
    while(n!=0)
    {
        temp+=n%10;
        n/=10;
    }
    
    return temp;
}