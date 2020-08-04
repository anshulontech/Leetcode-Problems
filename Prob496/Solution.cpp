// Approach 1:-

int find(vector<int>, int);

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> A;
        for (int i = 0; i < nums1.size(); i++)
        {
            int max = nums1[i];
            int index = find(nums2, max);
            for (int j = index + 1; j < nums2.size(); j++)
                if (nums2[j] > max)
                {
                    max = nums2[j];
                    break;
                }

            if (max == nums1[i])
                A.push_back(-1);
            else
                A.push_back(max);
        }

        return A;
    }
};

int find(vector<int> A, int value)
{
    for (int i = 0; i < A.size(); i++)
        if (A[i] == value)
            return i;

    return -1;
}

// Approach 2:-

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> store;
        stack<int> container;

        for (int i = 0; i < nums2.size(); i++)
        {
            while (!container.empty() && container.top() < nums2[i])
            {
                store.insert(make_pair(container.top(), nums2[i]));
                container.pop();
            }

            container.push(nums2[i]);
        }

        vector<int> res;

        for (int i = 0; i < nums1.size(); i++)
            if (store.find(nums1[i]) != store.end())
                res.push_back(store[nums1[i]]);
            else
                res.push_back(-1);

        return res;
    }
};