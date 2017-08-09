class Solution {
public:
    bool dfs(int t, vector<vector<int>>& edges,
             vector<bool>& vis, vector<bool>& inStack) {
        vis[t] = inStack[t] = true;
        
        bool hasCycle = false;
        for (auto nt : edges[t]) {
            if (vis[nt] == false) {
                hasCycle |= dfs(nt, edges, vis, inStack);
            } else if (inStack[nt] == true) {
                hasCycle |= true;
            }
        }
        
        inStack[t] = false;
        return hasCycle;
    }
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> edges(numCourses, vector<int>());
        for (auto p : prerequisites) {
            edges[p.second].push_back(p.first);   
        }
        
        vector<bool> inStack(numCourses, false);
        vector<bool> vis(numCourses, false);
        bool hasCycle = false;
        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == false) {
                hasCycle |= dfs(i, edges, vis, inStack);
            }
        }
        return hasCycle == false;
    }
};
