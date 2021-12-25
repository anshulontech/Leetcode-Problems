// Link To Problem:-
// https://leetcode.com/problems/detect-squares/

// Solution:-

class DetectSquares
{
public:
    unordered_map<int, unordered_map<int, int>> map;
    DetectSquares()
    {
        // unordered_map<int,unordered_map<int,int>> map;
    }

    void add(vector<int> point)
    {
        map[point[0]][point[1]]++;
    }

    int count(vector<int> point)
    {
        int res = 0;

        for (auto y : map[point[0]])
        {
            int dist = point[1] - y.first;

            if (dist == 0)
                continue;

            int count1 = map[point[0]][point[1] - dist];
            int count2 = map[point[0] - dist][point[1]];
            int count3 = map[point[0] - dist][point[1] - dist];
            int count4 = map[point[0] + dist][point[1]];
            int count5 = map[point[0] + dist][point[1] - dist];
            res += count1 * count2 * count3 + count1 * count4 * count5;
        }

        return res;
    }
};