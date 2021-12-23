// Link To Problem:-
// https://leetcode.com/problems/watering-plants-ii/

// Solution:-

class Solution
{
public:
    int minimumRefill(vector<int> &plants, int A, int B)
    {
        int a = A, b = B, count = 0;

        int i = 0, j = plants.size() - 1;

        while (i < j)
        {

            if (plants[i] > a)
            {
                count++;
                a = A;
            }

            a -= plants[i];
            if (plants[j] > b)
            {
                count++;
                b = B;
            }

            b -= plants[j];

            i++, j--;
        }

        if (i == j)
        {
            if (a > b)
            {
                if (plants[i] > a)
                    count++;
            }
            else
            {
                if (a < b)
                {
                    if (plants[i] > b)
                        count++;
                }
                else
                {
                    if (plants[i] > a)
                        count++;
                }
            }
        }

        return count;
    }
};