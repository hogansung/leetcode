/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    void dfs(UndirectedGraphNode* node,
                             unordered_map<int,UndirectedGraphNode*>& um) {
        UndirectedGraphNode* ret = new UndirectedGraphNode(node->label);
        um[node->label] = ret;
        for (auto neighbor : node->neighbors) {
            if (um.find(neighbor->label) == um.end()) {
                dfs(neighbor, um);   
            }
            ret->neighbors.push_back(um[neighbor->label]);
        }
    }
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) {
            return NULL;
        } else {
            unordered_map<int,UndirectedGraphNode*> um;
            dfs(node, um);
            return um[node->label];
        }
    }
};
