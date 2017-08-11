class Solution {
public:
    bool dfs(int t, vector<vector<int>>& edges,
             vector<bool>& inStack, vector<bool>& vis, vector<int>& order) {
        inStack[t] = vis[t] = true;
        
        bool hasCycle = false;
        for (auto nt : edges[t]) {
            if (vis[nt] == false) {
                hasCycle |= dfs(nt, edges, inStack, vis, order);
            } else if (inStack[nt] == true) {
                hasCycle |= true;
            }
        }
        
        inStack[t] = false;
        order.push_back(t);
        return hasCycle;
    }
    
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> edges(numCourses, vector<int>());
        for (auto pv : prerequisites) {
            edges[pv.first].push_back(pv.second);
        }
        
        vector<bool> inStack(numCourses, false);
        vector<bool> vis(numCourses, false);
        vector<int> order;
        bool hasCycle = false;
        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == false) {
                hasCycle |= dfs(i, edges, inStack, vis, order);
            }
        }
        
        if (hasCycle == true) {
            return vector<int>();
        } else {
            return order;
        }
    }
};
