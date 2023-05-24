class Solution {
public:
    int find(int v) {
        if (pn[v] == v) {
            return v;
        } else {
            return pn[v] = find(pn[v]);
        }
    }
    
    bool validTree(int n, vector<pair<int, int>>& edges) {
        for (int i = 0; i < n; i++) {
            pn.push_back(i);
        }
        
        int cnt = 0;
        for (auto edge : edges) {
            int pa = find(edge.first);
            int pb = find(edge.second);
            if (pa != pb) {
                pn[pa] = pb;
                cnt += 1;
            }
        }
        return cnt == n-1 and edges.size() == n-1;
    }
    
    vector<int> pn;
};
