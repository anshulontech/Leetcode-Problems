// Approach 1:-

class MyCircularQueue
{
private:
    vector<int> res;
    int start = 0, end = -1;
    int currSize = 0;

public:
    MyCircularQueue(int k)
    {
        res.resize(k);
    }

    bool enQueue(int value)
    {
        if (currSize == res.size())
            return false;

        currSize++;

        end = (end + 1) % res.size();
        res[end] = value;
        return true;
    }

    bool deQueue()
    {
        if (currSize == 0)
            return false;

        start = (start + 1) % res.size();
        currSize--;

        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        else
            return res[start];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        else
            return res[end];
    }

    bool isEmpty()
    {
        return currSize == 0;
    }

    bool isFull()
    {
        return currSize == res.size();
    }
};