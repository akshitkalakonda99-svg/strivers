class Solution {
public:
    bool check(int minEdgeCost, int n, vector<vector<int>>& edges,
               vector<bool>& online, long long k) {

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indegree(n, 0);

        // Build filtered graph
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];

            if (cost < minEdgeCost)
                continue;

            if (u != 0 && u != n - 1 && !online[u])
                continue;

            if (v != 0 && v != n - 1 && !online[v])
                continue;

            adj[u].push_back({v, cost});
            indegree[v]++;
        }

        // Topological Sort (Kahn's Algorithm)
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (auto &it : adj[node]) {
                int next = it.first;
                indegree[next]--;

                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        const long long INF = 1e18;
        vector<long long> dist(n, INF);
        dist[0] = 0;

        // Shortest Path in DAG
        for (int node : topo) {

            if (dist[node] == INF)
                continue;

            for (auto &it : adj[node]) {
                int next = it.first;
                int cost = it.second;

                dist[next] = min(dist[next], dist[node] + cost);
            }
        }

        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        int n = online.size();

        int low = 0;
        int high = 0;

        for (auto &edge : edges)
            high = max(high, edge[2]);

        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (check(mid, n, edges, online, k)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};