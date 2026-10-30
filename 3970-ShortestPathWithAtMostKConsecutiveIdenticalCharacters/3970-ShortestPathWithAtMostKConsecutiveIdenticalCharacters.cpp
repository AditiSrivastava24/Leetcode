// Last updated: 10/30/2026, 4:52:17 PM
1#include <vector>
2#include <string>
3#include <queue>
4#include <tuple>
5
6using namespace std;
7
8class Solution {
9public:
10    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
11        // Step 1: Build the adjacency list for the graph
12        vector<vector<pair<int, int>>> adj(n);
13        for (const auto& edge : edges) {
14            int u = edge[0];
15            int v = edge[1];
16            int w = edge[2];
17            adj[u].push_back({v, w});
18        }
19
20        // Step 2: Initialize distance array with a 2D state: dist[node][consecutive_count]
21        // k consecutive identical characters means consecutive_count ranges from 1 to k.
22        const int INF = 1e9;
23        vector<vector<int>> dist(n, vector<int>(k + 1, INF));
24
25        // Min-heap priority queue storing tuples of {distance, node, consecutive_count}
26        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
27
28        // Base case: Node 0 has 1 consecutive character initially
29        dist[0][1] = 0;
30        pq.push({0, 0, 1});
31
32        while (!pq.empty()) {
33            auto [d, u, consecutive_count] = pq.top();
34            pq.pop();
35
36            // Destination reached: since it's Dijkstra, this is guaranteed to be the shortest path
37            if (u == n - 1) {
38                return d;
39            }
40
41            // If we found a shorter path to this state already, skip it
42            if (d > dist[u][consecutive_count]) {
43                continue;
44            }
45
46            // Traverse all adjacent nodes
47            for (const auto& [v, weight] : adj[u]) {
48                int next_count = (labels[v] == labels[u]) ? consecutive_count + 1 : 1;
49
50                // Check if the state is within constraints
51                if (next_count <= k) {
52                    int next_dist = d + weight;
53                    
54                    // Relaxation step
55                    if (next_dist < dist[v][next_count]) {
56                        dist[v][next_count] = next_dist;
57                        pq.push({next_dist, v, next_count});
58                    }
59                }
60            }
61        }
62
63        // Return -1 if node n - 1 is unreachable under the constraints
64        return -1;
65    }
66};
67