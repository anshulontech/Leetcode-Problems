// https://leetcode.com/problems/counting-bits/

// Time Complexity:-O(N).
// Space Complexity:-O(N)   -- Used for the answer to stroe values.
    
// Approach:-
//     On observing the pattern we can found that the number of 1 bits in a number is equal to 1+ number of 1 bits 
// in number which is less than offset. So in this we are doing the same.
    
// What is offset?
//     Here offset represents the last number which has only 2 as prime factor. So on observation we can folow the 
// explanation as explained above.
    
// Example for observation:- Let initially offset =1;
// 0->0;
// 1->1;        1 - 1 = 0 so number of bits is 0 + 1;
// 2->0 1;      now offset changes as 2 has only 2 as prime factor 2 - 1 = 1 so number of bits is 0 + 1; offset = 2;
// 3->1 1;      3 - 2 = 1 so number of bits is 1 + 1;
// 4->0 0 1;    4 - 4 = 0 so number of bits is 0 + 1; offset changed = 4;
// 5->1 0 1;    5 - 4 = 1 so number of bits is 1 + 1;
// 6->0 1 1;    6 - 4 = 2 so number of bits is 1 + 1;
// 7->1 1 1;    7 - 4 = 3 so number of bits is 2 + 1;
// 8->0 0 1;    8 - 8 = 0 so number of bits is 0 + 1 as offset changed to 8;

class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> store(num + 1);
        int offset = 1;
        for (int i = 1; i <= num; i++)
        {
            if (offset * 2 == i)
                offset *= 2;

            store[i] = store[i - offset] + 1;
        }

        return store;
    }
};