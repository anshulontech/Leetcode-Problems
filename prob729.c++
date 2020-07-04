// https://leetcode.com/problems/my-calendar-i/description/

// Time Complexity:-O(N^2).
// Space Complexity:-O(N).

// Approach:-
//     Brute Force Approach that we will check with each interval that is it overlaps with one or not.

class MyCalendar
{
private:
    vector<vector<int>> store;

public:
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        for (int i = 0; i < store.size(); i++)
            if (end > store[i][0] && start < store[i][1])
                return false;

        store.push_back({start, end});

        return true;
    }
};

// Time Complexity:-O(N*log(N)).
// Space Complexity:-O(N).

class MyCalendar
{
private:
    set<pair<int, int>> store;

public:
    MyCalendar()
    {
    }

    bool book(int s, int e)
    {
        auto next = store.lower_bound({s, e});

        if (next != store.end() && e > next->first)
            return false;

        if (next != store.begin() && s < (--next)->second)
            return false;

        store.insert({s, e});

        return true;
    }
};