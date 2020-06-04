// https://leetcode.com/problems/count-primes/

// Time Complexity:-O(N*log(N))
// Space Complexity:-O(N)

// Approach:-
//     In this what we are going to do is we will start from 2 and set all further numbers which are divisible by 2 
// to false representing that they are not prime , Same will be done for 3 and others . Now if we encounter with number 
// which is already false than it represents that all it's factors are also checked hence we have no more need to 
// encounter with these . Now the number having true at their poisition represents that they are not divisible y 
// anyone hence will return their count.
    
    
class Solution
{
public:
    int countPrimes(int n)
    {
        if (n < 2)
            return 0;
        vector<bool> store(n, true);

        store[0] = false, store[1] = false;

        for (int i = 0; i < sqrt(n); i++)
            if (store[i])
            {
                for (int j = i * i; j < n; j += i)
                    store[j] = false;
            }

        return count(store.begin(), store.end(), true);
    }
};