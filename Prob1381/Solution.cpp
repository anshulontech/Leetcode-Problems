// Approach 1:-

class CustomStack
{
private:
    int size;
    vector<int> store;

public:
    CustomStack(int maxSize)
    {
        size = maxSize;

        return;
    }

    void push(int x)
    {
        if (store.size() < size)
            store.push_back(x);

        return;
    }

    int pop()
    {
        if (store.empty())
            return -1;

        int val = store[store.size() - 1];
        store.pop_back();

        return val;
    }

    void increment(int k, int val)
    {
        for (int i = 0; i < k && i < store.size(); i++)
            store[i] += val;

        return;
    }
};