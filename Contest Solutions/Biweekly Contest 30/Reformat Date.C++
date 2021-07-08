// Solution:-

class Solution
{
public:
    string reformatDate(string date)
    {
        string day = "", month = "", year = "";
        int n = date.size();

        year = date.substr(n - 4, 4);
        int i = 0;

        while (i < n && date[i] >= '0' && date[i] <= '9')
            i++;

        day = date.substr(0, i);
        if (day.size() == 1)
            day = '0' + day;

        while (i < n && date[i] != ' ')
            i++;
        i++;
        month = date.substr(i, 3);

        vector<string> temp = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

        for (int i = 0; i < 12; i++)
            if (temp[i] == month)
            {
                month = to_string(i + 1);
                break;
            }

        if (month.size() == 1)
            month = '0' + month;

        return year + "-" + month + "-" + day;
    }
};