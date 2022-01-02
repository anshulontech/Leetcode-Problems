// Link To Problem:-
// https://leetcode.com/problems/partition-labels/

// METHOD 1:-

int searchfromend(string &S, int index, int end);

class Solutions
{
public:
    vector<int> partitionLabels(string S)
    {
        cout << S.size();
        vector<int> A;
        for (int i = 0; i < S.size(); i++)
        {
            int end = searchfromend(S, i, i);
            for (int j = i + 1; j < end; j++)
                end = searchfromend(S, j, end);

            A.push_back(end - i + 1);
            i = end;
        }

        return A;
    }
};

int searchfromend(string &S, int index, int end)
{
    int i = S.size() - 1;
    while (i > end && S[index] != S[i])
        i--;

    if (i > end)
        end = i;

    return end;
}

// METHOD 2:-

class Solution
{
public:
    vector<int> partitionLabels(string S)
    {
        vector<int> B;
        vector<pair<int, int>> A(26, {-1, -1});
        for (int i = 0; i < S.size(); i++)
        {
            if (A[S[i] - 97].first == -1)
                A[S[i] - 97].first = i;

            A[S[i] - 97].second = i;
        }
        sort(A.begin(), A.end());
        int j = 0;
        while (A[j].first == -1)
            j++;

        for (int i = j; i < A.size(); i++)
        {
            int max = A[i].second;
            int k = i + 1;
            for (; k < A.size(); k++)
            {
                if (A[k].first > max)
                    break;
                if (A[k].second > max)
                    max = A[k].second;
            }

            B.push_back(max + 1 - A[i].first);
            i = k - 1;
        }

        return B;
    }
};