// Last updated: 10/29/2026, 7:30:27 PM
1#include <vector>
2#include <string>
3#include <sstream>
4
5using namespace std;
6
7class Solution {
8    int n;
9    vector<vector<int>> adj;
10    vector<int> parent, depth, heavy, head, pos;
11    int cur_pos;
12    
13    // Segment Tree for handling XOR bitmask queries
14    vector<int> tree;
15
16    int dfs_hl(int v, int p) {
17        int size = 1;
18        int max_c_size = 0;
19        parent[v] = p;
20        for (int c : adj[v]) {
21            if (c != p) {
22                depth[c] = depth[v] + 1;
23                int c_size = dfs_hl(c, v);
24                size += c_size;
25                if (c_size > max_c_size) {
26                    max_c_size = c_size;
27                    heavy[v] = c;
28                }
29            }
30        }
31        return size;
32    }
33
34    void decompose(int v, int h, const string& s) {
35        head[v] = h;
36        pos[v] = cur_pos++;
37        update_seg_tree(1, 0, n - 1, pos[v], 1 << (s[v] - 'a'));
38
39        if (heavy[v] != -1) {
40            decompose(heavy[v], h, s);
41        }
42        for (int c : adj[v]) {
43            if (c != parent[v] && c != heavy[v]) {
44                decompose(c, c, s);
45            }
46        }
47    }
48
49    void update_seg_tree(int node, int start, int end, int idx, int val) {
50        if (start == end) {
51            tree[node] = val;
52            return;
53        }
54        int mid = (start + end) / 2;
55        if (idx <= mid) update_seg_tree(2 * node, start, mid, idx, val);
56        else update_seg_tree(2 * node + 1, mid + 1, end, idx, val);
57        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
58    }
59
60    int query_seg_tree(int node, int start, int end, int l, int r) {
61        if (r < start || end < l) return 0;
62        if (l <= start && end <= r) return tree[node];
63        int mid = (start + end) / 2;
64        return query_seg_tree(2 * node, start, mid, l, r) ^ 
65               query_seg_tree(2 * node + 1, mid + 1, end, l, r);
66    }
67
68    int query_path(int a, int b) {
69        int res = 0;
70        for (; head[a] != head[b]; b = parent[head[b]]) {
71            if (depth[head[a]] > depth[head[b]]) swap(a, b);
72            res ^= query_seg_tree(1, 0, n - 1, pos[head[b]], pos[b]);
73        }
74        if (depth[a] > depth[b]) swap(a, b);
75        res ^= query_seg_tree(1, 0, n - 1, pos[a], pos[b]);
76        return res;
77    }
78
79public:
80    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
81        this->n = n;
82        adj.assign(n, vector<int>());
83        for (const auto& edge : edges) {
84            adj[edge[0]].push_back(edge[1]);
85            adj[edge[1]].push_back(edge[0]);
86        }
87
88        parent.assign(n, 0);
89        depth.assign(n, 0);
90        heavy.assign(n, -1);
91        head.assign(n, 0);
92        pos.assign(n, 0);
93        cur_pos = 0;
94        tree.assign(4 * n, 0);
95
96        dfs_hl(0, -1);
97        decompose(0, 0, s);
98
99        vector<bool> ans;
100        for (const string& q : queries) {
101            stringstream ss(q);
102            string type;
103            ss >> type;
104            if (type == "update") {
105                int u;
106                char c;
107                ss >> u >> c;
108                update_seg_tree(1, 0, n - 1, pos[u], 1 << (c - 'a'));
109            } else {
110                int u, v;
111                ss >> u >> v;
112                int path_mask = query_path(u, v);
113                // Check if the mask has at most 1 set bit
114                ans.push_back((path_mask & (path_mask - 1)) == 0);
115            }
116        }
117        return ans;
118    }
119};
120