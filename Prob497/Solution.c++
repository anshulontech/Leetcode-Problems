// Link To Problem:-
// https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/submissions/

class Solution
{
private:
    vector<vector<int>> store;

public:
    Solution(vector<vector<int>> &rects)
    {
        store = rects;
    }

    vector<int> pick()
    {
        int sum_area = 0;
        vector<int> selected;

        for (auto r : store)
        {
            int area = (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
            sum_area += area;

            if (rand() % sum_area < area)
                selected = r;
        }

        int x = rand() % (selected[2] - selected[0] + 1) + selected[0];
        int y = rand() % (selected[3] - selected[1] + 1) + selected[1];

        return {x, y};
    }
};

// Dont't Know why this fails.

class Solution
{
private:
    vector<vector<int>> store;

public:
    Solution(vector<vector<int>> &rects)
    {
        store = rects;
    }

    vector<int> pick()
    {
        int index = (rand() % store.size());

        int len = store[index][2] - store[index][0];
        int wid = store[index][3] - store[index][1];

        vector<int> res(2);

        if (len)
            res[0] = (rand() % len) + store[index][0];
        else
            res[0] = store[index][0];

        if (wid)
            res[1] = (rand() % wid) + store[index][1];
        else
            res[1] = store[index][1];

        return res;
    }
};