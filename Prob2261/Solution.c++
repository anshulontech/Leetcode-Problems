// Link To The Problem:-
// https://leetcode.com/problems/k-divisible-elements-subarrays/

// Solution:-

class trie
{
public:
    unordered_map<int, trie *> child;
    bool isEnd;

    trie()
    {
        isEnd = false;
    }
};

class Solution
{
public:
    int countDistinct(vector<int> &nums, int k, int p)
    {
        int res = 0, n = nums.size();

        trie *root = new trie();

        for (int i = 0; i < n; i++)
        {
            int count = 0;
            trie *node = root;

            for (int j = i; j < n && count <= k; j++)
            {
                if (nums[j] % p == 0)
                    count++;

                if (count <= k)
                {
                    if (node->child.find(nums[j]) == node->child.end())
                    {
                        node->child[nums[j]] = new trie();
                    }

                    node = node->child[nums[j]];

                    if (node->isEnd == false)
                        res++;
                    node->isEnd = true;
                }
            }
        }

        return res;
    }
};