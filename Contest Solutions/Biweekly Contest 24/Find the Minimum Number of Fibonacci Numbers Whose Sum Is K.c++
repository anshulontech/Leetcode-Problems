// Solution:-

class Solution
{
public:
    int findMinFibonacciNumbers(int k)
    {
        vector<int> store;

        store.push_back(1);
        store.push_back(1);

        int first = 1, second = 1;

        while (second + first <= k)
        {
            store.push_back(first + second);
            int temp = first + second;
            first = second;
            second = temp;
        }

        int res = 0;

        while (k > 0)
        {
            int idx = lower_bound(store.begin(), store.end(), k) - store.begin();

            if (idx == store.size() || store[idx] > k)
                idx--;

            k -= store[idx];
            res++;
        }

        return res;
    }
};