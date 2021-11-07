// Link To Problem:-
// https://leetcode.com/problems/vowels-of-all-substrings/

// Solution:-
class Solution
{
public:
    long long countVowels(string word)
    {
        long long res = 0;

        vector<long long> arr;
        int n = word.size();

        for (int i = 0; i < n; i++)
            if (i == 0)
                arr.push_back(n);
            else
            {
                long long temp1 = n - i, temp2 = arr[i - 1] - i;

                arr.push_back(temp1 + temp2);
            }

        for (int i = 0; i < n; i++)
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
                res += arr[i];

        return res;
    }
};