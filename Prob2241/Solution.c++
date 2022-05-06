// Link To The Problem:-
// https://leetcode.com/problems/design-an-atm-machine/

// Solution:-

class ATM
{
    vector<long long> arr;
    vector<long long> value;

public:
    ATM()
    {
        arr.resize(5, 0);
        value = {20, 50, 100, 200, 500};
    }

    void deposit(vector<int> banknotesCount)
    {
        for (int i = 0; i < 5; i++)
            arr[i] += banknotesCount[i];
    }

    vector<int> withdraw(int amount)
    {
        vector<int> res(5, 0);

        for (int i = 4; i >= 0; i--)
        {
            res[i] = min(amount / value[i], arr[i]);
            amount -= res[i] * value[i];
            arr[i] -= res[i];
        }

        if (amount == 0)
            return res;

        for (long long i = 0; i < 5; i++)
            arr[i] += res[i];

        return {-1};
    }
};
