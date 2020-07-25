// Approach 1:-

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr)
    {
        int N = arr.size();

        vector<long> store;
        store.push_back(0);
        long sum = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            store.push_back(sum);
        }

        int odd_before = 0, even_before = 1;
        int res = 0;
        int mod = pow(10, 9) + 7;
        for (int i = 1; i < arr.size() + 1; i++)
            if (store[i] % 2 == 0)
            {
                res += odd_before;
                res = res % mod;
                even_before++;
            }
            else
            {
                res += even_before;
                res = res % mod;
                odd_before++;
            }

        return res;
    }
};