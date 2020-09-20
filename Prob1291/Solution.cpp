// Approach 1:-

class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        string digits = "123456789";

        vector<int> res;

        int min_len = to_string(low).size();
        int max_len = to_string(high).size();

        for (int i = min_len; i <= max_len; i++)
            for (int j = 0; j < 10 - i; j++)
            {
                int num = stoi(digits.substr(j, i));
                if (num >= low && num <= high)
                    res.push_back(num);
            }

        return res;
    }
};