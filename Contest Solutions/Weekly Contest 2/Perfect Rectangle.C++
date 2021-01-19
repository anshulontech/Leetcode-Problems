// Solution 01:-

class Solution
{
public:
    bool isRectangleCover(vector<vector<int>> &rectangles)
    {
        int totalArea = 0;

        int xMin = INT_MAX, yMin = INT_MAX, xMax = INT_MIN, yMax = INT_MIN;

        unordered_map<string, int> store;

        for (auto x : rectangles)
        {
            totalArea += ((x[2] - x[0]) * (x[3] - x[1]));

            xMin = min(xMin, x[0]);
            yMin = min(yMin, x[1]);
            xMax = max(xMax, x[2]);
            yMax = max(yMax, x[3]);

            string temp = to_string(x[0]) + "_" + to_string(x[1]);
            store[temp]++;
            temp = to_string(x[0]) + "_" + to_string(x[3]);
            store[temp]++;
            temp = to_string(x[2]) + "_" + to_string(x[1]);
            store[temp]++;
            temp = to_string(x[2]) + "_" + to_string(x[3]);
            store[temp]++;
        }

        int count = 0;

        for (auto x : store)
            if (x.second == 1)
                count++;
            else if (x.second == 3) // If this happens than it represents that on a particular point 3 boxes are present not 4 and hence it will not form a rectangel.
                return false;

        int finalArea = (xMax - xMin) * (yMax - yMin); // To check that no boxes overlap if everything is fine.

        return (totalArea == finalArea) && (count == 4) && (store[to_string(xMin) + "_" + to_string(yMin)] == 1) && (store[to_string(xMin) + "_" + to_string(yMax)] == 1) && (store[to_string(xMax) + "_" + to_string(yMin)] == 1) && (store[to_string(xMax) + "_" + to_string(yMax)] == 1);
        // Map check is to confirm that all the corner points occur single time in the rectangle.
    }
};

// Solution 02:-

class Solution
{
public:
    bool isRectangleCover(vector<vector<int>> &rectangles)
    {
        int totalArea = 0;

        int xMin = INT_MAX, yMin = INT_MAX, xMax = INT_MIN, yMax = INT_MIN;

        unordered_set<string> store;

        for (auto x : rectangles)
        {
            totalArea += ((x[2] - x[0]) * (x[3] - x[1]));

            xMin = min(xMin, x[0]);
            yMin = min(yMin, x[1]);
            xMax = max(xMax, x[2]);
            yMax = max(yMax, x[3]);

            string s1 = to_string(x[0]) + "_" + to_string(x[1]);

            if (store.count(s1))
                store.erase(s1);
            else
                store.insert(s1);
            string s2 = to_string(x[0]) + "_" + to_string(x[3]);

            if (store.count(s2))
                store.erase(s2);
            else
                store.insert(s2);

            string s3 = to_string(x[2]) + "_" + to_string(x[1]);

            if (store.count(s3))
                store.erase(s3);
            else
                store.insert(s3);

            string s4 = to_string(x[2]) + "_" + to_string(x[3]);

            if (store.count(s4))
                store.erase(s4);
            else
                store.insert(s4);
        }

        string s1 = to_string(xMin) + "_" + to_string(yMin);
        string s2 = to_string(xMin) + "_" + to_string(yMax);
        string s3 = to_string(xMax) + "_" + to_string(yMin);
        string s4 = to_string(xMax) + "_" + to_string(yMax);

        if (!store.count(s1) || !store.count(s2) || !store.count(s3) || !store.count(s4) || store.size() != 4)
            return false;

        int finalArea = (xMax - xMin) * (yMax - yMin);

        return (totalArea == finalArea);
    }
};