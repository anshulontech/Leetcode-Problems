// Link To Probelm:-
// https://leetcode.com/problems/implement-trie-prefix-tree/

// Time Complexity:-O(N*l) Where N is no of operations and l represents avg lenght of string.
// Space Colexity:-O(N*26) Where N is number of strings.

// Approach:-
//     We wil use trie data structure. Learn from tushar roy and gaurav sen on you tube.

class TrieNode
{
public:
    TrieNode *next[26];
    bool is_word;

    TrieNode(bool b = false)
    {
        memset(next, 0, sizeof(next));
        is_word = b;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *p = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (p->next[word[i] - 'a'] == NULL)
                p->next[word[i] - 'a'] = new TrieNode();

            p = p->next[word[i] - 'a'];
        }

        p->is_word = true;
    }

    bool search(string word)
    {
        TrieNode *p = root;
        for (int i = 0; i < word.size() && p != NULL; i++)
            p = p->next[word[i] - 'a'];

        return p != NULL && p->is_word;
    }

    bool startsWith(string word)
    {
        TrieNode *p = root;
        int i;
        for (i = 0; i < word.size() && p != NULL; i++)
            p = p->next[word[i] - 'a'];

        return p != NULL;
    }
};