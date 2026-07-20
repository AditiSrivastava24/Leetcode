// Last updated: 7/20/2026, 8:22:25 PM
1class Solution {
2public:
3    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
4        int m = grid.size();
5        int n = grid[0].size();
6        int total = m * n;
7
8        k %= total;
9
10        vector<vector<int>> ans(m, vector<int>(n));
11
12        for (int i = 0; i < m; i++) {
13            for (int j = 0; j < n; j++) {
14                int idx = (i * n + j + k) % total;
15                int x = idx / n;
16                int y = idx % n;
17                ans[x][y] = grid[i][j];
18            }
19        }
20
21        return ans;
22    }
23};