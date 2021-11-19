// Link To Problem:-
// https://leetcode.com/problems/walking-robot-simulation-ii/

// Solution:-

class Robot
{
private:
    int x = 0, y = 0;
    int w, h, peri;

    vector<bool> dir;

public:
    Robot(int width, int height)
    {
        w = width - 1;
        h = height - 1;
        for (int i = 0; i < 4; i++)
            dir.push_back(false);
        dir[0] = true;
        peri = 2 * width + 2 * height - 4;
    }

    void move(int num)
    {
        while (num)
        {
            int count = 0;

            if (dir[0] == true)
            {
                count = w - x;
                count = min(count, num);
                num -= count;
                x += count;
                if (num)
                {
                    dir[0] = false;
                    dir[3] = true;
                }
            }
            else if (dir[1] == true)
            {
                count = y;
                count = min(num, count);
                num -= count;
                y -= count;
                if (num)
                {
                    dir[1] = false;
                    dir[0] = true;
                }
            }
            else if (dir[2] == true)
            {
                count = x;
                count = min(num, count);
                num -= count;
                x -= count;
                if (num)
                {
                    dir[2] = false;
                    dir[1] = true;
                }
            }
            else
            {
                count = h - y;
                count = min(count, num);
                num -= count;
                y += count;
                if (num)
                {
                    dir[3] = false;
                    dir[2] = true;
                }
            }
            int temp = num / peri;

            if (temp > 1)
                num -= (temp - 1) * peri;
        }

        return;
    }

    vector<int> getPos()
    {
        return {x, y};
    }

    string getDir()
    {
        if (dir[0])
            return "East";
        if (dir[1])
            return "South";
        if (dir[2])
            return "West";
        return "North";
    }
};

/*


*/