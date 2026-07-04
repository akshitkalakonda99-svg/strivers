class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    vector<int> vis;
    int ans = INT_MAX;

    void dfs(int node) {
        vis[node] = 1;

        for (auto &it : adj[node]) {
            int neigh = it.first;
            int wt = it.second;

            ans = min(ans, wt);

            if (!vis[neigh]) {
                dfs(neigh);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {

        adj.resize(n + 1);
        vis.resize(n + 1, 0);

        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];
            int wt = road[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        dfs(1);

        return ans;
    }
};