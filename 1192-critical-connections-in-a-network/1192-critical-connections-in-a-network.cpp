class Solution {
public:
    int time;

    vector<int> dt, low;

    void dfs(int u, int paru,
             vector<vector<int>>& adj,
             vector<vector<int>>& bridges) {

        dt[u] = low[u] = ++time;

        for (int i = 0; i < adj[u].size(); i++) {

            int v = adj[u][i];

            // Ignore the edge through which we came
            if (v == paru)
                continue;

            // v is not visited
            if (dt[v] == -1) {

                dfs(v, u, adj, bridges);

                low[u] = min(low[u], low[v]);

                // Bridge condition
                if (low[v] > dt[u]) {
                    bridges.push_back({u, v});
                }

            }
            // Back edge
            else {
                low[u] = min(low[u], dt[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(
        int n,
        vector<vector<int>>& connections) {

        // Adjacency list
        vector<vector<int>> adj(n);

        for (int i = 0; i < connections.size(); i++) {

            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        time = 0;

        // Initialize with -1
        dt.assign(n, -1);
        low.assign(n, -1);

        vector<vector<int>> bridges;

        // Graph may be disconnected
        for (int i = 0; i < n; i++) {

            if (dt[i] == -1) {
                dfs(i, -1, adj, bridges);
            }
        }

        return bridges;
    }
};
