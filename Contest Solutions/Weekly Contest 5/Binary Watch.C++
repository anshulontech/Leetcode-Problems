// Solution:-

class Solution
{
private:
    vector<string> res;
    unordered_set<string> store;

public:
    vector<string> readBinaryWatch(int num)
    {
        vector<bool> hours(4, false), minutes(6, false);

        int hour = 0, minute = 0;

        backtrack(num, hours, minutes, hour, minute);

        sort(res.begin(), res.end());

        return res;
    }

private:
    void backtrack(int &num, vector<bool> &hours, vector<bool> &minutes, int &hour, int &minute)
    {
        if (hour > 11 || minute > 59)
            return;

        if (num == 0)
        {
            string temp = to_string(hour) + ":" + (minute > 9 ? to_string(minute) : ("0" + to_string(minute)));
            if (store.find(temp) == store.end())
            {
                res.push_back(temp);
                store.insert(temp);
            }
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            if (hours[i] == true)
                continue;

            hours[i] = true;
            num--;
            hour += pow(2, i);
            backtrack(num, hours, minutes, hour, minute);
            hour -= pow(2, i);
            num++;
            hours[i] = false;
        }

        for (int i = 0; i < 6; i++)
        {
            if (minutes[i] == true)
                continue;

            minutes[i] = true;
            num--;
            minute += pow(2, i);
            backtrack(num, hours, minutes, hour, minute);
            minute -= pow(2, i);
            num++;
            minutes[i] = false;
        }
    }
};