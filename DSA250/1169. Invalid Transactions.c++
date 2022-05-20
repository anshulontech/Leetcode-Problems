// Link To The Problem:-
//  https://leetcode.com/problems/invalid-transactions/

// Solution:-

class Solution
{
public:
    vector<string> invalidTransactions(vector<string> &transactions)
    {
        vector<string> res;

        unordered_map<string, vector<vector<string>>> map;

        unordered_set<string> visited;

        for (auto x : transactions)
        {
            int i = 0, idx = 0;
            string name = "";
            while (x[i] != ',')
                i++;

            name = x.substr(idx, i);
            i++;
            idx = i;

            while (x[i] != ',')
                i++;

            int time = stoi(x.substr(idx, i - idx));

            i++;
            idx = i;

            while (x[i] != ',')
                i++;

            int amount = stoi(x.substr(idx, i - idx));

            idx = i + 1;

            string city = x.substr(idx, x.size() - idx);

            bool failed = false;

            if (amount > 1000)
            {
                failed = true;
                res.push_back(x);
            }

            idx = 0;

            for (auto &temp : map[name])
            {

                int pTime = stoi(temp[0]), pAmount = stoi(temp[1]);
                string pCity = temp[2];

                if (pCity != city)
                {
                    if (abs(time - pTime) <= 60)
                    {

                        if (!failed)
                        {
                            failed = true;
                            res.push_back(x);
                        }

                        string helper = name + "," + temp[0] + "," + temp[1] + "," + pCity + "," + to_string(idx);

                        if (visited.find(helper) == visited.end())
                        {
                            int len = helper.size() - 1;
                            while (helper[len] != ',')
                                len--;
                            res.push_back(helper.substr(0, len));
                            visited.insert(helper);
                        }
                    }
                }

                idx++;
            }

            if (failed)
            {
                visited.insert(x + "," + to_string(idx));
            }
            map[name].push_back({to_string(time), to_string(amount), city});
        }

        return res;
    }
};