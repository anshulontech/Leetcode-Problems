// Link To The Problem:-
// https://leetcode.com/problems/destroying-asteroids/

// Solution:-

class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int> &asteroids)
    {
        sort(asteroids.begin(), asteroids.end());

        long long currentMass = mass;

        for (auto x : asteroids)
            if (currentMass < x)
                return false;
            else
                currentMass += x;

        return true;
    }
};