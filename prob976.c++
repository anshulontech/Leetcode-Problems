// https://leetcode.com/problems/largest-perimeter-triangle/

// Time Complexity:-O(N*log(N)).
// Space Complexity:-O(1).
    
// Approach:-
//     We will iitially sort the given vector. Now as we know that If we want largest 3 than we will start fromback 
// and check the condition that is they are forming a triangle or not using the condition that if sum of any two sides 
// is more than third one and is true for all three than it represents that it will form a triangle.

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(),A.end());

        for (int i = A.size() - 1; i > 1; i--)
            if ((A[i] + A[i - 1]) > A[i - 2])
                if ((A[i - 1] + A[i - 2]) > A[i])
                    if ((A[i] + A[i - 2]) > A[i - 1])
                        return A[i] + A[i - 1] + A[i - 2];

        return 0;
    }
};

// Modification:-

//     As we know the smallest and middle side are always less than the sum of rest two hence we will check only for
// the longest one.



class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(),A.end());
        
        for(int i=A.size()-1;i>1;i--)
            if(A[i]<(A[i-1]+A[i-2]))
                return A[i]+A[i-1]+A[i-2];
        
        return 0;
    }
};