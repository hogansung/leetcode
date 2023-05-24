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
    
    bool search(string& word, int t, const int len) {
        if (t == len) {
            return exist;
        } else if (word[t] == '.') {
            bool suc = false;
            for (int tar = 0; tar < 26; tar++) {
                if (node[tar] == NULL) {
                    suc |= false;
                } else {
                    suc |= node[tar]->search(word, t+1, len);
                }
            }
            return suc;
        } else {
            int tar = word[t]-'a';
            if (node[tar] == NULL) {
                return false;
            } else {
                return node[tar]->search(word, t+1, len);
            }
        }
    }
    
    vector<Trie*> node;
    bool exist;
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        root.insert(word, 0, word.length());
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return root.search(word, 0, word.length());
    }
    
    Trie root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
