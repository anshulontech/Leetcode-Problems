// Approach 1:-

class Solution
{
public:
    bool isRobotBounded(string instructions)
    {
        vector<int> dire(4, 0);
        int idx = 0;
        int dist = 0;

        for (auto c : instructions)
            if (c == 'G')
            {
                dire[idx]++;
                dist++;
            }
            else if (c == 'L')
            {
                idx--;
                idx += 4;
                idx %= 4;
            }
            else
            {
                idx++;
                idx %= 4;
            }

        return dist == 0 || idx != 0 || (dire[0] == dire[2] && dire[0] != 0);
    }
};