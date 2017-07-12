class Solution {
public:
    bool check(string& s, string& w) {
        int len = s.length();
        int cnt = 0;
        for (int i = 0; i < len and cnt <= 1; i++) {
            if (s[i] != w[i]) {
                cnt += 1;
            }
        }
        return cnt <= 1;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_map<int,vector<int>> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (check(wordList[i], wordList[j]) == true) {
                    edges[i].emplace_back(j);
                    edges[j].emplace_back(i);
                }
            }
            if (check(wordList[i], beginWord) == true) {
                edges[i].emplace_back(n);
                edges[n].emplace_back(i);
            }
        }
        
        queue<int> qs;
        unordered_map<int,int> dis;
        qs.push(n);
        dis[n] = 1;
        
        while (qs.size()) {
            auto idx = qs.front(); qs.pop();
            for (auto nn : edges[idx]) {
                if (dis.find(nn) == dis.end()) {
                    if (wordList[nn] == endWord) {
                        return dis[idx] + 1;
                    }
                    qs.emplace(nn);
                    dis[nn] = dis[idx] + 1;
                }
            }
        }
        return 0;
    }
};
