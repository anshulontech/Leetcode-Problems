// https://leetcode.com/problems/replace-words/description/

// Time Complexity:-O(N+K).
// Space Copleixty:-O(K).
    
// Approach:-
//     In this initially we will store the words of dictionary in a set such that the complecity of searching a number 
// will become O(1). Now we start to traverse the sentense string and for each word we will check that is any successor 
// present in the dictionary than we will add that successor to the result and move for the next one. So by this we can 
// generate the result .

class Solution {
public:
    string replaceWords(vector<string>& dict, string s) {
        unordered_set<string> store;
        
        for(int i=0;i<dict.size();i++)
            store.insert(dict[i]);
        
        string res="";
        
        for(int i=0;i<s.size();i++) {
            int j=i;
            
            while(j<s.size() && s[j]!=' ')
                j++;
            
            int flag=0;
            
            for(int k=i;k<j;k++) {
                string temp=s.substr(i,k-i+1);
                if(store.find(temp)!=store.end()) {
                    flag=1;
                    res+=temp;
                    break;
                }
            }
            
            if(flag==0) {
                string temp=s.substr(i,j-i);
                res+=temp;
            }
            
            res+=" ";
            i=j;
        }
        
        res.erase(res.size()-1,1);
        
        return res;
    }
};

class TrieNode
{
public:
    vector<TrieNode *> children;
    string word = "";

    TrieNode() : children(26, NULL) {}
};

// Approach:- 
//     Using trie data structure.

class Solution
{
public:
    string replaceWords(vector<string> &dict, string s)
    {
        TrieNode *root = new TrieNode();

        for (int i = 0; i < dict.size(); i++)
        {
            TrieNode *temp = root;
            for (int j = 0; j < dict[i].size(); j++)
                if (temp->children[dict[i][j] - 'a'] != NULL)
                    temp = temp->children[dict[i][j] - 'a'];
                else
                {
                    TrieNode *temp2 = new TrieNode();
                    temp->children[dict[i][j] - 'a'] = temp2;
                    temp = temp2;
                }

            temp->word = dict[i];
        }

        string res = "";

        for (int i = 0; i < s.size(); i++)
        {

            int flag = 0;
            TrieNode *temp = root;
            int j = i;
            for (; j < s.size() && s[j] != ' '; j++)
                if (temp->children[s[j] - 'a'] != NULL)
                    if (temp->children[s[j] - 'a']->word != "")
                    {
                        flag = 1;
                        break;
                    }
                    else
                        temp = temp->children[s[j] - 'a'];
                else
                    break;

            if (flag == 0)
            {
                while (j < s.size() && s[j] != ' ')
                    j++;

                res += s.substr(i, j - i);
            }
            else
                res += temp->children[s[j] - 'a']->word;

            res += " ";

            while (i < s.size() && s[i] != ' ')
                i++;
        }

        res = res.erase(res.size() - 1, 1);

        return res;
    }
};