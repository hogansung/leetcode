class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        node = vector<Trie*>(26, NULL);
        exist = false;
    }
    
    void insert(string& word, int t, const int len) {
        if (t == len) {
            exist = true;
            return;
        } else {
            int tar = word[t]-'a';
            if (node[tar] == NULL) {
                node[tar] = new Trie();
            }
            node[tar]->insert(word, t+1, len);
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        insert(word, 0, word.length());
    }
    
    bool search(string& word, int t, const int len) {
        if (t == len) {
            return exist;
        } else {
            int tar = word[t]-'a';
            if (node[tar] == NULL) {
                return false;
            } else {
                return node[tar]->search(word, t+1, len);
            }
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return search(word, 0, word.length());
    }
    
    bool startsWith(string& prefix, int t, const int len) {
        if (t == len) {
            return true;
        } else {
            int tar = prefix[t]-'a';
            if (node[tar] == NULL) {
                return false;
            } else {
                return node[tar]->startsWith(prefix, t+1, len);
            }
        }
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return startsWith(prefix, 0, prefix.length());
    }
    
    vector<Trie*> node;
    bool exist;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
