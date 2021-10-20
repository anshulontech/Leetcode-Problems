// Link To Problem:-
// https://leetcode.com/problems/stock-price-fluctuation/

// Solution:-

class StockPrice
{
private:
    unordered_map<int, int> map;
    unordered_map<int, int> count;
    priority_queue<int> maxVal;
    priority_queue<int, vector<int>, greater<int>> minVal;
    int maxT = -1;

public:
    StockPrice()
    {
    }

    void update(int t, int p)
    {
        if (map.find(t) != map.end())
            count[map[t]]--;

        map[t] = p;
        count[p]++;
        maxT = max(maxT, t);
        maxVal.push(p);
        minVal.push(p);
    }

    int current()
    {
        return map[maxT];
    }

    int maximum()
    {
        while (count[maxVal.top()] == 0)
            maxVal.pop();

        return maxVal.top();
    }

    int minimum()
    {
        while (count[minVal.top()] == 0)
            minVal.pop();

        return minVal.top();
    }
};