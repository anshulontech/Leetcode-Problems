// Approach 1:-

class TrieNode
{
public:
    TrieNode *children[26];
    bool isWord;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;

        isWord = false;
    }

    void insert(string &word)
    {
        TrieNode *curr = this;

        for (auto c : word)
        {
            if (curr->children[c - 'a'] == nullptr)
                curr->children[c - 'a'] = new TrieNode();

            curr = curr->children[c - 'a'];
        }

        curr->isWord = true;
    }
};

class MagicDictionary
{
private:
    TrieNode *root = new TrieNode();

public:
    /** Initialize your data structure here. */
    MagicDictionary()
    {
    }

    void buildDict(vector<string> dictionary)
    {
        int n = dictionary.size();

        for (int i = 0; i < n; i++)
            root->insert(dictionary[i]);
    }

    bool search(string searchWord)
    {
        int n = searchWord.size();
        TrieNode *curr = root;

        for (int i = 0; i < n; i++)
        {
            char c = searchWord[i];
            bool res = false;
            for (int j = 0; j < 26; j++)
            {
                if (j == (c - 'a'))
                    continue;

                res = res || helper(searchWord, curr->children[j], i + 1);
                if (res)
                    return res;
            }

            if (curr->children[c - 'a'] == nullptr)
                return false;
            else
                curr = curr->children[c - 'a'];
        }

        return false;
    }

    bool helper(string &searchWord, TrieNode *curr, int index)
    {
        int n = searchWord.size();

        for (int i = index; i < n && curr; i++)
        {
            char c = searchWord[i];

            if (curr->children[c - 'a'] == nullptr)
                return false;
            else
                curr = curr->children[c - 'a'];
        }

        return curr && curr->isWord;
    }
};