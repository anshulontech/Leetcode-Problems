// https://leetcode.com/problems/add-and-search-word-data-structure-design/

// Time Complexity:-O(N).
// Space Complexity:-O(N*26).  Where N is total number of alphaebats in all the string including same.
    
// Approach:-
//     We will use a trie data stucture to store and search the result int that data structure. All things are same 
// as we are du=oing in trie data structure but the difference is that on encounter with '.' we will check for all 
// the combinations which can be formed from these. 

class TrieNode
{
public:
    bool word;
    TrieNode *children[26];
    TrieNode()
    {
        word = false;
        memset(children, NULL, sizeof(children));
    }
};

class WordDictionary
{
private:
    TrieNode *root = new TrieNode();

public:
    WordDictionary()
    {
    }

    void addWord(string word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->children[word[i] - 'a'])
                node->children[word[i] - 'a'] = new TrieNode();

            node = node->children[word[i] - 'a'];
        }

        node->word = true;
    }

    bool search(string word)
    {
        TrieNode *node = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == '.')
                return helper(word, node, i);
            else if (node->children[word[i] - 'a'] != NULL)
                node = node->children[word[i] - 'a'];
            else
                return false;
        }

        return node->word;
    }

    bool helper(string word, TrieNode *node, int index)
    {
        bool res = false;

        for (int i = 0; i < 26 && !res; i++)
            if (node->children[i] != NULL)
                res = res || serach_forward(word, node->children[i], index + 1);

        return res;
    }

    bool serach_forward(string word, TrieNode *node, int index)
    {
        for (int i = index; i < word.size(); i++)
            if (word[i] == '.')
                return helper(word, node, i);
            else if (node->children[word[i] - 'a'] != NULL)
                node = node->children[word[i] - 'a'];
            else
                return false;

        return node->word;
    }
};