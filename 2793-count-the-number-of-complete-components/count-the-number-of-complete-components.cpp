class Solution {
public:
    void dfs(vector<vector<int>>& adj, int node, vector<int>& vis, unordered_set<int>& component) {
        vis[node] = 1;
        component.insert(node);
        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                dfs(adj, neighbor, vis, component);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);

    
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int count = 0;

     
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                unordered_set<int> component;
                dfs(adj, i, vis, component);

               
                bool isComplete = true;
                int size = component.size();
                for (int node : component) {
                    if (adj[node].size() != size - 1) {
                        isComplete = false;
                        break;
                    }
                }

                if (isComplete) count++;
            }
        }

        return count;
    }
};
