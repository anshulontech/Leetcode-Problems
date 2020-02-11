// https://leetcode.com/problems/fizz-buzz/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> A(n);
        for(int i=1;i<=n;i++)
        {
            if(i%3==0)
                A[i-1] += "Fizz";
            if(i%5==0)
                A[i-1] += "Buzz";
            if(A[i-1].empty())
                A[i-1] += to_string(i);
                
        }
        return A;
    }
};