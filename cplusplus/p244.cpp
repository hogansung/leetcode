class WordDistance {
public:
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1,T2> &p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);

            // Mainly for demonstration purposes, i.e. works but is overly simple
            // In the real world, use sth. like boost.hash_combine
            return h1 ^ h2;  
        }
    };
    
    pair<string,string> createStringPair(string& a, string& b) {
        int cmp = strcmp(a.c_str(), b.c_str());
        if (cmp < 0) {
            return make_pair(a, b);
        } else {
            return make_pair(b, a);
        }
    }
    
    WordDistance(vector<string> words) {
        rcd = unordered_map<pair<string,string>,int,pair_hash>();
        um = unordered_map<string, vector<int>>();
        
        int n = words.size();
        for (int i = 0; i < n; i++) {
            um[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int> vct1 = um[word1];
        vector<int> vct2 = um[word2];
        int n1 = vct1.size();
        int n2 = vct2.size();
        int f1 = 0;
        int f2 = 0;
        int mmin = INT_MAX;
        while (f1 < n1 and f2 < n2) {
            mmin = min(mmin, abs(vct2[f2] - vct1[f1]));
            if (vct1[f1] < vct2[f2]) {
                f1 += 1;
            } else {
                f2 += 1;
            }
        }
        
        pair<string,string> ps = createStringPair(word1, word2);
        return rcd[ps] = mmin;
    }
    
    unordered_map<string, vector<int>> um;
    unordered_map<pair<string,string>,int,pair_hash> rcd;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
