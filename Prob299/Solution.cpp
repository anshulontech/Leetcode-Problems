// Approach 1:-

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        unordered_map<char, int> store;
        int bulls = 0, cows = 0;

        for (int i = 0; i < secret.size(); i++)
        {
            if (secret[i] == guess[i])
                bulls++;
            else
                store[secret[i]]++;
        }

        for (int j = 0; j < secret.size(); j++)
            if (secret[j] != guess[j] && store[guess[j]] != 0)
            {
                cows++;
                store[guess[j]]--;
            }

        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};

// Approach 2:-

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        vector<int> store(10, 0);
        int bulls = 0, cows = 0;

        for (int i = 0; i < secret.size(); i++)
        {
            if (secret[i] == guess[i])
                bulls++;
            else
                store[secret[i] - '0']++;
        }

        for (int j = 0; j < secret.size(); j++)
            if (secret[j] != guess[j] && store[guess[j] - '0'] != 0)
            {
                cows++;
                store[guess[j] - '0']--;
            }

        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};