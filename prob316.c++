// https://leetcode.com/problems/remove-duplicate-letters/description/

// Time Complexity:-O(N).
// Space Complexity:-O(N).

class Solution {
public:
    string removeDuplicateLetters(string s)
    {
        vector<int> count(26);           // To store the count of each character.
        vector<bool> visited(26, false); // To check weateher the character is already in answer or not.

        for (int i = 0; i < s.size(); i++) // storing count of each character.
            count[s[i] - 'a']++;

        stack<char> store; // Stack to store result.

        for (auto c : s)
        {                     // Traversing string.
            count[c - 'a']--; // Decreasing number fo characters to visit in the string.

            if (visited[c - 'a']) // If Number is already in stack that means it is in answer and there is no
                                  // need to include it again.
                continue;

            // Now we will remove all the letters which are greater than current and present in stack and have
            // there count after this number later in the string so that they can form lexicographical order

            while (!store.empty() && store.top() > c && count[store.top() - 'a'] > 0)
            {
                visited[store.top() - 'a'] = false;
                store.pop();
            }

            store.push(c); // add current element to stack and mark it as visited.
            visited[c - 'a'] = true;
        }

        string res = "";

        while (!store.empty())
        { // Building result from stack. Answer is in reverse order hence we need to reverse it later.
            res += store.top();
            store.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};