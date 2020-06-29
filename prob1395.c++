// https://leetcode.com/problems/count-number-of-teams/description/

// Time Complexity:-O(N^2).
// Space Complexity:-O(N).  For Recursion stack.
    
// Approach:-
//     In this approach we are going to use brute force approach such that for each element we will check next greater 
// element in forward and backeard element and than search that how many more next forward and backward elements are 
// there and store there count an than search for next and so on.

class Solution
{
private:
    int checkFor(vector<int> &rating, int &index)
    {

        int res = 0;

        for (int i = index + 1; i < rating.size(); i++)
            if (rating[i] > rating[index])
                res += checkFor2(rating, i);

        return res;
    }

    int checkFor2(vector<int> &rating, int &index)
    {
        int res = 0;

        for (int i = index + 1; i < rating.size(); i++)
            if (rating[i] > rating[index])
                res++;

        return res;
    }

    int checkBak(vector<int> &rating, int &index)
    {

        int res = 0;

        for (int i = index - 1; i >= 0; i--)
            if (rating[i] > rating[index])
                res += checkBak2(rating, i);

        return res;
    }

    int checkBak2(vector<int> &rating, int &index)
    {
        int res = 0;

        for (int i = index - 1; i >= 0; i--)
            if (rating[i] > rating[index])
                res++;

        return res;
    }

public:
    int numTeams(vector<int> &rating)
    {
        int res = 0;

        for (int i = 0; i < rating.size(); i++)
        {
            res += checkFor(rating, i);

            res += checkBak(rating, i);
        }

        return res;
    }
};