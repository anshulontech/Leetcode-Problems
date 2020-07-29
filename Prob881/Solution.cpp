// Approach 1:-

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        int res = 0;
        sort(people.begin(), people.end());

        int start = 0, end = people.size() - 1;

        while (start <= end)
        {
            res++;
            if ((people[end] + people[start]) <= limit)
                start++;

            end--;
        }

        return res;
    }
};

// Approach 2:-

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        int res = 0;
        vector<int> bucket(limit + 1);

        for (int i = 0; i < people.size(); i++)
            bucket[people[i]]++;

        int start = 0, end = bucket.size() - 1;

        while (start <= end)
        {
            while (start <= end && bucket[start] <= 0)
                start++;
            while (start <= end && bucket[end] <= 0)
                end--;

            if (bucket[start] <= 0 && bucket[end] <= 0)
                break;

            res++;

            if (start + end <= limit)
                bucket[start]--;

            bucket[end]--;
        }

        return res;
    }
};
