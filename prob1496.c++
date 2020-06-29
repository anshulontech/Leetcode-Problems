// https://leetcode.com/problems/path-crossing/description/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     We will initially make a direction map which will guide us to go where . Now we will use a pair of interger 
// which works as coordinate of the present point. Initially we are standing on the (0,0) point now we will start to 
// itterate the string and based on direction we will move as described , now we are using a hash map to store the 
// coordinates we visited , so on going to new coordinate we will check that is that coordinate already traversed 
// or not, if it will than we will return true else add that coordinate to the set and go for next direction , if in 
// the last we will reach the end of the direction string such that we not visited already visited coordinate than in 
// that situation we will return false.

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

public:
    bool isPathCrossing(string s)
    {
        unordered_map<char, pair<int, int>> store;

        store['N'] = {0, 1};
        store['S'] = {0, -1};
        store['E'] = {1, 0};
        store['W'] = {-1, 0};

        unordered_set<pair<int, int>, pair_hash> previous;

        pair<int, int> coordinates;
        coordinates.first = 0, coordinates.second = 0;

        previous.insert(coordinates);

        for (int i = 0; i < s.size(); i++)
        {
            coordinates.first += store[s[i]].first;
            coordinates.second += store[s[i]].second;

            if (previous.find(coordinates) != previous.end())
                return true;
            else
                previous.insert(coordinates);
        }

        return false;
    }
};