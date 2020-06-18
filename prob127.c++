// // https://leetcode.com/problems/word-ladder/

// Approach:-   (Time Limit Exceeded)
//     In this what we a going to do is that we wiill initially store all the wordList elements in a set so that 
// the time for search become O(1). Now we will maintain a queue for BFS. In queue we will insert the elements which 
// can be fored by 1 change in current element. Now will select all elemets in the queue and check for individually 
// to all that what number can be formed by changing only one element an if found in the set than we will insert that 
// element to the queue and check for next combination.At any stage if the word will become equal to endWord than we 
// will return the steps we had taken else go forward. In last if queue becomes empty than it roresents that word can 
// not be formed hence we will return 0 in that case.

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> dict;
        for (auto x : wordList)
            dict.insert(x);

        if (dict.find(endWord) == dict.end())
            return 0;

        queue<string> todo;
        int ladder = 1;
        todo.push(beginWord);
        while (!todo.empty())
        {
            int n = todo.size();

            for (int i = 0; i < n; i++)
            {
                string word = todo.front();
                todo.pop();

                if (word == endWord)
                    return ladder;

                dict.erase(word);

                for (int j = 0; j < word.size(); j++)
                {
                    char c = word[j];
                    for (int k = 0; k < 26; k++)
                    {
                        word[j] = 'a' + k;
                        if (dict.find(word) != dict.end())
                            todo.push(word);
                    }

                    word[j] = c;
                }
            }

            ladder++;
        }

        return 0;
    }
};