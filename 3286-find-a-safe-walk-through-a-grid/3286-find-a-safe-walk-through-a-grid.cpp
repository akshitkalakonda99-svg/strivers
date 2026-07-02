class Solution
{
public:
    bool findSafeWalk(vector<vector<int>> &grid, int health)
    {
        int m = grid.size();
        int n = grid[0].size();
        int startHealth = health - grid[0][0];
        if (startHealth <= 0)
            return false;
        vector<vector<int>> best(m, vector<int>(n, -1));

        priority_queue <vector<int>> pq;
        pq.push({startHealth, 0, 0});

        best[0][0] = startHealth;
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            int remHealth = curr[0];
            int r = curr[1];
            int c = curr[2];
            if (r == m - 1 && c == n - 1)
                return true;
            if (remHealth < best[r][c])
                continue;

            for (auto &d : dir)
            {
                int nr = r + d.first;
                int nc = c + d.second;
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                {
                    continue;
                }
                int newHealth = remHealth - grid[nr][nc];
                if (newHealth <= 0)
                    continue;
                if (newHealth > best[nr][nc])
                {
                    best[nr][nc] = newHealth;
                    pq.push({newHealth, nr, nc});
                }
            }
        }
        return false;
    }
};