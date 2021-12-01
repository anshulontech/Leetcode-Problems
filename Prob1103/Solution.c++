// Link To Problem:-
// https://leetcode.com/problems/distribute-candies-to-people/

class Solution
{
public:
    vector<int> distributeCandies(int candies, int people)
    {
        vector<int> A(people, 0);
        int i = 1;
        int j;
        while (i <= candies)
            for (j = 0; j < people && i <= candies; j++)
            {
                A[j] = A[j] + i;
                candies = candies - i;
                i++;
            }
        if (j == people)
            j = 0;
        if (candies != 0)
            A[j] = A[j] + candies;

        return A;
    }
};