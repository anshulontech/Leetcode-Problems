// https://leetcode.com/problems/next-greater-element-iii/description/

// Time Complexity:-O(N) -- Average Case & O(N*log(N)) -- Worst Case.
// Space Complexity:-O(N). Where N is number of digits in n.
    
// Approach:-
//     So in this problem we will initially change the number into the string and than search for the first decreasing 
// part from the last of the string and if it is valid than we will move forward else return -1 representing that it 
// is not possible to make a number from these digits which is greater than n as for this representation n is the max 
// number. After all this we will move forward and make a temp string representing the non decreasing part of the 
// string from the last. Now what we have to do is to just find the next permutation of this tsring so for this what 
// we are going to do is that we will first find the just next greater element for temp[0] and than switch it to the 
// first place and than sort the remaining string so what is happenning here is that it will give the next permutation 
// for the old string. Now we will replace the old part of the string with the new one and than return the value which 
// is reprsented by this string if it is under 32 bit integer value else return -1 , so for this we have a user defined 
// function check to perform this operation.

class Solution
{
public:
    int nextGreaterElement(int n)
    {
        string res = to_string(n);
        int i = res.size() - 2;

        for (; i >= 0; i--)
            if (res[i] < res[i + 1])
                break;

        if (i < 0)
            return -1;

        string next = res.substr(i, res.size() - i);
        res.erase(i, res.size() - i);

        int val = INT_MAX;
        int index;

        for (int j = 0; j < next.size(); j++)
            if (next[j] > next[0] && next[j] < val)
            {
                index = j;
                val = next[j];
            }
        next.erase(index, 1);

        res += to_string(val - '0');

        sort(next.begin(), next.end());

        res += next;

        long long int value = change(res);

        if (value > INT_MAX)
            return -1;
        else
            return value;
    }

    long long int change(string &res)
    {
        long long int val = 0;

        for (int i = 0; i < res.size(); i++)
            val = val * 10 + res[i] - '0';

        return val;
    }
};