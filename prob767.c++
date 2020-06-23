// https://leetcode.com/problems/reorganize-string/

// Time Complexity:-O(N*log(n)).
// Space Complexity:-O(n).
    
// Approach:-
//     Initially we will store the count of each char in a vector and than than will sort it.Now if any count was 
// founf to be greater than (N+1)/2 than it represents that we will not make the sln from these but if no has this 
// than we can can , so now what we are going to do is that we will place 1st element at 1 index 2nd at 3 index like 
// elements follow the order S[3], S[0], S[4], S[1], S[5], S[2] and by organising this we can generate the result.

class Solution
{
public:
    string reorganizeString(string s)
    {
        int N = s.size();
        vector<int> counts;

        for (int i = 0; i < 26; i++)
            counts.push_back(i); // i is assigned because as we will sort them we will loose their identity and hence 
                                 // can generate by taking modulo with 100 as will taken each element count to be 100.

        for (int i = 0; i < s.size(); i++)
            counts[s[i] - 'a'] += 100;

        sort(counts.begin(), counts.end());

        string res(N, ' ');
        int t = 1;

        for (auto count : counts)
        {
            int val = count / 100;
            char ch = (char)('a' + (count % 100));
            if (val > (N + 1) / 2)
                return "";

            for (int i = 0; i < val; i++)
            {
                if (t >= N)
                    t = 0;
                res[t] = ch;
                t += 2;
            }
        }

        return res;
    }
};