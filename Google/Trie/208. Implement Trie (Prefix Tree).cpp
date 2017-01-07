class TrieNode {
public:
    bool isWord;
    vector<TrieNode*> nodes;
    TrieNode() {
        nodes = vector<TrieNode*>(26);
        for(int i=0;i<26;i++)
             nodes[i]=NULL;
        isWord=false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* temp = root;
        for(int i=0;i<word.length();i++)
        {
            if(temp->nodes[word[i]-'a']!=NULL)
                temp=temp->nodes[word[i]-'a'];
            else
            {
                TrieNode* new_node = new TrieNode();
                temp->nodes[word[i]-'a'] = new_node;
                temp=temp->nodes[word[i]-'a'];
            }
        }
        temp->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* temp = root;
        for(int i=0;i<word.length();i++)
        {
            if(temp->nodes[word[i]-'a']==NULL)
                return false;
            else
                temp=temp->nodes[word[i]-'a'];
        }
        if(temp->isWord)
            return true;
        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(int i=0;i<prefix.length();i++)
        {
            if(temp->nodes[prefix[i]-'a']==NULL)
                return false;
            else
                temp=temp->nodes[prefix[i]-'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
