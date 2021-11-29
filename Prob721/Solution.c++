// Link To Problem:-
// https://leetcode.com/problems/accounts-merge/

// Solution:-

class Solution
{
public:
    unordered_set<string> visited;
    unordered_map<string, vector<string>> adjacent;

    void DFS(vector<string> &mergedAccount, string &email)
    {
        visited.insert(email);

        mergedAccount.push_back(email);

        for (string &neighbor : adjacent[email])
        {
            if (visited.find(neighbor) == visited.end())
            {
                DFS(mergedAccount, neighbor);
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>> &accountList)
    {
        int accountListSize = accountList.size();

        for (vector<string> &account : accountList)
        {
            int accountSize = account.size();

            string accountFirstEmail = account[1];
            for (int j = 2; j < accountSize; j++)
            {
                string email = account[j];
                adjacent[accountFirstEmail].push_back(email);
                adjacent[email].push_back(accountFirstEmail);
            }
        }

        vector<vector<string>> mergedAccounts;
        for (vector<string> &account : accountList)
        {
            string accountName = account[0];
            string accountFirstEmail = account[1];

            if (visited.find(accountFirstEmail) == visited.end())
            {
                vector<string> mergedAccount;

                mergedAccount.push_back(accountName);
                DFS(mergedAccount, accountFirstEmail);

                sort(mergedAccount.begin() + 1, mergedAccount.end());
                mergedAccounts.push_back(mergedAccount);
            }
        }

        return mergedAccounts;
    }
};