// Approach 1:-

class TrieNode {
    TrieNode* children[26];
    bool word;
    public:    
    
    TrieNode() {
        word=false;
        for(int i=0;i<26;i++)
            children[i]=nullptr;
    }
    
    void insert(string& s) {
        TrieNode* temp=this;
        
        for(int i=s.size()-1;i>=0;i--) {
            if(temp->children[s[i]-'a']==nullptr)
                temp->children[s[i]-'a']=new TrieNode();
            
            temp=temp->children[s[i]-'a'];
        }
        
        temp->word=true;
        
        return ;
    }
    
    bool search(vector<char>& prev) {
        TrieNode* temp=this;
        
        for(int i=prev.size()-1;i>=0 && temp;i--) {
            int n=prev[i]-'a';
            
            if(temp->children[n]==nullptr)
                return false;
            
            temp=temp->children[n];
            
            if(temp->word)
                return true;
        }
        
        return false;
    }
};


class StreamChecker {
public:
    vector<char> queryChar;
    TrieNode root;
    StreamChecker(vector<string>& words) {
        for(int i=0;i<words.size();i++)
            root.insert(words[i]);
    }
    
    bool query(char letter) {
        queryChar.push_back(letter);
        return root.search(queryChar);
    }
};

