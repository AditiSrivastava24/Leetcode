// Last updated: 7/25/2026, 4:13:21 PM
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;

        k %= total;

        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int idx = (i * n + j + k) % total;
                int x = idx / n;
                int y = idx % n;
                ans[x][y] = grid[i][j];
            }
        }

        return ans;
    }
};