class Solution {
public:
    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }
    
    int countComponents(int n, vector<pair<int, int>>& edges) {
        for (int i = 0; i < n; i++) {
            par.push_back(i);
        }
        
        int nc = n;
        for (auto edge : edges) {
            int pa = find(par[edge.first]);
            int pb = find(par[edge.second]);
            if (pa != pb) {
                nc -= 1;
                par[pa] = pb;
            }
        }
        return nc;
    }
    
    vector<int> par;
};
