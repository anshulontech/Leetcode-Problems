// Solution:-

class Solution
{
public:
    vector<string> alertNames(vector<string> &keyName, vector<string> &keyTime)
    {
        int n = keyName.size();
        unordered_map<string, vector<string>> store;
        vector<string> res;

        for (int i = 0; i < n; i++)
            store[keyName[i]].push_back(keyTime[i]);

        for (auto y : store)
        {
            auto &x = y.second;
            sort(x.begin(), x.end());

            for (int i = 0; i < x.size() - 2; i++)
                if (isDefaulter(x[i], x[i + 2]))
                {
                    res.push_back(y.first);
                    break;
                }
        }

        sort(res.begin(), res.end());

        return res;
    }

    bool isDefaulter(string &first, string &second)
    {
        int firstHour = stoi(first.substr(0, 2)), secondHour = stoi(second.substr(0, 2)), firstMinute = stoi(first.substr(3, 2)), secondMinute = stoi(second.substr(3, 2));

        if (firstHour == secondHour)
            return true;
        if (firstHour + 1 == secondHour)
            if (60 - firstMinute + secondMinute <= 60)
                return true;
            else
                return false;
        else
            return false;
    }
};