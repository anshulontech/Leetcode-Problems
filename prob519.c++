// https://leetcode.com/problems/random-flip-matrix/description/

// Using Matrix and set.

class Solution
{
private:
    struct pair_hash
    {
        inline std::size_t operator()(const std::pair<int, int> &v) const
        {
            return v.first * 31 + v.second;
        }
    };
    vector<vector<int>> store;
    int n, m;
    unordered_set<pair<int, int>, pair_hash> traversed;

public:
    Solution(int n_rows, int n_cols)
    {
        n = n_rows;
        m = n_cols;
        vector<int> temp(n_cols, 0);

        for (int i = 0; i < n_rows; i++)
            store.push_back(temp);
    }

    vector<int> flip()
    {
        int x = rand() % n, y = rand() % m;

        while (store[x][y] != 0)
        {
            x = rand() % n, y = rand() % m;
        }

        store[x][y] = 1;

        traversed.insert(make_pair(x, y));

        return {x, y};
    }

    void reset()
    {
        for (auto x : traversed)
        {
            store[x.first][x.second] = 0;
        }

        traversed.clear();
    }
};

// Using set.

class Solution
{
private:
    struct pair_hash
    {
        inline std::size_t operator()(const std::pair<int, int> &v) const
        {
            return v.first * 31 + v.second;
        }
    };
    int n, m;
    unordered_set<pair<int, int>, pair_hash> traversed;

public:
    Solution(int n_rows, int n_cols)
    {
        n = n_rows;
        m = n_cols;
    }

    vector<int> flip()
    {
        int x = rand() % n, y = rand() % m;

        while (traversed.find({x, y}) != traversed.end())
        {
            x = rand() % n, y = rand() % m;
        }

        traversed.insert(make_pair(x, y));

        return {x, y};
    }

    void reset()
    {
        traversed.clear();
    }
};