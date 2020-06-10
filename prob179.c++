// https://leetcode.com/problems/largest-number/submissions/

// Time Complexity:-O(N*N*M)  Where M i the max length of any particular string.
// Space Coplexity:-O(N*M).

// Approach:-
    // We are using the concept that which string we will apply first so that it will be max and do for all the index.
// Like for "3" and "30" as "3"+"30"="330" is greater than "30"+"3"="303" than it represents that for this case we
// should place "3" befor "30" and we will do this for all the index.

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> store;
        for (int i = 0; i < nums.size(); i++)
            store.push_back(to_string(nums[i]));

        for (int i = 0; i < store.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                if ((store[i] + store[j]) < (store[j] + store[i]))
                    swap(store[i], store[j]);

        string res = "";

        for (int i = 0; i < store.size(); i++)
            res += store[i];

        while (res[0] == '0' && res.length() > 1)
            res.erase(0, 1);

        return res;
    }
};

// Time Complexity:-O(N*Log(N)*M)  Where M i the max length of any particular string.
// Space Coplexity:-O(N*M).
    
// Approach:-
//     We will first copy all the intergers in a vector in the form of string and than sort it using the constrant 
// that s1+s2>s2+s1 which shows that if which string to be placed first if the nuber is made by only these string. 
// Like for "3" and "30" as "3"+"30"="330" is greater than "30"+"3"="303" than it represents that for this case we 
// should place "3" befor "30" this is the function of comperator.

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> store;
        for (int i = 0; i < nums.size(); i++)
            store.push_back(to_string(nums[i]));

        sort(store.begin(), store.end(), [](string &s1, string &s2) { return s1 + s2 > s2 + s1; });

        string res = "";

        for (int i = 0; i < store.size(); i++)
            res += store[i];

        while (res[0] == '0' && res.length() > 1)
            res.erase(0, 1);

        return res;
    }
};