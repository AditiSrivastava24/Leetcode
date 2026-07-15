// Last updated: 7/15/2026, 6:36:49 PM
class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        auto can = [&](int minCost) {
            vector<vector<pair<int,int>>> adj(n);
            vector<int> indeg(n, 0);

            for (auto &e : edges) {
                int u = e[0], v = e[1], c = e[2];

                if (c < minCost) continue;
                if (!online[u] || !online[v]) continue;

                adj[u].push_back({v, c});
                indeg[v]++;
            }

            queue<int> q;
            for (int i = 0; i < n; i++) {
                if (indeg[i] == 0) q.push(i);
            }

            vector<int> topo;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                topo.push_back(node);

                for (auto &[nei, cost] : adj[node]) {
                    indeg[nei]--;
                    if (indeg[nei] == 0) q.push(nei);
                }
            }

            const long long INF = 4e18;
            vector<long long> dist(n, INF);
            dist[0] = 0;

            for (int u : topo) {
                if (dist[u] == INF) continue;

                for (auto &[v, cost] : adj[u]) {
                    dist[v] = min(dist[v], dist[u] + cost);
                }
            }

            return dist[n - 1] <= k;
        };

        int low = 0, high = 1e9;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (can(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};