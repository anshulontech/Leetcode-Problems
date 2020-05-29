// https://leetcode.com/problems/top-k-frequent-elements/

// Time Complexity:-O(N*log(N)).
// Space Compleity:-O(M+k) i.e, O(N). Where M is no of different numbers.
    
// Approaach:-
//     Initially we will store the count of each number in a map. Now we start tio traverse the map and insert first 
// k elements in a min heap . Now after making size of mn heap equal to k we will continue the search the for map. Now 
// if the count of map num is found to be greater than the top element that is the min among them than we can say the 
// new one can replace the top one hence we can remove it else if the top is greater than we will just continue our 
// traversing to map. At last we will just insert the heap elements in the vector and return that one.

class Solution
{
    typedef pair<int, int> pi;

public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int N = nums.size();
        unordered_map<int, int> store;

        for (int i = 0; i < N; i++)
            store[nums[i]]++;

        vector<int> res;

        priority_queue<pi, vector<pi>, greater<pi>> temp;

        unordered_map<int, int>::iterator itr;

        for (itr = store.begin(); itr != store.end() && temp.size() < k; itr++)
        {
            temp.push(make_pair(itr->second, itr->first));
        }

        for (; itr != store.end(); itr++)
            if (temp.top().first < itr->second)
                temp.pop(), temp.push(make_pair(itr->second, itr->first));

        while (!temp.empty())
        {
            res.push_back(temp.top().second);
            temp.pop();
        }

        return res;
    }
};