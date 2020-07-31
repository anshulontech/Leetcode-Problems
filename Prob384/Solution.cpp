// Approach 1:-

class Solution
{
private:
    vector<int> arr, original;
    int N;

public:
    Solution(vector<int> &nums)
    {
        arr = nums;
        original = nums;
        N = arr.size();
    }

    vector<int> reset()
    {
        arr = original;
        return original;
    }

    vector<int> shuffle()
    {
        for (int i = 0; i < N; i++)
        {
            int index = rand() % N;

            swap(arr[i], arr[index]);
        }

        return arr;
    }
};

// Approach 2:-

class Solution
{
private:
    vector<int> arr, original;
    int N;

public:
    Solution(vector<int> &nums)
    {
        arr = nums;
        original = nums;
        N = arr.size();
    }

    vector<int> reset()
    {
        return original;
    }

    vector<int> shuffle()
    {
        for (int i = 0; i < N; i++)
        {
            int index = rand() % N;

            swap(arr[i], arr[index]);
        }

        return arr;
    }
};